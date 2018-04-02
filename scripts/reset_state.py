#!/usr/bin/env python
import rospy
import actionlib
from contact_nodes.msg import ResetKeyframeAction

class ResetServer:
    """Resets the behavior tree relevant state."""
    def __init__(self):
        self.server = actionlib.SimpleActionServer("reset_state", ResetKeyframeAction, self.execute, False)
        self.server.start()

    def execute(self, goal):
        rospy.loginfo("Reset state server received a goal")
        rospy.set_param("/pick/succeeded", False)
        rospy.set_param("/contact/success", False)
        self.server.set_succeeded()

if __name__ == "__main__":
    rospy.init_node("reset_server")
    server = ResetServer()
    rospy.loginfo("Reset server initialized")
    rospy.spin()
