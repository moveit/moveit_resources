cmake_minimum_required(VERSION 3.1.3)
project(moveit_resources_pr2_description)
find_package(catkin REQUIRED)

catkin_package()

install(DIRECTORY srdf urdf DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
install(FILES kinect.dae DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
