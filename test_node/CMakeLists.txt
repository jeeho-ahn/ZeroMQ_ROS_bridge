set(sub_name "test_zmq_server_node")

add_executable(${sub_name} src/test_zmq_server_node.cpp src/color_print.cpp)

target_link_libraries(${sub_name} ${catkin_LIBRARIES} ${ZeroMQ_LIBRARIES})

install(TARGETS ${sub_name} DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
install(DIRECTORY launch DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})