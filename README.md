# Welcome to SOAR (Simulated Operations for Aerial Research)

SOAR is a fork of [AirSim](https://github.com/microsoft/AirSim) and port to UE 5 by [Colosseum](https://github.com/CodexLabsLLC/Colosseum), developed for research purposes at the Raspet Flight Research Laboratory.

## Unreal Engine Version

The version of the Colosseum project that we used here supports Unreal 5.3.2 on both Windows and Linux.

## Currently Supported Operating Systems

Everything in the SOAR project was built and tested on Ubuntu version 20.04, (*PREFERRED* because of Gazebo support) and Windows 11. There is no support for Colosseum for any version of Ubuntu other than 20.04.

### PLEASE NOTE:
Do not attempt to run this project partially on Windows and partially on Ubuntu via a virtual machine or Windows subsystem for Linux unless you have a GPU that supports GPU passthrough.

## 1. Introduction

### NOTE: Skip to section 3 for build instructions...

SOAR is a simulator for aerial research, built on [Unreal Engine](https://www.unrealengine.com/). It is open-source and supports software-in-the-loop simulation with popular flight controllers such as PX4 & ArduPilot and hardware-in-loop with PX4 for physically and visually realistic simulations. It is developed as an Unreal plugin that can simply be dropped into any Unreal environment.

This simulator is a fork of the AirSim repository, tailored specifically for research purposes at the Raspet Flight Research Laboratory. The main focus of SOAR is to provide a platform for investigating the effects of different Detect and Avoid (DAA) displays on pilots in a multiplayer flight simulator environment.

## 2. Research Background

The research project behind SOAR aims to build upon the work done by Friedman-Berg et al. (2014) in their paper "Minimum Visual Information Requirements For Detect and Avoid in Unmanned Aircraft Systems." The authors conducted a human-in-the-loop simulation to determine the minimum visual information requirements for an effective DAA system in Unmanned Aircraft Systems (UAS). They identified the "Prediction" display configuration as the minimum required for successful DAA performance.

SOAR seeks to expand on this research by:

1. Finalizing and testing multiple variations of DAA displays, including the "Prediction" configuration and additional designs with more features and potential clutter.
2. Building a Primary Flight Display (PFD) window with elements such as airspeed, altitude, pitch, roll, yaw, gravity, and grid.
3. Implementing a First-Person View (FPV) window and adding a fixed-wing UAV to the simulator.
4. Integrating a Cesium World Map into the Unreal Engine project for enhanced realism.
5. Developing a settings menu to allow users to set flight mode and select aircraft models.
6. Creating a Test Director GUI for setting UI display type, encounter type, and other parameters.

By focusing on these aspects, SOAR aims to provide a comprehensive platform for evaluating the effectiveness of different DAA displays and their impact on pilot performance in a multiplayer flight simulator environment.

## 3. SOAR Build Instructions

This section of the README give full comprehensive instructions for building the project on Ubuntu and Windows. Additionally, this section details significant errors that the RFRL team faced when building the Colosseum project.

### Ubuntu
- clone this project: git clone git@github.com:Raspet-Flight-Research-Laboratory/SOAR.git
- cd into the project directory and run: chmod +x *.sh
- cd into (SOAR directory)/Unreal/Environments/Blocks and run: chmod +x *.sh
- cd back into the project directory and run: ./setup.sh -> This will begin downloading all the project dependecies.
- Once the downloads are done, run: ./build.sh -> This will create the folder (SOAR directory)/Unreal/Plugins, you can move this folder into any project you want. For this tutorial we use the default Blocks project.
- Once this is done, you can copy the Plugins folder into (SOAR directory)/Unreal/Environments/Blocks -> otherwise, if you are using a custom Unreal project, there is a tutorial on how to use AirSim for custom projects [here](https://microsoft.github.io/AirSim/unreal_custenv/), albeit outdated.
- Now the project is ready to run in Unreal
### Before going any farther, make sure you have Unreal and CesiumForUnreal installed, (see the Unreal and Cesium For Unreal subsections).
- From the SOAR directory, start your project with the command: ./start_sim.sh -> YOU MAY NEED TO OPEN THIS SCRIPT AND CHANGE THE PATHS TO THE LOCATIONS OF UNREAL AND THE SOAR PROJECT ON YOUR MACHINE.
- The Unreal Editor will tell you that the Blocks and AirSim modules are missing or created with a different engine version, and it will ask you if you want to compile from source, click yes.
- This should compile and start the project.

### Unreal

- To build Unreal on Ubuntu 20.04, we need to visit [this website](https://www.unrealengine.com/en-US/linux), download the Linux_Unreal_Engine_5.3.2.zip and unzip it. -> It is recommended to unzip this directly into the ~ directory on Ubuntu for easy access.

### Cesium For Unreal

- To get the Cesium For Unreal plugin working on Ubuntu, you will have to download the pre-compiled version from [this site](https://github.com/CesiumGS/cesium-unreal/releases) and unzip it into (SOAR directory)/Unreal/Environments/Blocks/Plugins
- You will need an access token which can be easily obtained by making an acount with Cesium and generating one using [their website](https://cesium.com/learn/ion/cesium-ion-access-tokens/).
- The Cesium plugin is now usable.


## 4. Miscellaneous Build Tutorials

This section details how to build Linux on Ubuntu. This section does not provide any details for building on Windows, because installing Unreal, and plugins for Unreal is very simple and intuative on Windows.

### Q Ground Control

- To build QGC, you must navigate [here](https://docs.qgroundcontrol.com/master/en/qgc-user-guide/getting_started/download_and_install.html) and download the QGroundControl.AppImage.
- Once this is done, put the .AppImage files somewhere where you will know where it is, cd into the folder, and run: chmod +x QGroundControl.AppImage
- The installation is complete.

### PX4

## Contact Information

For any questions or comments regarding SOAR, please contact:

- Email: bswann@raspet.mssstate.edu
- GitHub: @mr.stealyocurls

## License

This project is released under the GNU General Public License v3.0. Please review the [License file](LICENSE) for more details.
