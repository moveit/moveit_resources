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

#include <ros/ros.h>
#include <prbt_support/system_info.h>

using namespace prbt_support;

/**
 * @brief Logs important system information.
 */
// LCOV_EXCL_START
int main(int argc, char** argv)
{
  ros::init(argc, argv, "system_info");
  ros::NodeHandle nh{ "~" };

  prbt_support::SystemInfo system_info(nh);
  FirmwareCont versions{ system_info.getFirmwareVersions() };
  for (const auto& curr_elem : versions)
  {
    ROS_INFO("Firmware version [%s]: %s", curr_elem.first.c_str(), curr_elem.second.c_str());
  }
  return EXIT_SUCCESS;
}
// LCOV_EXCL_STOP
