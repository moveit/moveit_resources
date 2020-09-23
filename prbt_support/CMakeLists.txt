cmake_minimum_required(VERSION 2.8.3)
project(moveit_resources_prbt_support)

find_package(catkin REQUIRED COMPONENTS
  canopen_chain_node
  pilz_utils
  roscpp
  roslint
  sensor_msgs
)

add_definitions(-Wall)
add_definitions(-Wextra)
add_definitions(-Wno-unused-parameter)
add_definitions(-Werror)
add_definitions(-std=c++11)
add_definitions(-Wconversion) # At least this line needs to be below find_package to keep
                              #  the flag away from the gmock build
add_definitions(-Wpedantic)

catkin_package(
  CATKIN_DEPENDS roscpp
  INCLUDE_DIRS include
)

################
## Clang tidy ##
################
if(CATKIN_ENABLE_CLANG_TIDY)
  find_program(
    CLANG_TIDY_EXE
    NAMES "clang-tidy"
    DOC "Path to clang-tidy executable"
    )
  if(NOT CLANG_TIDY_EXE)
    message(FATAL_ERROR "clang-tidy not found.")
  else()
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")
    set(CMAKE_CXX_CLANG_TIDY "${CLANG_TIDY_EXE}")
  endif()
endif()

###########
## Build ##
###########

include_directories(
  include ${catkin_INCLUDE_DIRS}
)

# SYSTEM_INFO_NODE
add_executable(system_info_node
  src/system_info_node.cpp
  src/system_info.cpp
  src/system_info_exception.cpp
)
add_dependencies(system_info_node ${catkin_EXPORTED_TARGETS})
target_link_libraries(system_info_node ${catkin_LIBRARIES})

#############
## Install ##
#############

## Install URDF and meshes
install(DIRECTORY launch DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
install(DIRECTORY urdf DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
install(DIRECTORY meshes DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
install(DIRECTORY config DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
  PATTERN ".svn" EXCLUDE)

install(TARGETS
  system_info_node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

#############
## Testing ##
#############

if(CATKIN_ENABLE_TESTING)

  find_package(rostest REQUIRED)
  find_package(moveit_core REQUIRED)
  find_package(moveit_ros_planning REQUIRED)
  find_package(cmake_modules REQUIRED)
  find_package(Eigen3 REQUIRED)
  find_package(pilz_testutils REQUIRED)

  if(ENABLE_COVERAGE_TESTING)
    find_package(code_coverage REQUIRED)
    APPEND_COVERAGE_COMPILER_FLAGS()
  endif()

  #catkin_lint: ignore_once missing_directory <-- needed for successful catkin_linting
  #Declare system to supress strict compiler errors in external library headers
  include_directories(
    ${pilz_testutils_INCLUDE_DIRS}
    SYSTEM
    ${catkin_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR}
    ${gmock_SOURCE_DIR}/include/
  )

  #--- SystemInfo unit test ---
  add_rostest_gmock(unittest_system_info
      test/unit_tests/unittest_system_info.test
      test/unit_tests/unittest_system_info.cpp
      src/system_info.cpp
      src/system_info_exception.cpp
  )
  target_link_libraries(unittest_system_info
    ${catkin_LIBRARIES}
  )
  #----------------------------------------

#  add_rostest_gtest(urdf_tests
#  test/urdf_tests.test
#  test/urdf_tests.cpp
#  )
#
#  target_link_libraries(urdf_tests
#    ${catkin_LIBRARIES}
#    ${roscpp_LIBRARIES}
#    ${moveit_core_LIBRARIES}
#    ${moveit_ros_planning_LIBRARIES}
#    ${Eigen3_LIBRARIES})

  find_package(roslaunch REQUIRED)
  roslaunch_add_file_check(launch)

  roslint_python(
    test/acceptance_tests/acceptance_test_joint_limits.py
  )
  roslint_add_test()

  # to run: catkin_make -DENABLE_COVERAGE_TESTING=ON package_name_coverage (adding -j1 recommended)
  if(ENABLE_COVERAGE_TESTING)
    set(COVERAGE_EXCLUDES "*/${PROJECT_NAME}/test*")
    add_code_coverage(
      NAME ${PROJECT_NAME}_coverage
      DEPENDS tests
    )
  endif()

endif()
