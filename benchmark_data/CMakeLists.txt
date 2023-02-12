cmake_minimum_required(VERSION 3.10.2)
project(moveit_resources_benchmark_data)
find_package(ament_cmake REQUIRED)

ament_package()

install(DIRECTORY databases DESTINATION share/${PROJECT_NAME})
