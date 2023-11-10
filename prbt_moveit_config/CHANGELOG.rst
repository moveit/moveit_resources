^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package moveit_resources_prbt_moveit_config
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.8.3 (2023-11-10)
------------------
* Add ResolveConstraintFrames to all planning pipelines
* Contributors: Robert Haschke

0.8.2 (2021-11-18)
------------------

0.8.1 (2021-11-06)
------------------
* Remove deprecated xacro ``--inorder`` flag
* Rename launch parameter ``execution_type`` -> ``fake_execution_type`` to clarify that it is only used for fake controllers
* Replace ``$(find moveit_resources\_*_moveit_config)/launch/*`` -> ``$(dirname)/*``
* Introduce ``prbt_moveit_config/launch/test_environment.launch``
* Contributors: Robert Haschke

0.8.0 (2021-04-28)
------------------
* Let users specify fake execution type for demo.launch (`#61 <https://github.com/ros-planning/moveit_resources/issues/61>`_)
  Required to invoke demo.launch use_rviz:=false with execution speedup for tests.
  See https://github.com/ros-planning/moveit/pull/2602
  for the corresponding patch in the setup assistant.
* Contributors: Michael Görner

0.7.2 (2021-03-26)
------------------
* Run multiple planning pipelines with MoveGroup (`#47 <https://github.com/ros-planning/moveit_resources/issues/47>`_)
* Adding PRBT config (`#43 <https://github.com/ros-planning/moveit_resources/issues/43>`_)
* Contributors: Christian Henkel, Joachim Schleicher, Henning Kayser
