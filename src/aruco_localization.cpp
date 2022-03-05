#include "aruco_localization.hpp"

using std::placeholders::_1;

ArucoLocalization::ArucoLocalization() : rclcpp::Node(kArucoLocalizationNodeName) {
  const auto qos = rclcpp::QoS(
          rclcpp::QoSInitialization::from_rmw(rmw_qos_profile_sensor_data),
          rmw_qos_profile_sensor_data);
          
  subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
    kImageRawTopic, qos, std::bind(&ArucoLocalization::HandleImage, this, _1)
  );
}

void ArucoLocalization::HandleImage(sensor_msgs::msg::Image::ConstSharedPtr msg) {
  RCLCPP_INFO(this->get_logger(),"HandleImage(msg) called");
  // auto cv_image = cv_bridge::toCvShare(msg);
  
  // cv::aruco::detectMarkers(cv_image->image, dictionary, markerCorners, markerIds, parameters, rejectedCandidates);

  // RCLCPP_INFO(this->get_logger(), "found markers : %d", markerIds.size());
  // cv::Mat outputImage = cv_image->image.clone();
  // cv::aruco::drawDetectedMarkers(outputImage, markerCorners, markerIds);
  // cv::imwrite("/ws/image_with_detected_markers.png", outputImage);
  // cv_bridge::CvImage cv_image()
}

// class SimpleSubscriber : public rclcpp::Node
// {
//   const std::string ImageRawTopic = "/camera/color/image_raw";

  // public:
  //   SimpleSubscriber()
  //   : Node("simple_subscriber")
  //   {
      
  //   }

//   private:
//     void ShowImage(const sensor_msgs::msg::CameraInfo& msg) const
//     {
//       RCLCPP_INFO(this->get_logger(), "got height = %d, width = %d", msg.height, msg.width);
//     }
//     rclcpp::Subscription<sensor_msgs::msg::CameraInfo>::SharedPtr subscription_;
// };

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto aruco_localization = std::make_shared<ArucoLocalization>();
  RCLCPP_INFO(aruco_localization->get_logger(), "init() finished");
  rclcpp::spin(aruco_localization);
  rclcpp::shutdown();
  return 0;
}
