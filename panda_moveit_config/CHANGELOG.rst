^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package moveit_resources_panda_moveit_config
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

3.0.0 (2024-02-19)
------------------
* Update acceleration limits for robot configs (`#195 <https://github.com/ros-planning/moveit_resources/issues/195>`_)
  * update panda
  * rename file to joint_limits_jerk_limited.yaml
  * rename to hard_joint_limits.yaml
  ---------
* Update ros2 control usage (`#192 <https://github.com/ros-planning/moveit_resources/issues/192>`_)
  * Update ros2_control usage
  * Update dual_arm_panda_moveit_config/config/panda_hand.ros2_control.xacro
  Co-authored-by: Sebastian Castro <4603398+sea-bass@users.noreply.github.com>
  ---------
  Co-authored-by: Sebastian Castro <4603398+sea-bass@users.noreply.github.com>
* Update planner configs (`#191 <https://github.com/ros-planning/moveit_resources/issues/191>`_)
* Update planning pipeline configs (`#189 <https://github.com/ros-planning/moveit_resources/issues/189>`_)
* Fix Panda demo launch for MoveIt 2 tutorials (`#190 <https://github.com/ros-planning/moveit_resources/issues/190>`_)
* Add bio_ik and TRAC-IK kinematics configs (`#187 <https://github.com/ros-planning/moveit_resources/issues/187>`_)
* Remove unsupported planner configs (`#182 <https://github.com/ros-planning/moveit_resources/issues/182>`_)
* Create Panda URDF Xacro, restore URDF for RobotModelTestUtils (`#178 <https://github.com/ros-planning/moveit_resources/issues/178>`_)
* Contributors: Henning Kayser, Paul Gesel, Sebastian Castro, Sebastian Jahr

2.1.1 (2023-05-18)
------------------

2.1.0 (2023-05-18)
------------------
* Cherry pick TopicBased rename `#163 <https://github.com/ros-planning/moveit_resources/issues/163>`_ (`#172 <https://github.com/ros-planning/moveit_resources/issues/172>`_)
  Co-authored-by: Jafar <cafer.abdi@gmail.com>
* Add STOMP planner config (`#171 <https://github.com/ros-planning/moveit_resources/issues/171>`_)
  Co-authored-by: Henning Kayser <henningkayser@picknik.ai>
* Remove comments from scalars (`#169 <https://github.com/ros-planning/moveit_resources/issues/169>`_)
* Enable AnytimePathShortening and fix benchmarks (`#167 <https://github.com/ros-planning/moveit_resources/issues/167>`_)
* Update information about Ruckig and jerk limits (`#168 <https://github.com/ros-planning/moveit_resources/issues/168>`_)
* Enable acceleration limits so TOTG can work (`#166 <https://github.com/ros-planning/moveit_resources/issues/166>`_)
* Add joint limits to Panda demo launch file + make consistent with tutorials (`#165 <https://github.com/ros-planning/moveit_resources/issues/165>`_)
* [ROS2]: Add a new parameter to panda's xacro to select ros2_control hardware interface type (`#158 <https://github.com/ros-planning/moveit_resources/issues/158>`_)
  * Add xacro parameter to select ros2_control hardware interface type
  * Update panda demo launch file to have ros2_control_hardware_type argument
  * Add argument to the launch description
* Add execution_duration_monitoring param to the example config (`#160 <https://github.com/ros-planning/moveit_resources/issues/160>`_)
* Fix xacro deprecation warning: use xacro.load_yaml() (`#156 <https://github.com/ros-planning/moveit_resources/issues/156>`_)
* Add Pilz to panda launch (`#154 <https://github.com/ros-planning/moveit_resources/issues/154>`_)
* Add pilz_industrial_motion_planner_planning.yaml (`#151 <https://github.com/ros-planning/moveit_resources/issues/151>`_)
* Contributors: AndyZe, Giovanni, Jafar, Marq Rasmussen, Sebastian Castro, Sebastian Jahr, Stephanie Eng

2.0.6 (2022-07-18)
------------------
* fake_components -> mock_components (`#147 <https://github.com/ros-planning/moveit_resources/issues/147>`_)
* Rename cartesian_limits.yaml (`#146 <https://github.com/ros-planning/moveit_resources/issues/146>`_)
* Contributors: AndyZe, Tyler Weaver

2.0.5 (2022-06-25)
------------------
* Fix a typo in chomp_planning.yaml (`#143 <https://github.com/ros-planning/moveit_resources/issues/143>`_)
* Update ros2_control launching (`#140 <https://github.com/ros-planning/moveit_resources/issues/140>`_)
* Proper scoping for controllers in Panda Config (`#132 <https://github.com/ros-planning/moveit_resources/issues/132>`_)
* Contributors: AndyZe, David V. Lu!!, Stephanie Eng

2.0.4 (2022-05-19)
------------------
* Explicitly use CHOMP and OMPL planners (`#135 <https://github.com/ros-planning/moveit_resources/issues/135>`_)
* Rename Panda Controller Files (`#127 <https://github.com/ros-planning/moveit_resources/issues/127>`_)
* Fix controller_manager node's output type (`#129 <https://github.com/ros-planning/moveit_resources/issues/129>`_)
* Black Formatting for Launch Files (`#128 <https://github.com/ros-planning/moveit_resources/issues/128>`_)
* Refactor panda demo.launch to use moveit_configs_utils (`#119 <https://github.com/ros-planning/moveit_resources/issues/119>`_)
* Remove stomp configuration file (`#126 <https://github.com/ros-planning/moveit_resources/issues/126>`_)
* Restore panda_gripper_controllers.yaml. Rename panda_moveit_controllers.yaml (`#117 <https://github.com/ros-planning/moveit_resources/issues/117>`_)
* Delete deprecated Panda config and launch files (`#98 <https://github.com/ros-planning/moveit_resources/issues/98>`_)
* No initial velocity conditions (`#111 <https://github.com/ros-planning/moveit_resources/issues/111>`_)
* ros2_control update: initial_position -> initial_value (`#110 <https://github.com/ros-planning/moveit_resources/issues/110>`_)
* Update yaml parameters for moveit_configs_utils (`#108 <https://github.com/ros-planning/moveit_resources/issues/108>`_)
* Port PRBT packages for PILZ planner tests (`#101 <https://github.com/ros-planning/moveit_resources/issues/101>`_)
* Adding RPBT config (`#43 <https://github.com/ros-planning/moveit_resources/issues/43>`_)
  to speed up test time by skipping trajectory in fake execution
* Contributors: AndyZe, Christian Henkel, David V. Lu!!, Henning Kayser, Jafar, Jafar Abdi, Sebastian Jahr, Stephanie Eng

2.0.3 (2021-09-16)
------------------
* Migrate to joint state broadcaster
* Add panda_hand_controller to demo.launch.py (`#87 <https://github.com/ros-planning/moveit_resources/issues/87>`_)
* Add fake controller for panda_hand (`#73 <https://github.com/ros-planning/moveit_resources/issues/73>`_)
* Contributors: Jafar Abdi, Marq Rasmussen, Vatan Aksoy Tezer

2.0.2 (2021-05-24)
------------------
* Add missing ros2_control parameters (`#74 <https://github.com/ros-planning/moveit_resources/issues/74>`_)
* Add Panda demo.launch.py and RViz config (`#64 <https://github.com/ros-planning/moveit_resources/issues/64>`_)
* Remove move group prefixes from rviz configs (`#62 <https://github.com/ros-planning/moveit_resources/issues/62>`_)
* Ensure panda joint limits have the proper type (`#63 <https://github.com/ros-planning/moveit_resources/issues/63>`_)
* Contributors: AndyZe, Henning Kayser, Vatan Aksoy Tezer

2.0.1 (2021-04-09)
------------------
* Update panda configs for ros2_control (`#51 <https://github.com/ros-planning/moveit_resources/issues/51>`_)
* Contributors: Jafar Abdi, Tyler Weaver

2.0.0 (2020-11-20)
------------------
* Port and modernize CMakeLists.txt + package.xml for ROS2 (`#26 <https://github.com/ros-planning/moveit_resources/issues/26>`_, `#31 <https://github.com/ros-planning/moveit_resources/issues/31>`_)
* Contributors: Henning Kayser, Jafar Abdi, Mike Lautman, Nathan Brooks

0.7.1 (2020-10-09)
------------------
* Fix self-colliding 'extended' pose (`#42 <https://github.com/ros-planning/moveit_resources/issues/42>`_)
* Contributors: Henning Kayser

0.7.0 (2020-08-13)
------------------
* Split resources into multiple packages (`#36 <https://github.com/ros-planning/moveit_resources/issues/36>`_)
* Remove solver attempts (`#35 <https://github.com/ros-planning/moveit_resources/issues/35>`_)
* Contributors: Michael Görner, Robert Haschke
