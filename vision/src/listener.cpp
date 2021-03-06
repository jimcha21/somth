#include "ros/ros.h"
#include "std_msgs/String.h"
#include "sensor_msgs/Image.h"
#include <ctype.h>
#include <stdio.h>
#include <iostream>
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/core/core.hpp"
#include <opencv2/xfeatures2d/nonfree.hpp>
#include "vision/ChessVector.h"


using namespace cv;
/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const vision::ChessVector& msg)
{
  //ROS_INFO("I heard: [%s]", msg->data.c_str());
  //ROS_INFO("frame received: ROWS[%d]xCOLUMNS[%d]", msg->width,msg->height);
  ROS_INFO("KATI PHRE");
  ROS_INFO("phre %d",msg.p_vector.size());
  for(int i;i<msg.p_vector.size();i++){
    ROS_INFO("phre %d %d",msg.p_vector[i].x,msg.p_vector[i].y);


  } 
  //ROS_INFO("phre %d %d",msg.p_vector[0].x,msg.p_vector[0].y);ROS_INFO("phre %d %d",msg.p_vector[1].x,msg.p_vector[1].y);
 // ROS_INFO("phre %d",msg.size());
  //CvImagePtr toCvCopy(msg->data,msg->encoding);

  //ROS_INFO("encoding received: [%s]", msg->encoding.c_str()); //rgb8
  //ROS_INFO("bigendian BOOL received: [%d]", msg->is_bigendian); //0
  //ROS_INFO("step received: [%d]", msg->step); //960
  //ROS_INFO("data received: [%d] with size [%d]",msg->data,sizeof(msg->data[0])); //rgb8
  //ROS_INFO("kai ena stoixeio [%d]",msg->data[230502]);
// Create a Size(1, nSize) Mat object of 8-bit, single-byte elements
  //Mat rawData  =  Mat( 1, 100000, CV_8UC1, msg->data );

  //Mat decodedImage  =  imdecode( rawData /*, flags */ );
  //if ( decodedImage.data == NULL )   
  //{
      // Error reading raw image data
  //}

  //cv::Mat test = cv::Mat(240, 320, CV_8UC1);
  //cv::imdecode  (   msg->data,  cv::IMREAD_UNCHANGED ,   test  )  ; 

  //test>>(msg->data);
  //cv::Mat image= imread(msg->data);
  //imshow("nao", image);
  //ROS_INFO("KATI AKOUSA");
}

int main(int argc, char **argv)
{
  /**
   * The ros::init() function needs to see argc and argv so that it can perform
   * any ROS arguments and name remapping that were provided at the command line.
   * For programmatic remappings you can use a different version of init() which takes
   * remappings directly, but for most command-line programs, passing argc and argv is
   * the easiest way to do it.  The third argument to init() is the name of the node.
   *
   * You must call one of the versions of ros::init() before using any other
   * part of the ROS system.
   */
  ros::init(argc, argv, "listener");
  //namedWindow( "nao", 0 );
  /**
   * NodeHandle is the main access point to communications with the ROS system.
   * The first NodeHandle constructed will fully initialize this node, and the last
   * NodeHandle destructed will close down the node.
   */
  ros::NodeHandle n;
  ROS_INFO("now running ");

  /**
   * The subscribe() call is how you tell ROS that you want to receive messages
   * on a given topic.  This invokes a call to the ROS
   * master node, which keeps a registry of who is publishing and who
   * is subscribing.  Messages are passed to a callback function, here
   * called chatterCallback.  subscribe() returns a Subscriber object that you
   * must hold on to until you want to unsubscribe.  When all copies of the Subscriber
   * object go out of scope, this callback will automatically be unsubscribed from
   * this topic.
   *
   * The second parameter to the subscribe() function is the size of the message
   * queue.  If messages are arriving faster than they are being processed, this
   * is the number of messages that will be buffered up before beginning to throw
   * away the oldest ones.
   */
  //ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  ros::Subscriber sub = n.subscribe("chess_points", 10, chatterCallback);
  /**
   * ros::spin() will enter a loop, pumping callbacks.  With this version, all
   * callbacks will be called from within this thread (the main one).  ros::spin()
   * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
   */
  ros::spin();

  return 0;
}
