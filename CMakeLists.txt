cmake_minimum_required(VERSION 2.8.3)
project(imu_estimator)


## Find catkin and any catkin packages
find_package(catkin REQUIRED COMPONENTS 
  roscpp 
  rospy 
  std_msgs 
  genmsg
  )

find_package(OpenCV REQUIRED)

find_package(Eigen3 REQUIRED)


catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}
)

add_executable(imu_estimator src/estimator_node.cpp)

target_link_libraries(imu_estimator ${catkin_LIBRARIES} ${OpenCV_LIBS} )

add_dependencies(imu_estimator imu_estimator_generate_message_cpp)
