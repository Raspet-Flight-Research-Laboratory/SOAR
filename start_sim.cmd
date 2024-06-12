@echo off

rem Make the entry point
:start
Unreal\Environments\Blocks\Blocks.uproject
goto :start_px4


rem Define a function to launch PX4 Autopilot
:start_px4
start Ubuntu -c "cd ~/ardupilot && ~/ardupilot/Tools/autotest/sim_vehicle.py -v ArduCopter -f airsim-copter --console --map --sim-address=172.29.192.1; exec bash"
goto :start_qgc


rem Start the QGC software
:start_qgc
start Ubuntu -c "cd ~/QGC && ./QGroundControl.AppImage"
goto :end

:end