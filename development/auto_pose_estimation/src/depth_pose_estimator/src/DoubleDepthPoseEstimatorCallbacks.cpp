#include "depth_pose_estimator/DoubleDepthPoseEstimator.hpp"

void DoubleDepthPoseEstimator::image_callback(const sensor_msgs::Image::ConstPtr& image_messages)
{
  cv::Mat frame(
    image_messages->height - 80,  // 480px - 80px
    image_messages->width,        // 640px
    encoding_mat_type(image_messages->encoding),
    const_cast<unsigned char*>(image_messages->data.data()),
    image_messages->step
  );

  cv::Mat copied_frame;
  if (image_messages->encoding == "rgb8")
  {
    cv::Mat temporary_frame;
    cv::cvtColor(frame, temporary_frame, cv::COLOR_RGB2BGR);
    copied_frame = temporary_frame;
  }
  else
  {
    copied_frame = frame;
  }

  std::vector<uchar> data;
  sensor_msgs::CompressedImage compressed_image;
  compressed_image.header.stamp = ros::Time::now();
  compressed_image.format = "jpeg";
  cv::imencode(".jpg", copied_frame, data);
  compressed_image.data = data;
  compressed_image_publisher_1.publish(compressed_image);

  // [TEST]
  cv::imshow("DEFAULT", copied_frame);

  aruco_marker_detection(copied_frame);

  world_corners_publisher.publish(pcl_to_sensor(world_corners_messages));
  cv::waitKey(1000/frames_per_seconds);
}

void DoubleDepthPoseEstimator::depth_callback(const sensor_msgs::PointCloud2::ConstPtr& depth_messages)
{
    // YET
}