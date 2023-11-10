^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package moveit_resources_panda_moveit_config
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.8.3 (2023-11-10)
------------------
* Add ResolveConstraintFrames to all planning pipelines
* Add dual_panda_moveit_config (`#133 <https://github.com/ros-planning/moveit_resources/issues/133>`_)
* Contributors: Robert Haschke, Cristian Beltran

0.8.2 (2021-11-18)
------------------
* test_environment.launch: use fake_execution_type="last point" by default
* Contributors: Robert Haschke

0.8.1 (2021-11-06)
------------------
* Recreated moveit_resources_panda_moveit_config with latest MSA (`#92 <https://github.com/ros-planning/moveit_resources/issues/92>`_)
* Rename launch parameter ``execution_type`` -> ``fake_execution_type`` to clarify that it is only used for fake controllers
* Replace ``$(find moveit_resources\_*_moveit_config)/launch/*`` -> ``$(dirname)/*``
* Introduce ``prbt_moveit_config/launch/test_environment.launch``
* Remove TrajOpt planner config from OMPL pipeline (`#85 <https://github.com/ros-planning/moveit_resources/issues/85>`_)
* Minor fixes (`#90 <https://github.com/ros-planning/moveit_resources/issues/90>`_)
  * CHOMP parameter ``collision_clearance`` got renamed (fixed typo)
  * Fix empty sensors_3d.yaml
  * ``setup_assistant.launch``: require MSA node
* Contributors: Captain Yoshi, Michael Görner, Robert Haschke

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
