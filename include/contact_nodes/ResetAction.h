#ifndef __RESET_ACTION__
#define __RESET_ACTION__

#include <ros/ros.h>
#include <sarafun_tree/ExecuteAction.h>
#include <contact_nodes/ResetKeyframeAction.h>

namespace sarafun {
class ResetAction
    : ExecuteAction<contact_nodes::ResetKeyframeAction,
                    contact_nodes::ResetKeyframeGoal> {
public:
  ResetAction(std::string node_name, std::string action_name,
                        std::string bt_name)
      : ExecuteAction<
            contact_nodes::ResetKeyframeAction,
            contact_nodes::ResetKeyframeGoal>::ExecuteAction(node_name,
                                                               action_name,
                                                               bt_name),
        node_name_(node_name), bt_name_(bt_name) {
    node_handle_ = ros::NodeHandle(node_name);
  }
  ~ResetAction() {}

  bool fillGoal(contact_nodes::ResetKeyframeGoal &goal);
  double getTimeoutValue();

private:
  ros::NodeHandle node_handle_;
  std::string node_name_;
  std::string bt_name_;
};
}
#endif
