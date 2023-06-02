# panda_description

> Note: This package contains a panda.urdf and a newer panda.urdf.xacro.
> The XACRO has been created to support finding package resource files dynamically which is needed for Gazebo.
> The URDF is still needed by [RobotModelTestUtils](https://github.com/ros-planning/moveit2/blob/main/moveit_core/utils/src/robot_model_test_utils.cpp#L75) which doesn't support xacro yet.

The URDF model and meshes contained in this package were copied from the frankaemika `franka_ros` package and adapted for use with `moveit_resources`.

All imported files were released under the Apache-2.0 license.
