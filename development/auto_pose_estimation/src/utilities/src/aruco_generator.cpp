#include "ros/ros.h"
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/aruco.hpp"

static inline void aruco_generator(int width = 4, int height = 5, float marker_size = 0.1f, float marker_seperation_size = 0.1f)
{
  cv::Ptr<cv::aruco::Dictionary> dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);
  cv::Ptr<cv::aruco::GridBoard> board = cv::aruco::GridBoard::create(width, height, marker_size, marker_seperation_size, dictionary);
  cv::Mat arucoboard;
  board->draw(cv::Size(841, 1189), arucoboard, 10, 1);
  cv::imwrite("arucoboard.jpg", arucoboard);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "aruco_generator");
  ros::NodeHandle node_handle;

  aruco_generator();

  return 0;
}