^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package prbt_moveit_config
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.5.18 (2020-07-02)
-------------------

0.5.17 (2020-06-22)
-------------------

0.5.16 (2020-05-15)
-------------------

0.5.15 (2020-05-03)
-------------------
* Use default hardware setup in moveit_planning_execution.launch
* Contributors: Pilz GmbH and Co. KG

0.5.14 (2020-03-11)
-------------------
* add pipeline for merging the planner into moveit (old pipeline still available)
* Contributors: Pilz GmbH and Co. KG

0.5.13 (2019-12-04)
-------------------

0.5.12 (2019-11-28)
-------------------
* Fake speed override in case of sim:=true
* Contributors: Pilz GmbH and Co. KG

0.5.11 (2019-11-22)
-------------------

0.5.10 (2019-10-08)
-------------------

0.5.9 (2019-10-07)
------------------
* Fix warning by change parent and child of fixed frame
* Contributors: Pilz GmbH and Co. KG

0.5.8 (2019-09-10)
------------------

0.5.7 (2019-08-29)
------------------

0.5.6 (2019-06-12)
------------------

0.5.5 (2019-06-12)
------------------

0.5.4 (2019-05-27)
------------------

0.5.3 (2019-04-24)
------------------
* Set interactive marker size in RViz config
* Remove unnecessary file test_context.launch
* Add missing dependency on joint_state_controller
* update the documentation
* Contributors: Pilz GmbH and Co. KG

0.5.2 (2019-02-21)
------------------
* Remove exec_depend on metapackages
* Rename command_planner to pilz_command_planner
* Set default pipeline to ompl. To run with the specified
  run_depends we cannot default to command_planner.
* Contributors: Pilz GmbH and Co. KG

0.5.1 (2018-11-30)
------------------
* melodic release based on kinetic version 0.4.3
* Contributors: Pilz GmbH and Co. KG

0.5.0 (2018-11-07)
------------------

0.4.3 (2018-11-30)
------------------
* load pilz capabilities for command_planner by default
* adjust rviz config

0.4.2 (2018-11-08)
------------------

0.4.1 (2018-11-07)
------------------

0.4.0 (2018-11-06)
------------------
* add capabilities argument to moveit_planning_execution.launch
* Contributors: Pilz GmbH and Co. KG

0.3.0 (2018-08-15)
------------------
* remove dependency on gripper

0.2.2 (2018-07-26)
------------------
* Add capabilities argument to move_group.launch

0.2.1 (2018-07-19)
------------------
* Add <url> tag to all package.xml files
* test launch files and add missing dependencies

0.2.0 (2018-07-12)
------------------
* configuration files for moveit. see moveit_planning_execution.launch
* Contributors: Alexander Gutenkunst, Fahri Demirci, Hagen Slusarek, Immanuel Martini, Joachim Schleicher, Kai Hu
