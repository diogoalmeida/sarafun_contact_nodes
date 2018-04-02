#ifndef __GOT_CONTACT_CONDITION__
#define __GOT_CONTACT_CONDITION__

#include <ros/ros.h>
#include <behavior_tree_leaves/ConditionTemplate.h>

namespace contact_nodes {
class GotContactCondition : ConditionTemplate{
public:
	GotContactCondition(std::string node_name, std::string bt_name) : ConditionTemplate(bt_name)
	{
		nh_ = ros::NodeHandle("~");
	}

  ~GotContactCondition() {}

  bool conditionEvaluation();
private:
	ros::NodeHandle nh_;
};
}
#endif
