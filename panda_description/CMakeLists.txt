cmake_minimum_required(VERSION 3.1.3)
project(moveit_resources_panda_description)
find_package(catkin REQUIRED)
find_package(xacro REQUIRED)

catkin_package()

xacro_add_xacro_file(urdf/panda_arm_hand.urdf.xacro ${CMAKE_CURRENT_SOURCE_DIR}/urdf/panda.urdf)
xacro_install(xacro ${XACRO_OUTPUT_FILE} DESTINATION robots)

install(DIRECTORY meshes urdf DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
