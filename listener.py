#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def callback(data):
    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
    
def listener():

    # Anonymous creates this node with a unique name 
    rospy.init_node('listener', anonymous=True)

    # subscribe to the slimshady channel
    rospy.Subscriber("slimshady", String, callback)

    # spin() simply keeps python from exiting until this node is stopped
    rospy.spin()

if __name__ == '__main__':
    listener()