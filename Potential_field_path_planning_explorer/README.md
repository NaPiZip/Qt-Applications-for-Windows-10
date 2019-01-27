<img src="http://www.jeffdelmerico.com/wp-content/uploads/2015/05/kitchen_world_perc_3_2.png" alt="Path planning" height="42px" width="42px" align="left">

# Potential Field Path Planning Visualization
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
This is an example of a simple Qt application for Windows 10 which is shows the `Potential Field Method for path planning` which is based on the following [paper](https://www.business-sweden.se/contentassets/fcac981bfd224e609363bc7fc56889f3/discover-autonomous-driving-potential-in-japan.pdf).

I am creating this application in order to practice the following topics:<br>
- Graphical user interfaces (GUI) design with Qt 5.10+.
- Using different chart types for creation of quick visualizations in Qt.
- C++ development with focus on object oriented programming (OOP).

## Requirements
The application should provide an interactive interface for the user to visualize the potential field method for path planning. The application should show a 3D representation of the force field, as well as the potential field of a scenario. A scenario consists of a `Host Vehicle` and up to 20 `Obstacles`. The representation should show the `Host Vehicle` path around the obstacles and towards a `Goal Position`. The user should be able to select different `potential field function`'s for the `Host Vehicle`, the `Goal`, and the `Obstacles`. The user should also be able to add and remove `Obstacles` as well the `Goal Position`.

Optional:
The user should be able to adjust the parameters of the `potential field function`'s.

## Use Case Diagram
The following image shows the corresponding use case diagram of the application. The user can visualize the scenario containing of a `Host Vehicle`, a `Goal`, multiple `Obstacles`, and a `Potential field function`. The user can set the position of the `Host Vehicle`, `Obstacle`'s and the `Goal`, in addition he can also add `Obstacles` as well as setting the `potential field function`.  


<p align="center">
<img src="https://github.com/NaPiZip/Qt-Applications-for-Windows-10/blob/master/Potential_field_path_planning_explorer/Resources/Images/UseCaseDiagram.JPG?raw=true" alt="Use case diagram"/></p>

## Class diagram

<p align="center">
<img src="https://github.com/NaPiZip/Qt-Applications-for-Windows-10/blob/master/Potential_field_path_planning_explorer/Resources/Images/ClassDiagram.JPG?raw=true" alt="Use case diagram"/></p>

## Introduction
This section covers the basic content of the Potential field method from the paper.

## The Graphical User Interface Explained
This section explains the GUI, and what it displays.

## Conclusions
Answers to the following questions:
  - What was good?
  - What was bad?
  - What would I change next time?


## Future
Additional things I would like to improve?


## Contributing

To get started with contributing to me GitHub repository, please contact me [Slack](https://join.slack.com/t/napi-friends/shared_invite/enQtNDg3OTg5NDc1NzUxLWU1MWNhNmY3ZTVmY2FkMDM1ODg1MWNlMDIyYTk1OTg4OThhYzgyNDc3ZmE5NzM1ZTM2ZDQwZGI0ZjU2M2JlNDU).
