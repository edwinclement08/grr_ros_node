#include "rclcpp/rclcpp.hpp"
#include "grr_interfaces/srv/get_sum.hpp"
#include "grr_interfaces/srv/solve_for_point.hpp"

#include <iostream>
#include <ompl/datastructures/NearestNeighborsGNAT.h>
#include <boost/lambda/lambda.hpp>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <utility>

#include "boost/tuple/tuple.hpp"

#include <memory>

using namespace std;

typedef tuple<double, double, double, double, double> JointConfig;

double distance2(const int &a, const int& b) {
    return static_cast<double>(abs(a - b));
}

// void add(const std::shared_ptr<grr_interfaces::srv::GetSum::Request> request,
//           std::shared_ptr<grr_interfaces::srv::GetSum::Response>      response)
// {
//   response->sum = request->a + request->b + request->c;

//   RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %ld" " b: %ld",
//                 request->a, request->b);
//   RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
// }

void solve(const std::shared_ptr<grr_interfaces::srv::SolveForPoint::Request> request,
          std::shared_ptr<grr_interfaces::srv::SolveForPoint::Response>      response)
{
  response->new_joint_config = {1.0, 2.0, 3.0, 4.0, 5.0};

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "(solver)Incoming request");
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back dummy response"); 
}


int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("grr_solver_server");

  rclcpp::Service<grr_interfaces::srv::SolveForPoint>::SharedPtr service2 =
    node->create_service<grr_interfaces::srv::SolveForPoint>("/grr_solver_server/redundancy_solver", &solve);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to solve for redundancy.");

  ompl::NearestNeighborsGNAT<int> nn;

    nn.add(1);
    nn.add(121);
    nn.add(31);
    nn.add(10000);
    nn.add(1565);

    nn.setDistanceFunction(&distance2);

    std::cout << "Hello, World!" << std::endl;
    int n = 3900;
    int nearest = nn.nearest(n);
    cout << "Nearest neighbour of " << n << " is " << nearest << endl;

  rclcpp::spin(node);
  rclcpp::shutdown();
}