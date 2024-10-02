#!/bin/bash

if [ "$1" == "--gz" ]; then
    gnome-terminal -- bash -c "~/UnrealEngine/Engine/Binaries/Linux/UnrealEditor ~/repos/SOAR/Unreal/Environments/Blocks/Blocks.uproject -settings="~/repos/SOAR/gz-settings.json"; exec bash"

    export PX4_HOME_LAT=33.44018
    export PX4_HOME_LON=-88.84567

    if [ "$2" == "--headless" ]; then
        gnome-terminal -- bash -c "cd ~/repos/PX4-Autopilot && HEADLESS=1 make px4_sitl gazebo-classic; exec bash"
    else
        gnome-terminal -- bash -c "cd ~/repos/PX4-Autopilot && make px4_sitl gazebo-classic; exec bash"
    fi

    gnome-terminal -- bash -c "cd ~/repos/QGC && ./QGroundControl.AppImage; exec bash"
    gnome-terminal -- bash -c "~/repos/SOAR/GazeboDrone/build/GazeboDrone; exec bash"
else
    gnome-terminal -- bash -c "~/UnrealEngine/Engine/Binaries/Linux/UnrealEditor ~/repos/SOAR/Unreal/Environments/Blocks/Blocks.uproject -settings="~/repos/SOAR/settings.json"; exec bash"
    gnome-terminal -- bash -c "cd ~/repos/PX4-Autopilot && make px4_sitl_default none_iris; exec bash"
    gnome-terminal -- bash -c "cd ~/repos/QGC && ./QGroundControl.AppImage; exec bash"
fi