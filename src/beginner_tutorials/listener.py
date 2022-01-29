#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "Q: Will the real slim shady please stand up? ---- A: %s", data.data)
    
def listener():

    # Anonymous creates this node with a unique name 
    rospy.init_node('listener', anonymous=True)

    # subscribe to the chatter channel
    rospy.Subscriber("slimshady", String, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()
