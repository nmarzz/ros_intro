#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

/**
 *  We gonna send some messages
 * 
 *  An adapted code from the http://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28c%2B%2B%29
 *  ros cpp tutorial 
 * 
 * 
 */
int main(int argc, char **argv)
{
  /**   
   *
   * Need to call ros::inti before using another aspect of ROS. 
   * 
   * This node is named 'talker'
   */
  ros::init(argc, argv, "talker");

  
  ros::NodeHandle n;

  /**
   * Call advertise to signal our desire to publish
   */
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("slimshady", 100);

  ros::Rate loop_rate(1); // publish at 1 hz

  /**
   * ros::ok allows us to SIGINT the program
   */
  int count = 0;
  while (ros::ok())
  {
    /**
     * init a message
     */
    std_msgs::String msg;

    std::stringstream ss;
    ss << "I am standing up:" << count;
    msg.data = ss.str();

    ROS_INFO("%s", msg.data.c_str());

    /**
     * Now send it
     */
    chatter_pub.publish(msg);

    ros::spinOnce(); // not strictly needed


    loop_rate.sleep();
    ++count;
  }


  return 0;
}
