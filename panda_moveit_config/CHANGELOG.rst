^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package moveit_resources_panda_moveit_config
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.7.2 (2021-03-26)
------------------
* Master GitHub actions (`#57 <https://github.com/ros-planning/moveit_resources/issues/57>`_)
* Fix formatting issues
* Run multiple planning pipelines with MoveGroup (`#47 <https://github.com/ros-planning/moveit_resources/issues/47>`_)
* Update panda_moveit_config launch files, add use_rviz parameter (`#52 <https://github.com/ros-planning/moveit_resources/issues/52>`_)
  Regenerated demo.launch and rviz.launch from setup assistant.
  The main motivation for this change is the additional use_rviz argument
  through which rviz can be disabled.
  The `rviz_tutorial` parameter in moveit_rviz.launch was only ever used
  through demo.launch and it's easier to handle the different rviz configurations there.
* Adding RPBT config (`#43 <https://github.com/ros-planning/moveit_resources/issues/43>`_)
  Co-authored-by: Joachim Schleicher <J.Schleicher@pilz.de>
* Contributors: Christian Henkel, Henning Kayser, Michael Görner, Robert Haschke, Tyler Weaver

* add execution_type and pilz pipeline to panda config
* Contributors: Pilz GmbH and Co. KG

0.7.1 (2020-10-09)
------------------
* Fix self-colliding 'extended' pose (`#42 <https://github.com/ros-planning/moveit_resources/issues/42>`_)
* Contributors: Henning Kayser

0.7.0 (2020-08-13)
------------------
* Split resources into multiple packages (`#36 <https://github.com/ros-planning/moveit_resources/issues/36>`_)
* Remove solver attempts (`#35 <https://github.com/ros-planning/moveit_resources/issues/35>`_)
* Contributors: Michael Görner, Robert Haschke
