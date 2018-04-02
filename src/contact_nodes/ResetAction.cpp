#include <contact_nodes/ResetAction.h>

namespace sarafun {
bool ResetAction::fillGoal(contact_nodes::ResetKeyframeGoal &goal) {
  int idx;

  fillParameter("/sarafun/reset/idx", 0, idx);
  goal.idx = idx;

  return true;
}

double ResetAction::getTimeoutValue() {
  double timeout = 0;
  fillParameter("/sarafun/bt_action_nodes/reset/timeout", 30.0, timeout);

  return timeout;
}
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "ResetAction");
  std::string bt_client_name, action_server_name;

  if (!ros::param::get("/sarafun/bt_action_nodes/reset/action_server_name", action_server_name))
  {
    ROS_ERROR("%s missing action server name", ros::this_node::getName().c_str());
    return -1;
  }

  if (!ros::param::get("/sarafun/bt_action_nodes/reset/bt_client_name", bt_client_name))
  {
    ROS_ERROR("%s missing bt client name", ros::this_node::getName().c_str());
    return -1;
  }

  sarafun::ResetAction reset_action(
      ros::this_node::getName(),  action_server_name, bt_client_name);
  ros::spin();
  return 1;
}
