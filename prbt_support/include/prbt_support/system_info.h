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

#ifndef PRBT_SUPPORT_SYSTEM_INFO_H
#define PRBT_SUPPORT_SYSTEM_INFO_H

#include <ros/ros.h>

#include <string>
#include <vector>
#include <map>

#include <canopen_chain_node/GetObject.h>

namespace prbt_support
{
//! key = joint_name
//! value = firmware version of joint
using FirmwareCont = std::map<std::string, std::string>;

/**
 * @brief Provides easy access to system information which are of importance
 * when analyzing bugs.
 */
class SystemInfo
{
public:
  SystemInfo(ros::NodeHandle& nh);

  /**
   * @returns a container comprised of the firmware version of each joint
   * of the robot.
   */
  FirmwareCont getFirmwareVersions();

  /**
   * @returns the firmware version of the specified joint.
   */
  std::string getFirmwareVersionOfJoint(const std::string& joint_name);

private:
  /**
   * @returns the names of all joints/nodes.
   */
  static std::vector<std::string> getNodeNames(const ros::NodeHandle& nh);

private:
  const std::vector<std::string> joint_names_;
  ros::ServiceClient canopen_srv_get_client_;
};

}  // namespace prbt_support
#endif  // PRBT_SUPPORT_SYSTEM_INFO_H
