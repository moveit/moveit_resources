^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package moveit_resources_fanuc_moveit_config
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.7.2 (2021-03-26)
------------------
* Run multiple planning pipelines with MoveGroup (`#47 <https://github.com/ros-planning/moveit_resources/issues/47>`_)
* Change package maintainer: Dave to Robert (`#49 <https://github.com/ros-planning/moveit_resources/issues/49>`_)
  * Change package maintainer to MoveIt Release Team
  Co-authored-by: Robert Haschke <rhaschke@techfak.uni-bielefeld.de>
* Adding RPBT config (`#43 <https://github.com/ros-planning/moveit_resources/issues/43>`_)
  * adding RPBT config
  * removing roslaunch check becasue of removed dependencies
  * adding pilz pipeline config for panda
  * add remaining prbt-related packages
  * prbt_ikfast_manipulaor_plugin
  * prbt_support
  * prbt_pg70_support
  * drop no longer needed dependency
  * add remaining prbt-related packages
  * prbt_ikfast_manipulaor_plugin
  * prbt_support
  * prbt_pg70_support
  * add argument to enable last point execution
  to speed up test time by skipping trajectory in fake execution
  * last point execution for pg70 gripper
  * drop system_info
  since we only need urdf model for testing in simulation
  to get rid of dependency to pilz_testutils
  * actually use pg70 package
  inside from moveit_resources instead of schunk_description
  * drop depend on prbt_hardware_support
  not needed in simulation
  * add execution type for panda config
  to allow skipping execution and jump to last point in fake execution
  * fixup 4bc2ce drop system_info
  * fix roslaunch and CMakeLists checks
  * also adding capabilities here
  * drop more dependencies
  * using pg70 support from moveit_resources
  * add execution_type to gripper
  * drop Werror
  as suggested in the review by v4hn
  * update deprecated macro to INSTANTIATE_TEST_SUITE_P
  * Revert "update deprecated macro to INSTANTIATE_TEST_SUITE_P"
  This reverts commit 1a467ccea675af7fe296ff8ba18c4f8bee9d53f0.
  * update version numbers to be consitant across the meta-package
  * version increase fo pilz packages
  * removing patch files
  * tiny fix
  * update panda config from templates
  re-generated from MSA with adapted templates
  see moveit 99c059f
  * update fanuc package from MSA
  with updated templates, see moveit commit a4527b
  * drop remapping to joint_states_desired
  for easier include of move_group.launch into tests.
  This brings the panda_moveit_config closer to the templates in MSA.
  Co-authored-by: Joachim Schleicher <J.Schleicher@pilz.de>
* Contributors: Christian Henkel, Dave Coleman, Henning Kayser

0.7.1 (2020-10-09)
------------------

0.7.0 (2020-08-13)
------------------
* Split resources into multiple packages (`#36 <https://github.com/ros-planning/moveit_resources/issues/36>`_)
* Contributors: Robert Haschke, Michael Görner
