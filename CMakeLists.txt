cmake_minimum_required(VERSION 2.8.3)
project(moveit_resources)

find_package(catkin REQUIRED)

file(MAKE_DIRECTORY "${CATKIN_DEVEL_PREFIX}/include")
catkin_package(INCLUDE_DIRS include "${CATKIN_DEVEL_PREFIX}/include")

# devel space file
set(MOVEIT_TEST_RESOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR})
configure_file("include/${PROJECT_NAME}/config.h.in" "${CATKIN_DEVEL_PREFIX}/include/${PROJECT_NAME}/config.h")

# install space file
set(MOVEIT_TEST_RESOURCES_DIR ${CMAKE_INSTALL_PREFIX}/${CATKIN_PACKAGE_SHARE_DESTINATION})
configure_file("include/${PROJECT_NAME}/config.h.in" "${CATKIN_DEVEL_PREFIX}/include/${PROJECT_NAME}/.config_install.h")

install(
  DIRECTORY pr2_description fanuc_description
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
install(
  FILES "${CATKIN_DEVEL_PREFIX}/include/${PROJECT_NAME}/.config_install.h"
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  RENAME "config.h")

# fanuc moveit config
install(DIRECTORY fanuc_moveit_config DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
