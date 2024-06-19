@echo off

rem Make the entry point
:start

set /p input=Running this script will halt ALL WSL instances. Do you want to continue? (y/n): 

rem Select the next step based on the user's input
if %input% == y goto :start_blocks
if %input% == n goto :end

rem Else restart the script
goto :start

rem Reset WSL and start the Blocks project
:start_blocks

rem Shutdown WSL to ensure a graceful entry
wsl --shutdown

Unreal\Environments\Blocks\Blocks.uproject
goto :start_px4


rem Define a function to launch PX4 Autopilot
:start_px4
start Ubuntu -c "cd ~/PX4-Autopilot && export PX4_SIM_HOST_ADDR=172.29.192.1 && make px4_sitl_default none_iris; exec bash"
goto :start_qgc


rem Start the QGC software
:start_qgc
start C:\"Program Files"\QGroundControl\QGroundControl.exe
goto :end

:end