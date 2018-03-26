#include <contact_nodes/no_slippage_condition.hpp>

namespace contact_nodes {

bool NoSlippageCondition::conditionEvaluation() {
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
  ros::init(argc, argv, "NoSlippageCondition");
  contact_nodes::NoSlippageCondition condition(ros::this_node::getName(),
							  "NoSlippageCondition");
  ros::spin();
  return 1;
}
