#!/usr/bin/env python
import rospy
import actionlib
from sarafun_msgs.msg import PickUpKeyframeAction, ContactKeyframeAction

class PickServer:
    """Dummy pick implementation. Will wait a pre-defined amount of time to
    succeed."""
    def __init__(self):
        self.server = actionlib.SimpleActionServer("pick_server", PickUpKeyframeAction, self.execute, False)
        self.action_time = 10.0
        rospy.set_param("/pick/succeeded", False)
        self.server.start()

    def execute(self, goal):
        rospy.loginfo("Pick server received a goal")
        rospy.set_param("/pick/succeeded", False)
        init_time = rospy.Time.now()

        while (rospy.Time.now() - init_time).to_sec() < self.action_time:
            if self.server.is_preempt_requested():
                rospy.logwarn("Pick server preempted")
                rospy.set_param("/pick/succeeded", False)
                self.server.set_preempted()
                return

            rospy.loginfo_throttle(1, "Running pick")
            rospy.sleep(0.1)

        rospy.loginfo("Pick server succeeded")
        rospy.set_param("/pick/succeeded", True)
        self.server.set_succeeded()

if __name__ == "__main__":
    rospy.init_node("pick_server")
    server = PickServer()
    rospy.loginfo("Pick server initialized")
    rospy.spin()
