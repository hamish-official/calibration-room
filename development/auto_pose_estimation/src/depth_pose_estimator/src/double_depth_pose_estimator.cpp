#include "depth_pose_estimator/DoubleDepthPoseEstimator.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "doube_depth_pose_estimator");
  ros::NodeHandle node_handle;

  DoubleDepthPoseEstimator double_depth_pose_estimator = DoubleDepthPoseEstimator(node_handle);

  return 0;
}