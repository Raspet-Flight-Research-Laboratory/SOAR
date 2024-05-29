# Welcome to SOAR (Simulated Operations for Aerial Research)

SOAR is a fork of [AirSim](https://github.com/microsoft/AirSim) and port to UE 5 by [Colosseum](https://github.com/CodexLabsLLC/Colosseum), developed for research purposes at the Raspet Flight Research Laboratory.

## Build Status

[![Windows Build](https://github.com/OpenSourceVideoGames/AirSim/actions/workflows/test\_windows.yml/badge.svg)](https://github.com/OpenSourceVideoGames/AirSim/actions/workflows/test\_windows.yml)

## Unreal Engine Version

SOAR uses Unreal Engine 5.3.2 or greater.

## Currently Supported Operating Systems

SOAR currently supports the following operating system:

### Windows

- Windows 11 (Latest)

## Introduction

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

## Contact Information

For any questions or comments regarding SOAR, please contact:

- Email: bswann@raspet.mssstate.edu
- GitHub: @mr.stealyocurls

## License

This project is released under the MIT License. Please review the [License file](LICENSE) for more details.
