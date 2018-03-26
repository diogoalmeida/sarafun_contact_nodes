cmake_minimum_required(VERSION 2.8.3)
project(contact_nodes)

find_package(catkin REQUIRED COMPONENTS
  rospy
  actionlib_msgs
  actionlib
  sarafun_msgs
  behavior_tree_leaves
)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")

link_directories(${catkin_LIBRARY_DIRS})

catkin_package(
  CATKIN_DEPENDS actionlib_msgs rospy actionlib sarafun_msgs behavior_tree_leaves
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(got_contact_condition src/contact_nodes/got_contact_condition.cpp)
target_link_libraries(got_contact_condition ${catkin_LIBRARIES})

add_executable(has_grasp_condition src/contact_nodes/has_grasp_condition.cpp)
target_link_libraries(has_grasp_condition ${catkin_LIBRARIES})

add_executable(no_slippage_condition src/contact_nodes/no_slippage_condition.cpp)
target_link_libraries(no_slippage_condition ${catkin_LIBRARIES})
