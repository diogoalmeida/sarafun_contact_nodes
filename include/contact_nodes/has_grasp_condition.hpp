#ifndef __HAS_GRASP_CONDITION__
#define __HAS_GRASP_CONDITION__

#include <ros/ros.h>
#include <behavior_tree_leaves/ConditionTemplate.h>
#include <random>

namespace contact_nodes {
class HasGraspCondition : ConditionTemplate{
public:
	HasGraspCondition(std::string node_name, std::string bt_name) : ConditionTemplate(bt_name)
  {
      nh_ = ros::NodeHandle("~");

      if (!nh_.getParam("fail_threshold", fail_threshold_))
      {
        ROS_WARN("Missing fail_threshold parameter, using default");
        fail_threshold_ = 0.75;
      }
  }

  ~HasGraspCondition() {}

  bool conditionEvaluation();

private:
  std::default_random_engine generator_;
	ros::NodeHandle nh_;
  double fail_threshold_;
};
}
#endif
