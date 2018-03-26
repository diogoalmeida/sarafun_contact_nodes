#include <contact_nodes/got_contact_condition.hpp>

namespace contact_nodes {

bool GotContactCondition::conditionEvaluation() {
  	return true;
}
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "GotContactCondition");
  contact_nodes::GotContactCondition condition(ros::this_node::getName(),
							  "GotContactCondition");
  ros::spin();
  return 1;
}
