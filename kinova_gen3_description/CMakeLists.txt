cmake_minimum_required(VERSION 3.10.2)
project(moveit_resources_kinova_gen3_description)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

find_package(ament_cmake REQUIRED)

install(
  DIRECTORY arms grippers launch robots rviz
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
