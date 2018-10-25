cmake_minimum_required(VERSION 2.8.3)
project(kinematics_tests_support)

add_compile_options(-std=c++11)
find_package(catkin REQUIRED)

###################################
## catkin specific configuration ##
###################################
catkin_package(
)

###########
## Build ##
###########

#############
## Install ##
#############

install(DIRECTORY urdf DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
install(DIRECTORY meshes DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

#############
## Testing ##
#############

