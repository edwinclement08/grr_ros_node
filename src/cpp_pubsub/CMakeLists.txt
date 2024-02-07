cmake_minimum_required(VERSION 3.5)
project(cpp_pubsub)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(grr_interfaces REQUIRED)
find_package(std_msgs REQUIRED)

find_package(ompl REQUIRED)
find_package(Boost 1.66 COMPONENTS program_options REQUIRED)


include_directories(
        /usr/include/eigen3
        ${OMPL_INCLUDE_DIRS}
)

# SET(KLAMPT_ROOT ${native_grr_SOURCE_DIR}/Klampt)
# SET (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${KLAMPT_ROOT}/CMakeModules")
# FIND_PACKAGE(Klampt REQUIRED)
# ADD_DEFINITIONS(${KLAMPT_DEFINITIONS})
# INCLUDE_DIRECTORIES(${KLAMPT_INCLUDE_DIRS})


# add_executable(talker src/publisher_member_function.cpp)
# ament_target_dependencies(talker rclcpp std_msgs)
add_executable(server src/service.cpp)
ament_target_dependencies(server rclcpp grr_interfaces)

target_link_libraries(server
        ${OMPL_LIBRARIES}
        Boost::program_options
)


# install(TARGET
#   talker
#   DESTINATION lib/${PROJECT_NAME})

install(TARGETS
    server
  DESTINATION lib/${PROJECT_NAME})


ament_package()