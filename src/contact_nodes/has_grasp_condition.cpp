#include <contact_nodes/has_grasp_condition.hpp>

namespace contact_nodes {

bool HasGraspCondition::conditionEvaluation() {
    std::uniform_real_distribution<double> distribution(0.0,1.0);

    double draw = distribution(generator_);

    if (draw > fail_threshold_)
    {
      return false;
    }

    return true;
}
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "HasGraspCondition");
  contact_nodes::HasGraspCondition condition(ros::this_node::getName(),
							  "HasGraspCondition");
  ros::spin();
  return 1;
}
