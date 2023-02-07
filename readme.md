# ZeroMQ ROS Bridge Demo

This ROS package is a demonstration of bridging [ZeroMQ](http://zeromq.org) commnuication to ROS communication. 

## How to setup

1. Clone this repository into ros src folder.
2. Build with ``catkin_make``
   ```
   cd ~/catkin_ws
   catkin_make
   ```

## How to use

1. Run `roscore`
   ```
   roscore
   ```
2. Run test ROS node.
   ```
   rosrun zmq_bridge test_zmq_server_node
   ```
3. Run test python client code.
   ```
   roscd zmq_bridge/scripts
   python test_zmq_client.py
   ```