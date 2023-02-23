#include "depth_pose_estimator/DoubleDepthPoseEstimator.hpp"

// *** 생성자 함수 *** //
DoubleDepthPoseEstimator::DoubleDepthPoseEstimator(ros::NodeHandle& node_handle)
{
  parameter_initializer(node_handle);

  // subscriber
  image_subscriber = image_transport::ImageTransport(node_handle).subscribe(depth_color_topic, 1, &DoubleDepthPoseEstimator::image_callback, this);
  depth_subscriber = node_handle.subscribe(depth_registered_topic, 1, &DoubleDepthPoseEstimator::depth_callback, this);

  // publisher
  world_corners_publisher = node_handle.advertise<sensor_msgs::PointCloud2>(depth_world_pointcloud_topic, 1);
  camera_corners_publisher = node_handle.advertise<sensor_msgs::PointCloud2>(depth_camera_pointcloud_topic, 1);

  // image_publisher
  compressed_image_publisher_1 = node_handle.advertise<sensor_msgs::CompressedImage>(depth_image_01, 1);
  compressed_image_publisher_2 = node_handle.advertise<sensor_msgs::CompressedImage>(depth_image_02, 1);

  detector_parameters = cv::aruco::DetectorParameters();
  dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_6X6_250);

  create_world_coordinate_system();

  // 내부 파라미터값 1
  double _intrinsic_parameters[] = {453.7543640, 0.0, 323.54632568, 0.0, 453.7543640, 241.9261780, 0.0, 0.0, 1.0};
  intrinsic_parameters = _intrinsic_parameters;
  double _radial_tangential_distortion[] = {0.0, 0.0, 0.0, 0.0};
  radial_tangential_distortion = _radial_tangential_distortion;

  // 내부 파라미터값 2
  camera_martix = cv::Mat(3, 3, CV_64FC1, intrinsic_parameters);
  distortion_coefficients = cv::Mat(4, 1, CV_64FC1, radial_tangential_distortion);

  // [TEST] cv::namedWindow("DEFAULT");
  // [TEST] cv::namedWindow("FOUND");
}

// *** 소멸자 함수 *** //
DoubleDepthPoseEstimator::~DoubleDepthPoseEstimator()
{
  // [TEST] cv::destroyWindow("DEFAULT");
  // [TEST] cv::destroyWindow("FOUND");
}

// *** ArucoMarker를 찾아내는 함수 *** //
void DoubleDepthPoseEstimator::aruco_marker_detection(cv::Mat& copied_frame)
{
  marker_ids.clear();
  marker_corners.clear();

  cv::Mat frame;
  copied_frame.copyTo(frame);

  cv::aruco::detectMarkers(frame, dictionary, marker_corners, marker_ids);

  if (marker_ids.size() > 0)
  {
    cv::aruco::drawDetectedMarkers(frame, marker_corners, marker_ids);
    // [TEST] cv::imshow("FOUND", frame);

    std::vector<uchar> data;
    sensor_msgs::CompressedImage compressed_image;
    compressed_image.header.stamp = ros::Time::now();
    compressed_image.format = "jpeg";
    cv::imencode(".jpg", frame, data);
    compressed_image.data = data;
    compressed_image_publisher_2.publish(compressed_image);
  }
}

// *** rigid_transformation 함수 *** //
std::tuple<Eigen::Matrix3f, Eigen::Vector3f> DoubleDepthPoseEstimator::rigid_transformation(std::vector<cv::Point3f> corner_information_vector)
{
  Eigen::Matrix<float, 3, Eigen::Dynamic> camera_coordinate_points, world_coordinate_points;
  Eigen::Matrix<float, 3, Eigen::Dynamic> camera_substract_mean, world_substract_mean;

  int corner_information_vector_size = corner_information_vector.size();
  // [TEST] std::cout << corner_information_vector_size << std::endl;

  camera_coordinate_points.resize(3, corner_information_vector_size);
  world_coordinate_points.resize(3, corner_information_vector_size);
  camera_substract_mean.resize(3, corner_information_vector_size);
  world_substract_mean.resize(3, corner_information_vector_size);

  int count = 0;
  for (auto &corner_information : corner_information_vector)
  {
    camera_coordinate_points(0, count) = corner_information.x;
    camera_coordinate_points(1, count) = corner_information.y;
    camera_coordinate_points(2, count) = corner_information.z;
    count++;
  }
  
  count = 0;
  for (auto &object_point : object_points)
  {
    world_coordinate_points(0 ,count) = object_point.x;
    world_coordinate_points(1, count) = object_point.y;
    world_coordinate_points(2, count) = object_point.z;
    count++;
  }

  const Eigen::Vector3f centroid_camera = camera_coordinate_points.rowwise().mean();
  const Eigen::Vector3f centroid_world = world_coordinate_points.rowwise().mean();

  camera_substract_mean = camera_coordinate_points.colwise() - centroid_camera;
  world_substract_mean = world_coordinate_points.colwise() - centroid_world;

  Eigen::Matrix<float, 3, Eigen::Dynamic> H = camera_substract_mean * world_substract_mean.transpose();
  Eigen::JacobiSVD<Eigen::Matrix3Xf> svd = H.jacobiSvd(Eigen::DecompositionOptions::ComputeFullU | Eigen::DecompositionOptions::ComputeFullV);

  const Eigen::Matrix3f& U = svd.matrixU();
  Eigen::MatrixXf V = svd.matrixV();
  Eigen::Matrix3f R = V * U.transpose();

  if (R.determinant() < 0.0f)
	{
		V.col(2) *= -1.0f;
		R = V * U.transpose();
	}

  const Eigen::Vector3f t = -R * centroid_camera + centroid_world;

  return std::make_tuple(R, t);
}

// *** 체크보드의 월드좌표계를 저장하는 함수 *** //
void DoubleDepthPoseEstimator::create_world_coordinate_system()
{
  object_points.clear();

  // for (int i = 0; i < chessboard_dimensions.height; i++)
  // {
  //   for (int j = 0; j < chessboard_dimensions.width; j++)
  //   {
  //     cv::Point3f corner(1.36f, 0.35f - j * (chessboard_edge_size), 0.6f - i * (chessboard_edge_size));
  //     pcl::PointXYZ corner_point(corner.x, corner.y, corner.z);
  //     object_points.push_back(corner);
  //     world_corners_messages.push_back(corner_point);
  //   }
  // }
}

// *** 인코딩 방식을 상수화하는 함수 *** //
int DoubleDepthPoseEstimator::encoding_mat_type(const std::string & encoding)
{
  if (encoding == "mono8")
  {
    return CV_8UC1;
  }
  else if (encoding == "bgr8")
  {
    return CV_8UC3;
  }
  else if (encoding == "mono16")
  {
    return CV_16SC1;
  }
  else if (encoding == "rgba8")
  {
    return CV_8UC4;
  }
  else if (encoding == "bgra8")
  {
    return CV_8UC4;
  }
  else if (encoding == "32FC1")
  {
    return CV_32FC1;
  }
  else if (encoding == "rgb8")
  {
    return CV_8UC3;   // color의 image_raw 인코딩 형식
  }
  else if (encoding == "16UC1")
  {
    return CV_16UC1;  // depth의 image_raw 인코딩 형식
  }
  else {
    throw std::runtime_error("Unsupported encoding type");
  }
}

// *** sensor_msgs::PointCloud2에서 pcl::PointCloud<pcl::PointXYZ>로 변환하는 함수 *** //
pcl::PointCloud<pcl::PointXYZ> DoubleDepthPoseEstimator::sensor_to_pcl(sensor_msgs::PointCloud2 sensor_messages)
{
  pcl::PointCloud<pcl::PointXYZ> pcl_messages;
  pcl::fromROSMsg(sensor_messages, pcl_messages);
  return pcl_messages;
}

// *** pcl::PointCloud<pcl::PointXYZ>에서 sensor_msgs::PointCloud2로 변환하는 함수 *** //
sensor_msgs::PointCloud2 DoubleDepthPoseEstimator::pcl_to_sensor(pcl::PointCloud<pcl::PointXYZ> pcl_messages)
{
  sensor_msgs::PointCloud2 sensor_messages;
  pcl::toROSMsg(pcl_messages, sensor_messages);
  sensor_messages.header.frame_id = "base_link";
  return sensor_messages;
}

void DoubleDepthPoseEstimator::parameter_initializer(ros::NodeHandle& node_handle)
{
  // 카메라 방향 설정(left: 1, right: 2)
  node_handle.getParam("/depth_pose_estimator/DEPTH_DIRECTION", depth_direction);

  // 초당 프레임
  node_handle.getParam("/depth_pose_estimator/FRAMES_PER_SECONDS", frames_per_seconds);

  // aruco marker 관련 변수
  node_handle.getParam("/depth_pose_estimator/ARUCO_EDGE_SIZE", aruco_edge_size);
  node_handle.getParam("/depth_pose_estimator/ARUCO_GAP_SIZE", aruco_gap_size);

  // topic 관련 변수
  node_handle.getParam("/depth_pose_estimator/DEPTH_COLOR_TOPIC", depth_color_topic);
  node_handle.getParam("/depth_pose_estimator/DEPTH_REGISTERED_TOPIC", depth_registered_topic);
  node_handle.getParam("/depth_pose_estimator/DEPTH_TF_TOPIC", depth_tf);

  // 이미지 관련 변수
  node_handle.getParam("/depth_pose_estimator/DEPTH_IMAGE_01_TOPIC", depth_image_01);
  node_handle.getParam("/depth_pose_estimator/DEPTH_IMAGE_02_TOPIC", depth_image_02);

  // 포인트클라우드 관련 변수
  node_handle.getParam("/depth_pose_estimator/DEPTH_CAMERA_POINTCLOUD_TOPIC", depth_camera_pointcloud_topic);
  node_handle.getParam("/depth_pose_estimator/DEPTH_WORLD_POINTCLOUD_TOPIC", depth_world_pointcloud_topic);
}