#ifndef __NO_SLIPPAGE_CONDITION__
#define __NO_SLIPPAGE_CONDITION__

#include <ros/ros.h>
#include <behavior_tree_leaves/ConditionTemplate.h>
#include <random>

namespace contact_nodes {
class NoSlippageCondition : ConditionTemplate{
public:
	NoSlippageCondition(std::string node_name, std::string bt_name) : ConditionTemplate(bt_name)
  {
      ros::NodeHandle nh("~");

      if (!nh.getParam("fail_threshold", fail_threshold_))
      {
        ROS_WARN("Missing fail_threshold parameter, using default");
        fail_threshold_ = 0.9;
      }
  }

  ~NoSlippageCondition() {}

  bool conditionEvaluation();

private:
  std::default_random_engine generator_;
  double fail_threshold_;
};
}
#endif
