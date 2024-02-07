#include "rclcpp/rclcpp.hpp"
#include "grr_interfaces/srv/get_sum.hpp"

#include <memory>

void add(const std::shared_ptr<grr_interfaces::srv::GetSum::Request> request,
          std::shared_ptr<grr_interfaces::srv::GetSum::Response>      response)
{
  response->sum = request->a + request->b + request->c;

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
                request->a, request->b);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("service_1");

  rclcpp::Service<grr_interfaces::srv::GetSum>::SharedPtr service =
    node->create_service<grr_interfaces::srv::GetSum>("get_sum", &add);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to add two ints.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}