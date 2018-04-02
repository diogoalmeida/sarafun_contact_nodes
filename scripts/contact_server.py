#!/usr/bin/env python
import rospy
import actionlib
from sarafun_msgs.msg import PickUpKeyframeAction, ContactKeyframeAction
from std_srvs.srv import Empty, EmptyResponse

class ContactServer:
    """Dummy contact implementation. Will wait a pre-defined amount of time to
    succeed."""
    def __init__(self):
        self.server = actionlib.SimpleActionServer("contact_server", ContactKeyframeAction, self.execute, False)
        self.action_time = 10.0
        self.teach_mode = False
        self.toggle_server = rospy.Service('/contact/toggle_teach', Empty, self.toggle_teach_mode)
        rospy.set_param("/contact/success", False)
        self.server.start()


    def toggle_teach_mode(self, req):
        rospy.loginfo("Toggling teach")
        self.teach_mode = not self.teach_mode
        return EmptyResponse()

    def execute(self, goal):
        rospy.loginfo("Contact server received a goal")
        init_time = rospy.Time.now()

        while (rospy.Time.now() - init_time).to_sec() < self.action_time:
            if self.server.is_preempt_requested():
                rospy.logwarn("Contact server preempted")
                self.server.set_preempted()
                return

            rospy.loginfo_throttle(1, "Running contact")
            rospy.sleep(0.1)

        if self.teach_mode:
            rospy.logwarn("Contact server in teach mode")
            self.server.set_aborted()
        else:
            rospy.loginfo("Contact server succeeded")
            rospy.set_param("/contact/success", True)
            self.server.set_succeeded()

if __name__ == "__main__":
    rospy.init_node("contact_server")
    server = ContactServer()
    rospy.loginfo("Contact server initialized")
    rospy.spin()
