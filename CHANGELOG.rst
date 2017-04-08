^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Changelog for package moveit_resources
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

0.6.2 (2017-04-07)
------------------
* [fix] Missing license to fanuc pkgs imported from ros-industrial/fanuc. `#11 <https://github.com/ros-planning/moveit_resources/issues/11>`_. (`#12 <https://github.com/ros-planning/moveit_resources/issues/12>`_)
* [fix] Missing run depends for [robot|joint]_state_publisher (`#14 <https://github.com/ros-planning/moveit_resources/issues/14>`_)
* [fix] Correct warehouse ros mongo (`#13 <https://github.com/ros-planning/moveit_resources/issues/13>`_)
* [improve] test chomp (`#10 <https://github.com/ros-planning/moveit_resources/issues/10>`_)
* Contributors: Chittaranjan Srinivas Swaminathan, Dave Coleman, G.A. vd. Hoorn, kirstyellis

0.6.1 (2016-08-27)
------------------
* [sys] Added Fanuc robot model (m10ia) for system testing. Improve README (`#7 <https://github.com/ros-planning/moveit_resources/issues/7>`_, `#8 <https://github.com/ros-planning/moveit_resources/issues/8>`_)
* Contributors: Dave Coleman, Robert Haschke

0.6.0 (2016-01-30)
------------------
* Don't make include dir into build
* Place include folder in the devel space instead of the build space
  fixes #5 .
* Add travis indicator
* added branch name to build status
* added travis build status indicator in README.md
* Merge pull request #3 from ros-planning/add-travis
  added travis support
* Contributors: Dave Coleman, Dave Hershberger, Nantas Nardelli, isucan

0.5.0 (2013-07-30)
------------------
* bump version for hydro

0.4.1 (2013-07-03)
------------------
* fix for missing include path
* fix for missing config.h

0.4.0 (2013-05-24)
------------------
  fix config.h so it is not created in the source dir
* fix config.h so it is not created in the source dir

0.3.1 (2013-05-20)
------------------
* create config file with location of test resources

0.3.0 (2013-03-09)
------------------
  fix srdf robot name
* change robot name to "pr2" to match urdf

0.2.0 (2013-01-15)
------------------
* bump version
* update urdf

0.1.1 (2012-12-20)
------------------
* fix buildtool tag

0.1.0 (2012-12-13)
------------------
* add build system
* adding test resources
* Update README.md
* Update README.md
* Initial commit
