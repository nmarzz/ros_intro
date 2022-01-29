cmake_minimum_required(VERSION 3.0.2)
project(beginner_tutorials)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
)


catkin_package()



include_directories(include ${catkin_INCLUDE_DIRS})


add_executable(talker talker.cpp)
target_link_libraries(talker ${catkin_LIBRARIES})
add_dependencies(talker beginner_tutorials_generate_messages_cpp)

catkin_install_python(PROGRAMS listener.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)
