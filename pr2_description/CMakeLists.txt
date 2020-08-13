cmake_minimum_required(VERSION 3.10.2)
project(moveit_resources_pr2_description)
find_package(ament_cmake REQUIRED)

ament_package()

install(DIRECTORY srdf urdf DESTINATION share/${PROJECT_NAME})
install(FILES kinect.dae DESTINATION share/${PROJECT_NAME})
