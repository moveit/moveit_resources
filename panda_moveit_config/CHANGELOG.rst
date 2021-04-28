^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package moveit_resources_panda_moveit_config
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.8.0 (2021-04-28)
------------------
* Let users specify fake execution type for demo.launch (`#61 <https://github.com/ros-planning/moveit_resources/issues/61>`_)
  Required to invoke demo.launch use_rviz:=false with execution speedup for tests.
  See https://github.com/ros-planning/moveit/pull/2602
  for the corresponding patch in the setup assistant.
* Contributors: Michael Görner

0.7.2 (2021-03-26)
------------------
* Migrate to GitHub Actions (`#57 <https://github.com/ros-planning/moveit_resources/issues/57>`_)
* Fix formatting issues
* Run multiple planning pipelines with MoveGroup (`#47 <https://github.com/ros-planning/moveit_resources/issues/47>`_)
* Update panda_moveit_config launch files: add use_rviz parameter (`#52 <https://github.com/ros-planning/moveit_resources/issues/52>`_)
* Add Pilz planner pipeline
* Contributors: Christian Henkel, Joachim Schleicher, Henning Kayser, Michael Görner, Robert Haschke, Tyler Weaver

0.7.1 (2020-10-09)
------------------
* Fix self-colliding 'extended' pose (`#42 <https://github.com/ros-planning/moveit_resources/issues/42>`_)
* Contributors: Henning Kayser

0.7.0 (2020-08-13)
------------------
* Split resources into multiple packages (`#36 <https://github.com/ros-planning/moveit_resources/issues/36>`_)
* Remove solver attempts (`#35 <https://github.com/ros-planning/moveit_resources/issues/35>`_)
* Contributors: Michael Görner, Robert Haschke
