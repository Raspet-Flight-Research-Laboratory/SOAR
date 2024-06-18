---
# * (05/22/2024) *

** Created a copy of AirSim, AirSim v5.3.2, and Colosseum to maintain their current state as a backup. **

** Updated C:/Users/RFRL/Documents/AirSim/setting.json to remove the prompt to start the AirSim simulation as a car. **


---
# * (05/23/2024) *

** Installed and tested PX4 SITL with the current AirSim v5.3.2 installation. **
	To used PX4:
	1. Open C:/User/rfrl/Douments/AirSim/setting.json and update the LocalHostIp variable to the current WSL IP. 

	NOTE: THE WSL IP CAN BE FOUND ON THE WINDOWS CMD WITH THE COMMAND IPCONFIG /ALL.

	2. Open Ubuntu and run the command "export PX4_SIM_HOST_ADDR=(WSL IP_ADDR)". Replace (WSL IP_ADDR) with the actual WSL IP
	3. Cd into the PX4-Autopilot directory.
	4. Run the command "make px4_sitl_default none_iris". PX4 SITL should start trying to connect to AirSim automatically.

NOTE: PX4 seemed to be working as intended when evaluated in tandem with the blocks project; however, PX4 has not been tested with any scripts

** Updated C:/Users/RFRL/Documents/AirSim/setting.json to contain the correct setting for using PX4 SITL with AirSim. **

** Installed QGroundControl **

NOTE: QGC IS NOT CURRENTLY WORKING WITH PX4 SITL AS OF * (05/23/2024) *. this could just be me being uneducated with respect to this type of software or it could be a WSL2 compatibility issue. If it is the latter, [this link](https://github.com/PX4/PX4-Autopilot/issues/17610) may have some solutions to resolve the issue.


---
# * (05/24/2024) *

** Fixed QGC by downloading it on WSL. When PX4 and QGC were put into the same environment, QGC autodetected and connected to the SITL. **

** QGC is in the ~/QGC folder on windows. To start QGC cd into the QGC folder and run the command ./QGroundControl.AppImage. **

NOTE: THE ORDER IN WHICH YOU START THE APPLICATIONS MATTERS. Start the Unreal AirSim project first, then start PX4, then start QGC.


---
# * (05/28/2024) *

** Installed Rufus for the purpose of formatting micro SDs. **

NOTE: DO NOT TOUCH THIS PROGRAM IF YOU DO NOT KNOW WHAT IT DOES. IT CAN DESTROY EVERYTHING IN A DRIVE.

** Loading 3rd party maps into unreal can be simple, [this link](https://youtu.be/y09VbdQWvQY?si=qfFHkwHqYp8SNK0R) provides a good tutorial. **

NOTE: It seems that importing a 3rd party map to Unreal will be more difficult if the map in question does not have an associated .FBX file.

** Imported a traditional Korean palace to the blocks projects. This map was downloaded and imported through Epic Games. **
	To load the map:
	1. Launch Unreal
	2. Click file 
	3. Click open level
	4. Navigate to: Content>HwaseongHaenggung>Maps>demo

** Reduced Unreal scalibility setting from epic to high to improve performance and response time. **

NOTE: Running the blocks project on the aformentioned map causes performance to drop once the simulation is halted.

** Created a cesium account and linked it to the Cesium plugin in the blocks Unreal project. **

** Configured the Cesium plugin so it displays a 3D map of the world in real time. **

NOTE: USE [THIS TUTORIAL](https://www.youtube.com/watch?v=Eib5YmHieuk) FOR SETTING UP AND/OR STARTING CESIUM 

** Enabled the PhysicsCollisionHandler in the World Setting of the blocks project. **


---
# * (05/29/2024) *

** Began studying Unreal so that we can implement SOAR's multi-window structure more efficiently. **

** Found a few paid plugins for multi-window rendering. **

** Started work on syncing QGC coordinates and Unreal Cesium coordinates. **

** Set the starting position of the AirSim drone to the parking lot of Raspet II. **

** Installed Notepad++ to act as a superior file editor of sorts. **

** Removed all traces of helloCar from the AirSim.sln. **


---
# * (06/04/2024) *

** Researched Multi-window plugins for Unreal engine. We should probably choose [this one.](https://www.unrealengine.com/marketplace/en-US/product/multi-window-extension) **

** Adjusted start_sim.cmd to utilize the previously unknown WSL static IP. **

** Wrote some LISP scripts that may help in the future. **


---
# * (06/05/2024) *

** Began (once again) trying to figure out how to sync the location data between PX4/QGC and cesium in Unreal. **

** Began trying to fix the communication issues between PX4, QGC, and AirSim. **

NOTE: SOMETIMES PX4 WILL THROW A (px4 server already running for instance 0) ERROR. RESTARTING THE PC WILL FIX THIS.

NOTE: IF THE QGC SCREEN STARTS GLITCHING IT IS A WSL ISSUE, NOT A QGC ISSUE. SEE [THIS LINK](https://github.com/microsoft/wslg/issues/1148) FOR A DISCUSSION OF A SIMILAR PROBLEM. Also, launching QGC then closing it with Ctrl + c seems to fix the issue sometimes.

** Installed and configured Ardupilot to replace PX4. **

** The start up cmd files are currently not working. **

** As of today, Unreal is not loading with the current settings.json. **


---
# * (06/12/2024) *

** Started working on connecting Ardupilot and AirSim. (Much harder than it sounds.) **

** Updated Unreal .gitignore to allow Blocks.uproject to the github. **

** Brady provided a new battery for the X9D, it is working now. **

** Began attempting to connect the Taranis to QGC. **

** THERE ARE NOW TWO START UP SCRIPTS. One scripts starts AirSim with PX4, the other starts AirSim with Ardupilot. **


---
# * (06/13/2024) *

** Fixed this issue where QGC would never reach the "Ready to fly" state, thanks to Matthew. **

** The flight plan upload system between QGC and PX4 is still broken. Working on that as of now. **

** Still broken, I think it might be related to the fact that we are trying to fly without a radio. **

** Installed usbipd for the purpose of sharing the Taranis connection with WSL **

** I was able to sucessfully connect the Taranis to WSL, but QGC still does not recognize it. **


---
# * (06/14/2024) *

** Forced Windows to connect the Logitech controller to WSL, Windows cannot use this controller until it is unbound.
NOTE: SEE usbipd /? for help. **


---
# * (06/18/2024) *

** Downloaded process explorer **

** Sucessfully connected the logitech controller to QGC (I think) this did not resolve the issue. **

** Create a joint developer GitHub account for further development efforts.  **

** Created an Epic Games account linked with the raspet.dev account and connected GitHub to the Epic Games account. **

---
