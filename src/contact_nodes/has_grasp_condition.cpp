#include <contact_nodes/has_grasp_condition.hpp>

namespace contact_nodes {

bool HasGraspCondition::conditionEvaluation() {
    std::uniform_real_distribution<double> distribution(0.0,1.0);
    bool grasped;
    if (!nh_.getParam("/pick/succeeded", grasped))
    {
      ROS_ERROR("Missing /pick/succeeded parameter");
      grasped = false;
    }

    double draw = distribution(generator_);

    if (grasped)
    {
      if (draw > fail_threshold_)
      {
        ROS_WARN("Lost grasp!");
        return false;
      }

      return true;
    }

    return false;
}
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "HasGraspCondition");
  contact_nodes::HasGraspCondition condition(ros::this_node::getName(),
							  "HasGraspCondition");
  ros::spin();
  return 1;
}
