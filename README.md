# Contact nodes demo package

This package illustrates an example scenario of a reactive Behavior Tree (BT) implementation.
Two actions, "pickup" and "contact" need to be executed in order for a certain
task to be executed successfully. To leverage the reactiveness a BT offers,
we pair each action with a condition, under a selector node. The conditions will
act as the "BT state", which indicate the status of the task.

For instance, if "pickup" was successful, the "has_grasp" condition will be true.
When a BT tick is sent, the first subtree will return true, without the need for ticking
the pickup action again. If, during the contact action, "has_grasp" becomes false,
the tree will react accordingly and preempt "contact". On the following tick,
"pickup" will run again.

The demo also implements a service, "/contact/toggle_teach", which when called will
toggle between normal and teach modes. In teach mode, the "got_contact" condition
will always return false, forcing the tree to repeat the contact action. This illustrates
a [SARAFun](http://h2020sarafun.eu/) application where we might want to repeat a certain action in order to
teach an assembly system details of a task.

## Launch the demo
After compiling the catkin workspace where the package is downloaded to and sourcing your workspace, run
``$ roslaunch contact_nodes contact_nodes.launch`` to start the system.

You'll have to call a service with the path of the ``action_nodes_config.yaml`` path. Example:
``$ rosservice call /sarafun/start_tree "file_path: '/home/<username>/catkin_ws/src/contact_nodes/config/example_slippage.json'"``

### Launch parameters
The launch file offers these parameters

* ``debug``: Set to true to launch the tree in gdb with the logging level set at debug. Default: false
* ``has_grasp_fail_thres``: Set to a value in the range <0, 1> to define the probability this node will succeed,
if the success conditions are met. A value smaller than 1 will showcase the tree reactivity when a grasp is lost. Default: 1

## Dependencies

This package depends on the following:

* [ROS-Behavior Tree](https://github.com/diogoalmeida/ROS-Behavior-Tree) - BT package
* [sarafun_bt](https://github.com/diogoalmeida/sarafun_bt) - Packages which enable integration of
generic actionlib servers as actions in a ROS-Behavior Tree.
* [sarafun_msgs](https://github.com/diogoalmeida/sarafun_msgs) - Messages used in the examples
