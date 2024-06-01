@echo off

rem Make the entry point
:start
Unreal\Environments\Blocks\Blocks.uproject
goto :start_px4


rem Define a function to launch PX4 Autopilot
:start_px4
rem First get the WSL IP
netsh interface ip show address "vEthernet (WSL)" | findstr "Ipv4 Address" > ip_data.txt
set /p ip=<ip_data.txt
del ip_data.txt
set "ip=%ip:~-10%"

rem Then start an Ubuntu instance
start Ubuntu -c "cd ~/PX4-Autopilot && export PX4_SIM_HOST_ADDR=%ip% && make px4_sitl_default none_iris; exec bash"
goto :start_qgc


rem Start the QGC software
:start_qgc
start Ubuntu -c "cd ~/QGC && ./QGroundControl.AppImage; exec bash"
goto :end

:end