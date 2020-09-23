# unapply all patches
quilt pop -a

robot_name=prbt
srdf_path="$(rospack find ${robot_name}_moveit_config)/config/${robot_name}.srdf"
xacro $srdf_path.xacro > $srdf_path
./update_ikfast_plugin.sh
rm $srdf_path

# apply all patches
quilt push -a

