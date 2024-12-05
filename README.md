# Welcome to SOAR (Simulated Operations for Aerial Research)

SOAR is a fork of [AirSim](https://github.com/microsoft/AirSim) and port to UE 5 by [Colosseum](https://github.com/CodexLabsLLC/Colosseum), developed for research purposes at the Raspet Flight Research Laboratory.

<div align="center">
   <!-- Make sure format is just like this.
    Wrong -> <a>  <img/> </a> (this might cause a blue line after every badge).   Correct -> <a><img/></a> 
    -->
  <a href="https://www.raspet.msstate.edu/"><img src="https://img.shields.io/badge/Find%20us%20-Raspet_Flight_research_Laboratory%20-maroon?logoColor" alt="Find Us Badge"/></a> 
  <a href="https://www.instagram.com/msstateraspet/"><img src="https://img.shields.io/badge/@msstateraspet-E4405F?logo=instagram&logoColor=white" alt="Instagram Badge"/></a>
  <a href="https://www.linkedin.com/company/raspet-flight-research-laboratory"><img src="https://img.shields.io/badge/Raspet_Flight_Research_Laboratory-0077B5?logo=linkedin&logoColor=white" alt="LinkedIn Badge"/></a>
</div>

<div align="center">
  <a href="https://docs.github.com/en/repositories/managing-your-repositorys-settings-and-features/customizing-your-repository/licensing-a-repository"><img src="https://img.shields.io/badge/License-MIT-green" alt="License Badge"></a>
  <a href="https://flutter.dev/multi-platform"><img src="https://img.shields.io/badge/Platform-Ubuntu-violet" alt="Platform Badge"></a>
   <a><img alt="Static Badge" src="https://img.shields.io/badge/Unreal_Engine_5.3.2-grey"></a>
   <a><img src="https://img.shields.io/badge/Languages-C++%20%7C%20Python-lightgrey?logo=Code::Blocks&logoColor=white" alt="Platform Badge"></a>
</div>

## Table of Contents
1. [![Notes](https://img.shields.io/badge/Notes-lightgreen?style=flat&logo)](#notes)
2. [![Introduction](https://img.shields.io/badge/Introduction-lightgreen?style=flat&logo)](#introduction)
3. [![Research Background](https://img.shields.io/badge/Research_Background-lightgreen?style=flat&logo)](#research-background)
4. [![SOAR Build Tutorial](https://img.shields.io/badge/SOAR_Build_Turotial-lightgreen?style=flat&logo)](#soar-build-tutorial)
5. [![Miscellaneous Build Tutorial](https://img.shields.io/badge/Miscellaneuos_Build_Tutorial-lightgreen?style=flat&logo)](#miscellaneuos-build-tutorial)
6. [![Contact Info](https://img.shields.io/badge/Contact_Info-lightgreen?style=flat&logo)](#contact-info)

## Notes
## Unreal Engine Version

The version of the Colosseum project that we used here supports Unreal 5.3.2.

## Currently Supported Operating Systems

Everything in the SOAR project was built and tested on Ubuntu version 20.04. There is no support for Colosseum for any version of Ubuntu other than 20.04.

## Introduction

### NOTE: Skip to section 3 for build instructions...

SOAR is a simulator for aerial research, built on [Unreal Engine](https://www.unrealengine.com/). It is open-source and supports software-in-the-loop simulation with popular flight controllers such as PX4 & ArduPilot and hardware-in-loop with PX4 for physically and visually realistic simulations. It is developed as an Unreal plugin that can simply be dropped into any Unreal environment.

This simulator is a fork of the AirSim repository, tailored specifically for research purposes at the Raspet Flight Research Laboratory. The main focus of SOAR is to provide a platform for investigating the effects of different Detect and Avoid (DAA) displays on pilots in a multiplayer flight simulator environment.

## Research Background

The research project behind SOAR aims to build upon the work done by Friedman-Berg et al. (2014) in their paper "Minimum Visual Information Requirements For Detect and Avoid in Unmanned Aircraft Systems." The authors conducted a human-in-the-loop simulation to determine the minimum visual information requirements for an effective DAA system in Unmanned Aircraft Systems (UAS). They identified the "Prediction" display configuration as the minimum required for successful DAA performance.

SOAR seeks to expand on this research by:

1. Finalizing and testing multiple variations of DAA displays, including the "Prediction" configuration and additional designs with more features and potential clutter.
2. Building a Primary Flight Display (PFD) window with elements such as airspeed, altitude, pitch, roll, yaw, gravity, and grid.
3. Implementing a First-Person View (FPV) window and adding a fixed-wing UAV to the simulator.
4. Integrating a Cesium World Map into the Unreal Engine project for enhanced realism.
5. Developing a settings menu to allow users to set flight mode and select aircraft models.
6. Creating a Test Director GUI for setting UI display type, encounter type, and other parameters.

By focusing on these aspects, SOAR aims to provide a comprehensive platform for evaluating the effectiveness of different DAA displays and their impact on pilot performance in a multiplayer flight simulator environment.

## SOAR Build Instructions

This section of the README give full comprehensive instructions for building the project on Ubuntu and Windows. Additionally, this section details significant errors that the RFRL team faced when building the Colosseum project.

### Ubuntu
- clone this project: `git clone git@github.com:Raspet-Flight-Research-Laboratory/SOAR.git`
- cd into the project directory and run: `chmod +x *.sh`
- cd into `(SOAR directory)/Unreal/Environments/Blocks` and run: `chmod +x *.sh`
- cd back into the project directory and run: `./setup.sh` -> This will begin downloading all the project dependecies.
- Once the downloads are done, run: `./build.sh` -> This will create the folder `(SOAR directory)/Unreal/Plugins`, you can move this folder into any project you want. For this tutorial we use the default Blocks project.
- Once this is done, you can copy the Plugins folder into `(SOAR directory)/Unreal/Environments/Blocks` -> otherwise, if you are using a custom Unreal project, there is a tutorial on how to use AirSim for custom projects [here](https://microsoft.github.io/AirSim/unreal_custenv/), albeit outdated.
- Now the project is ready to run in Unreal
### Before going any farther, make sure you have Unreal and CesiumForUnreal installed, (see the Unreal and Cesium For Unreal subsections).
- From the SOAR directory, start your project with the command: `./start_sim.sh` -> YOU MAY NEED TO OPEN THIS SCRIPT AND CHANGE THE PATHS TO THE LOCATIONS OF UNREAL AND THE SOAR PROJECT ON YOUR MACHINE.
- The Unreal Editor will tell you that the Blocks and AirSim modules are missing or created with a different engine version, and it will ask you if you want to compile from source, click yes.
- This should compile and start the project.

### Unreal

- To build Unreal on Ubuntu 20.04, we need to visit [this website](https://www.unrealengine.com/en-US/linux), download the `Linux_Unreal_Engine_5.3.2.zip` and unzip it. -> It is recommended to unzip this directly into the `~` directory on Ubuntu for easy access.

### Cesium For Unreal

- To get the Cesium For Unreal plugin working on Ubuntu, you will have to download the pre-compiled version from [this site](https://github.com/CesiumGS/cesium-unreal/releases) and unzip it into `(SOAR directory)/Unreal/Environments/Blocks/Plugins` -> This is the same directory that you put the AirSim plugin into.
- You will need an access token which can be easily obtained by making an acount with Cesium and generating one using [their website](https://cesium.com/learn/ion/cesium-ion-access-tokens/).
- The Cesium plugin is now usable.


## Miscellaneous Build Tutorials

This section details how to build the other components of the simulator on Ubuntu.

### Q Ground Control

- To build QGC, you must navigate [here](https://docs.qgroundcontrol.com/master/en/qgc-user-guide/getting_started/download_and_install.html) and download the QGroundControl.AppImage.
- Once this is done, put the .AppImage files somewhere where you will know where it is, cd into the folder, and run: `chmod +x QGroundControl.AppImage`
- The installation is complete and QGC can be started with `./QGroundControl.AppImage`

### PX4

- To build PX4, you need to first clone the [PX4 repository](https://github.com/PX4/PX4-Autopilot.git).
- cd into the PX4 directory and run: `git checkout release/1.15`
- cd into `(PX4 directory)/Tools/setup`
- Run: `sudo ./ubuntu.sh` -> This will install all of the PX4 dependancies.
- Once this is done, PX4 is ready to be used.
- PX4 can be invoked with commands similar to the onces found in `start_sim.sh`, and more details on the different PX4 startup commands can be found [on their website](https://docs.px4.io/main/en/dev_setup/building_px4.html).

### Gazebo

- To install Gazebo, you have to run `sudo apt install libgazebo9-dev gazebo` -> This installs Gazebo and all the tools you need to get Gazebo working with AirSim.
- To get AirSim working with Gazebo, make sure you have already completed everything in Section 3, then follow the directions [here](https://microsoft.github.io/AirSim/gazebo_drone/).

## Contact Information

For any questions or comments regarding SOAR, please contact:

- Email: bswann@raspet.mssstate.edu
- GitHub: [@mr.stealyocurls](https://github.com/MrStealYoCurls)

## License

This project is released under the GNU General Public License v3.0. Please review the [License file](LICENSE) for more details.
