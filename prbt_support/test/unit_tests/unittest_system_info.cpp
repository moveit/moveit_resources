/*
 * Copyright (c) 2019 Pilz GmbH & Co. KG
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <string>
#include <vector>
#include <thread>
#include <atomic>
#include <memory>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <ros/ros.h>
#include <canopen_chain_node/GetObject.h>
#include <sensor_msgs/JointState.h>

#include <pilz_utils/wait_for_message.h>
#include <pilz_utils/wait_for_service.h>
#include <pilz_testutils/async_test.h>
#include <prbt_support/system_info.h>
#include <prbt_support/system_info_exception.h>

namespace system_info_tests
{
using canopen_chain_node::GetObject;
using namespace prbt_support;
using namespace testing;

static const std::string GET_OBJECT_TOPIC_NAME{ "get_object" };
static const std::string JOINT_STATES_TOPIC_NAME{ "joint_states" };
static constexpr unsigned int JOINT_STATES_TOPIC_QUEUE_SIZE{ 1 };

/**
 * @brief Collection of tests checking the functionality of the SystemInfo
 * class.
 *
 */
class SystemInfoTests : public testing::Test, public testing::AsyncTest
{
public:
  void SetUp() override;
  void TearDown() override;

  void publishJointState();

protected:
  MOCK_METHOD2(executeGetObject, bool(GetObject::Request&, GetObject::Response&));

  void advertiseGetObjectService();

protected:
  // Needed so that service callback are proecessed. Otherwise test in which
  // service are calls will hang.
  ros::AsyncSpinner spinner_{ 2 };

  const std::vector<std::string> joint_names_{ "joint1", "joint2" };
  ros::ServiceServer get_obj_service_;
  std::thread publisher_thread_;
  std::atomic_bool terminate_{ false };
};

void SystemInfoTests::advertiseGetObjectService()
{
  ros::NodeHandle driver_nh{ "/prbt/driver/" };
  get_obj_service_ = driver_nh.advertiseService(GET_OBJECT_TOPIC_NAME, &SystemInfoTests::executeGetObject, this);
}

void SystemInfoTests::SetUp()
{
  spinner_.start();

  // Set joint names on parameter server
  ros::NodeHandle driver_nh{ "/prbt/driver/" };
  for (unsigned int i = 0; i < joint_names_.size(); ++i)
  {
    driver_nh.setParam("nodes/" + joint_names_.at(i) + "/id", static_cast<int>(i));
  }

  publisher_thread_ = std::thread(&SystemInfoTests::publishJointState, this);
  advertiseGetObjectService();
}

void SystemInfoTests::TearDown()
{
  if (publisher_thread_.joinable())
  {
    terminate_ = true;
    publisher_thread_.join();
  }
}

void SystemInfoTests::publishJointState()
{
  ros::NodeHandle global_nh{ "/" };
  ros::Publisher joint_state_pub =
      global_nh.advertise<sensor_msgs::JointState>(JOINT_STATES_TOPIC_NAME, JOINT_STATES_TOPIC_QUEUE_SIZE);

  while (!terminate_ && ros::ok())
  {
    joint_state_pub.publish(sensor_msgs::JointState());
    ros::Duration(0.5).sleep();
  }
}

/**
 * @brief Tests that exception stores and returns correct error message.
 */
TEST_F(SystemInfoTests, TestExceptions)
{
  const std::string exp_msg{ "Test-Msg" };
  std::shared_ptr<SystemInfoException> ex{ new SystemInfoException(exp_msg) };
  EXPECT_TRUE(std::string(ex->what()) == exp_msg);
}

/**
 * @brief Checks that exception is thrown if param "/prbt/driver/nodes" can
 * not be found on parameter server.
 */
TEST_F(SystemInfoTests, testNodeNamesMissing)
{
  ros::NodeHandle nh{ "~" };
  nh.deleteParam("/prbt/driver/nodes");
  EXPECT_THROW(SystemInfo{ nh }, SystemInfoException);
}

/**
 * @brief Tests that constructor waits until CAN is up and running by
 * waiting for the "/joint_states" topic.
 */
TEST_F(SystemInfoTests, testCANUpAndRunning)
{
  // Make sure that no JointStates are published
  terminate_ = true;
  publisher_thread_.join();

  // Variable stating if the constructor is finished or not.
  std::atomic_bool ctor_called{ false };
  // Start thread which allows us to asynchronously call the constructor
  std::thread async_ctor_call_thread = std::thread([this, &ctor_called]() {
    ros::NodeHandle nh{ "~" };
    SystemInfo info(nh);
    ctor_called = true;
    this->triggerClearEvent("ctor_called");
  });

  // Wait a while and then check if constructor is still waiting for the topic.
  ros::Duration(5.0 * pilz_utils::DEFAULT_RETRY_TIMEOUT).sleep();
  ASSERT_FALSE(ctor_called) << "Ctor already finished although \"/joint_states\" topic not published yet";

  // Activate publishing of "/joint_states"
  terminate_ = false;
  publisher_thread_ = std::thread(&SystemInfoTests::publishJointState, this);
  pilz_utils::waitForMessage<sensor_msgs::JointState>("/joint_states");
  // Wait till constructor is finished
  BARRIER("ctor_called");

  if (async_ctor_call_thread.joinable())
  {
    async_ctor_call_thread.join();
  }
}

/**
 * @brief Tests that constructor waits until ros_canopen service "get_object"
 * is advertised.
 */
TEST_F(SystemInfoTests, testCANServiceUpAndRunning)
{
  // Make sure that no ros_canopen service "get_object" is advertised.
  get_obj_service_.shutdown();

  // Variable stating if the constructor is finished or not.
  std::atomic_bool ctor_called{ false };
  // Start thread which allows us to asynchronously call the constructor
  std::thread async_ctor_call_thread = std::thread([this, &ctor_called]() {
    ros::NodeHandle nh{ "~" };
    SystemInfo info(nh);
    ctor_called = true;
    this->triggerClearEvent("ctor_called");
  });

  // Wait a while and then check if constructor is still waiting for the topic.
  ros::Duration(5.0 * pilz_utils::DEFAULT_RETRY_TIMEOUT).sleep();
  ASSERT_FALSE(ctor_called) << "Ctor already finished although \"get_object\" service not advertised yet";

  advertiseGetObjectService();
  pilz_utils::waitForService("/prbt/driver/get_object");
  // Wait till constructor is finished
  BARRIER("ctor_called");

  if (async_ctor_call_thread.joinable())
  {
    async_ctor_call_thread.join();
  }
}

/**
 * @brief Tests that exception is thrown in case the service returns
 * as response "false".
 */
TEST_F(SystemInfoTests, testServiceResponseFalse)
{
  EXPECT_CALL(*this, executeGetObject(_, _))
      .Times(1)
      .WillRepeatedly(testing::Invoke([](GetObject::Request&, GetObject::Response& res) {
        res.success = false;
        return true;
      }));

  ros::NodeHandle nh{ "~" };
  SystemInfo info{ nh };
  EXPECT_THROW(info.getFirmwareVersions(), SystemInfoException);
}

/**
 * @brief Tests that exception is thrown in case the service returns "false".
 */
TEST_F(SystemInfoTests, testServiceFail)
{
  EXPECT_CALL(*this, executeGetObject(_, _))
      .Times(1)
      .WillRepeatedly(testing::Invoke([](GetObject::Request&, GetObject::Response&) { return false; }));

  ros::NodeHandle nh{ "~" };
  SystemInfo info{ nh };
  EXPECT_THROW(info.getFirmwareVersions(), SystemInfoException);
}

/**
 * @brief Tests that SystemInfo class returns correct firmware versions for
 * each joint, given that everything needed by SystemInfo class works correctly.
 */
TEST_F(SystemInfoTests, testGetFirmwareVersions)
{
  ASSERT_EQ(2u, joint_names_.size()) << "Number of joints in test set-up have changed => Change expected version "
                                        "container in test accordingly.";

  const FirmwareCont exp_versions{ { joint_names_.at(0), "100 Build:11158 Date:2018-06-07 16:49:55" },
                                   { joint_names_.at(1), "101 Build:11158 Date:2018-06-07 16:49:55" } };

  EXPECT_CALL(*this, executeGetObject(_, _))
      .Times(2)
      .WillRepeatedly(testing::Invoke([exp_versions](GetObject::Request& req, GetObject::Response& res) {
        res.value = exp_versions.at(req.node);
        res.success = true;
        return true;
      }));

  // Check that returned versions from service are correct
  ros::NodeHandle nh{ "~" };
  SystemInfo info{ nh };
  FirmwareCont actual_version_cont{ info.getFirmwareVersions() };
  for (const auto& joint : joint_names_)
  {
    EXPECT_TRUE(actual_version_cont.find(joint) != actual_version_cont.cend()) << "No version for joint found";
    EXPECT_EQ(exp_versions.at(joint), actual_version_cont.at(joint)) << "Expected and actual firmware version do not "
                                                                        "match";
  }
}

/**
 * @brief Tests that the firmware string is trimmed to 40chars
 * See https://github.com/PilzDE/pilz_robots/issues/299
 */
TEST_F(SystemInfoTests, testGetFirmwareVersionsResizeTo40Chars)
{
  ASSERT_EQ(2u, joint_names_.size()) << "Number of joints in test set-up have changed => Change expected version "
                                        "container in test accordingly.";

  const FirmwareCont exp_versions{ { joint_names_.at(0), "100 Build:11158 Date:2018-06-07 16:49:55" },
                                   { joint_names_.at(1), "101 Build:11158 Date:2018-06-07 16:49:55" } };

  EXPECT_CALL(*this, executeGetObject(_, _))
      .Times(2)
      .WillRepeatedly(testing::Invoke([exp_versions](GetObject::Request& req, GetObject::Response& res) {
        res.value = exp_versions.at(req.node) + "AdditionalStuffWhichNeedsToBeRemoved";
        res.success = true;
        return true;
      }));

  // Check that returned versions from service are correct
  ros::NodeHandle nh{ "~" };
  SystemInfo info{ nh };
  FirmwareCont actual_version_cont{ info.getFirmwareVersions() };
  for (const auto& joint : joint_names_)
  {
    EXPECT_TRUE(actual_version_cont.find(joint) != actual_version_cont.cend()) << "No version for joint found";
    EXPECT_EQ(exp_versions.at(joint), actual_version_cont.at(joint)) << "Expected and actual firmware version do not "
                                                                        "match";
  }
}

}  // namespace system_info_tests

int main(int argc, char* argv[])
{
  ros::init(argc, argv, "system_info_test");
  ros::NodeHandle nh;

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
