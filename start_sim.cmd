@echo off

rem Make the entry point
:start
Unreal\Environments\Blocks\Blocks.uproject
goto :start_px4


rem Define a function to launch PX4 Autopilot
:start_px4
start Ubuntu -c "cd ~/PX4-Autopilot && export PX4_SIM_HOST_ADDR="172.29.192.1" && echo "Exporting WSL IP: %ip%" && make px4_sitl_default none_iris; exec bash"
goto :start_qgc


rem Start the QGC software
:start_qgc
start Ubuntu -c "cd ~/QGC && ./QGroundControl.AppImage"
goto :end

:end