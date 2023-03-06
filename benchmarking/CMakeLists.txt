cmake_minimum_required(VERSION 3.10.2)
project(moveit_resources_benchmarking)
find_package(ament_cmake REQUIRED)

ament_package()

install(DIRECTORY config databases launch DESTINATION share/${PROJECT_NAME})
