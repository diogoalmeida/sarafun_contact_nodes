#!/usr/bin/env python
import rospy
import actionlib
from sarafun_msgs.msg import PickUpKeyframeAction, ContactKeyframeAction

class ContactServer:
    """Dummy contact implementation. Will wait a pre-defined amount of time to
    succeed."""
    def __init__(self):
        self.server = actionlib.SimpleActionServer("contact_server", ContactKeyframeAction, self.execute, False)
        self.action_time = 3.0
        self.server.start()

    def execute(self, goal):
        rospy.loginfo("Contact server received a goal")
        init_time = rospy.Time.now()

        while (rospy.Time.now() - init_time).to_sec() < self.action_time:
            if self.server.is_preempt_requested():
                rospy.logwarn("Contact server preempted")
                self.server.set_preempted()
                return

            rospy.sleep(0.1)

        rospy.loginfo("Contact server succeeded")
        self.server.set_succeeded()

if __name__ == "__main__":
    rospy.init_node("contact_server")
    server = ContactServer()
    rospy.loginfo("Contact server initialized")
    rospy.spin()
