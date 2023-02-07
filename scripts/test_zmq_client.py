"""
an example code from https://zeromq.org/languages/python/
"""

import zmq

context = zmq.Context()

#  Socket to talk to server
print("Connecting to hello world server…")
socket = context.socket(zmq.REQ)
#set server ip address and port info
socket.connect("tcp://localhost:7777")

#send some message
socket.send(b"Hi AIRLab")
message = socket.recv()
#print("Received reply %s" % (message))
print(message.decode('utf-8'))