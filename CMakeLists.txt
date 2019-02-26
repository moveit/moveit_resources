cmake_minimum_required(VERSION 3.10.2)
project(moveit_resources)

find_package(ament_cmake REQUIRED)
file(MAKE_DIRECTORY "include")
ament_export_include_directories(include "include/")

# install space file
set(MOVEIT_TEST_RESOURCES_DIR "share/${PROJECT_NAME}")
configure_file("include/${PROJECT_NAME}/config.h.in" "include/${PROJECT_NAME}/.config_install.h")

install(
  DIRECTORY pr2_description fanuc_description panda_description mara_description
DESTINATION "share/${PROJECT_NAME}")
install(
  FILES "${CMAKE_BINARY_DIR}/include/${PROJECT_NAME}/.config_install.h"
  DESTINATION "include/${PROJECT_NAME}"
  RENAME "config.h")

install(DIRECTORY fanuc_moveit_config panda_moveit_config DESTINATION "share/${PROJECT_NAME}")
ament_package()
