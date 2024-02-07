# Setup

```bash
git clone --recurse-submodules https://github.com/edwinclement08/grr_ros_node
```

# Running

```bash
source ./install/setup.bash
colcon build
ros2 run grr_solver server  
```

# ROS Service Details

Details of Service Call [Service Parameters](./src/grr_interfaces/srv/SolveForPoint.srv)

Topic Name of service: `/grr_solver_server/redundancy_solver`