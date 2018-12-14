<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/da/Bluetooth.svg/393px-Bluetooth.svg.png" alt="Bluetooth_Logo" height="42px" width="42px" align="left">

# Qt Bluetooth Sniffer Tool
<div>
    <a href="https://github.com/NaPiZip/Docker_GUI_Apps_on_Windows">
        <img src="https://img.shields.io/badge/Document%20Version-1.0.0-brightgreen.svg"/>
    </a>
    <a href="https://www.qt.io/download">
        <img src="https://img.shields.io/badge/Qt-5.10.1-blue.svg"/>
    </a>
    <a href="https://www.microsoft.com">
        <img src="https://img.shields.io/badge/Windows%2010%20x64-10.0.17134%20Build%2017134-blue.svg"/>
    </a>
    <a href="https://docs.microsoft.com/en-us/visualstudio/releasenotes/vs2015-version-history">
        <img src="https://img.shields.io/badge/MS%20Visual%20C%2B%2B-14.0%20(amd64__x86)-blue.svg"/>
    </a>
</div>

## Objectives
This is an example of a simple Qt application for Windows 10 which is capable of monitoring nearby Bluetooth devices as well as logging the traffic.

I am creating this application in order to practice the following topics:<br>
- Graphical user interfaces (GUI) design with Qt 5.10+
- C++ development with focus on object oriented programming (OOP)
- Multithreaded applications
- Bluetooth protocol and communication

## Introduction
This section covers basic content about the Bluetooth protocol in general, the usage of the [Windows Sockets 2.2](https://docs.microsoft.com/en-us/windows/desktop/bluetooth/bluetooth-start-page) API from Windows, in particular for Bluetooth devices. Windows sockets are used in order to establish Bluetooth connections to devices and to get service information's.

### The Bluetooth Protocol
Create quick summary of [An Introduction to Bluetooth Programming](https://people.csail.mit.edu/albert/bluez-intro/). The introduction provides all necessary information about the Bluetooth protocol.
<image src="https://raw.githubusercontent.com/NaPiZip/Qt-Applications-for-Windows-10/master/Bluetooth_sniffer_tool/images/bluetooth_stack.JPG" class="center"/>

### Windows Sockets 2
[Winsock 2](https://docs.microsoft.com/en-us/windows/desktop/WinSock/windows-sockets-2-architecture-2) defines a standard service provider interface (SPI) between the application programming interface (API), with its functions exported from WS2_32.dll and the protocol stacks. Consequently, Winsock support is not limited to TCP/IP protocol stacks as is the case for Windows Sockets 1.1.

<image src="https://raw.githubusercontent.com/NaPiZip/Qt-Applications-for-Windows-10/master/Bluetooth_sniffer_tool/images/winsocket_overview.png" class="center"/><br>

There are two types of socket applications, server and client. The server is waiting and listening for incoming requests issued by the client, in order to perform the requested action. The client on the other hand, is the initiator of a request, he is inquiring some kind of information / asking to perform a particular action.

**What is a socket?**<br>
A socket is commonly know as a handle to a connection. If a client wants to connect to a known server, it needs to create a receiver socket in order to establish a connection. Two common types of sockets exist:
1.  Streaming socket a.k.a SOCK_STREAM.<br>
    Is a reliable connection often used for continuous streams of data. The used protocol is [TCP](https://en.wikipedia.org/wiki/Transmission_Control_Protocol).
2.  Datagram socket a.k.a SOCK_DGRAM.<br>
    Is a so called "connectionless" data transfer without a send and receive handshake. The used protocol is [UDP](https://en.wikipedia.org/wiki/User_Datagram_Protocol).

**What is binding a socket?**<br>
Binding is the process of associating an IP address and a port number to a socket. In order to establish a connect between a client and a server, the client as well as the server both need to have a bounded socket to build up a connection.

**What is a connection?**<br>
A connection is a data link between two bounded sockets. The client initiates the connection, where as the server is listening on a defined socket. It is not explicitly needed to create a client socket before connecting to a server, since the Winsock connect function is able to bind a socket to the client before establishing a connection, more details can be found at [madwizard](http://www.madwizard.org/programming/tutorials/netcpp/3).

**Server & client application**<br>
The following steps describe the procedure to create a server and a client application using Winsock 2:

Server
1.  Initialize Winsock.
2.  Create a socket.
3.  Bind the socket.
4.  Listen on the socket for a client.
5.  Accept a connection from a client.
6.  Receive and send data.
7.  Disconnect.

Client
1.  Initialize Winsock.
2.  Create a socket.
3.  Connect to the server.
4.  Send and receive data.
5.  Disconnect.

Sample code for a server as well as a client connection can be found [here](https://docs.microsoft.com/en-us/windows/desktop/WinSock/finished-server-and-client-code).

### Windows Sockets for Bluetooth Devices
Create quick summary of [Winsock 2.2](https://docs.microsoft.com/en-us/windows/desktop/WinSock/windows-sockets-start-page-2). Explanation about:
- How to initialize the WSA service
- How to scann for devices
- How to connect
- How to properly terminate the connection


## Architecture of the final Application




## Contributing

To get started with contributing to me GitHub repository, please contact me [Slack](https://join.slack.com/t/napi-friends/shared_invite/enQtNDg3OTg5NDc1NzUxLWU1MWNhNmY3ZTVmY2FkMDM1ODg1MWNlMDIyYTk1OTg4OThhYzgyNDc3ZmE5NzM1ZTM2ZDQwZGI0ZjU2M2JlNDU).
