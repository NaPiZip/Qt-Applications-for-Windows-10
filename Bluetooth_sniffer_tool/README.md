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

### Windows Sockets 2
Create quick summary of [Winsock 2.2](https://docs.microsoft.com/en-us/windows/desktop/WinSock/windows-sockets-start-page-2). This should explain the background of Windows sockets and how to utilize them.

### Windows Sockets for Bluetooth Devices
Create quick summary of [Winsock 2.2](https://docs.microsoft.com/en-us/windows/desktop/WinSock/windows-sockets-start-page-2). Explanation about:
- How to initialize the WSA service
- How to scann for devices
- How to connect
- How to properly terminate the connection


## Architecture of the final Application




## Contributing

To get started with contributing to me GitHub repository, please contact me [Slack](https://join.slack.com/t/napi-friends/shared_invite/enQtNDg3OTg5NDc1NzUxLWU1MWNhNmY3ZTVmY2FkMDM1ODg1MWNlMDIyYTk1OTg4OThhYzgyNDc3ZmE5NzM1ZTM2ZDQwZGI0ZjU2M2JlNDU).
