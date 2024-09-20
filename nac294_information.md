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
# * (06/12/2024) * hours -> 7

** Started working on connecting Ardupilot and AirSim. (Much harder than it sounds.) **

** Updated Unreal .gitignore to allow Blocks.uproject to the github. **

** Brady provided a new battery for the X9D, it is working now. **

** Began attempting to connect the Taranis to QGC. **

** THERE ARE NOW TWO START UP SCRIPTS. One scripts starts AirSim with PX4, the other starts AirSim with Ardupilot. **


---
# * (06/13/2024) * hours -> 8

** Fixed this issue where QGC would never reach the "Ready to fly" state, thanks to Matthew. **

** The flight plan upload system between QGC and PX4 is still broken. Working on that as of now. **

** Still broken, I think it might be related to the fact that we are trying to fly without a radio. **

** Installed usbipd for the purpose of sharing the Taranis connection with WSL **

** I was able to sucessfully connect the Taranis to WSL, but QGC still does not recognize it. **


---
# * (06/14/2024) * hours -> 1

** Forced Windows to connect the Logitech controller to WSL, Windows cannot use this controller until it is unbound.
NOTE: SEE usbipd /? for help. **


---
# * (06/18/2024) * hours -> 8

** Downloaded process explorer **

** Sucessfully connected the logitech controller to QGC (I think) this did not resolve the issue. **

** Create a joint developer GitHub account for further development efforts.  **

** Created an Epic Games account linked with the raspet.dev account and connected GitHub to the Epic Games account. **


---
# * (06/19/2024) * hours -> 8

** Began working on some possible workarounds for the current task 8 software failures. **

** Created a .wslconfig file in the %userprofile% (C:\Users\rfrl) folder to force WSL into mirrored mode. 
NOTE: I allowed inbound connections with the following admin powershell command: "Set-NetFirewallHyperVVMSetting -Name '{40E0AC32-46A5-438A-A0B2-2B479E8F2E90}' -DefaultInboundAction Allow". This needs to be set to Block instead of Allow to reset it to default. **

 ** Even after setting up mirrored mode, QGC is still throwwing errors. **
 
 ** Re-trying with QGC installed on windows **
 
 ** Fixed the AirSim/Px4/QGC flight upload issues by re-installing QGC on windows, and manually connecting it to PX4. **
 
 ** NOTE: the IP that QGC connects to PX4 with is 172.29.198.6, this can be found in WSL with the command: "ip addr" on Ubuntu. **
 
 ** Updated start_sim.cmd to support the new install location of QGC and to solve a few previous issues. **
 
 ** Sucessfully connected the Taranis to QGC and flew a mission (from Raspet II to the swamp and back). The new setup WORKS FLAWLESSLY. **
 
 
---
# * (06/20/2024) * hours -> 4

** Began working to get camera feed from AirSim to QGC. **

** Found a way to begin connecting multiple asynchronous vehicles to the same AirSim project. **


---
# * (06/24/2024) * hours -> 3

** Worked on setting up a project similar to SOAR on personal machine. **


---
# * (06/25/2024) * hours -> 7.5

** Set up the SOAR drone to launch in first person view. **

** Moved settings.json into the SOAR project to make it easier to track changes. **

** NOTE: THE UNREAL PROJECT NEEDS TO BE BOOTED FROM THE STARTUP FILE. IF STARTED FROM THE BLOCKS.UPROJECT THE WRONG SETTING WILL LOAD. **

** NOTE: It looks like we may have to implement a small UDP protocol to get camera data from AirSim to QGC. **

** Began setting up a blueprint in SOAR to swap between FPV and GCSV. **


---
# * (06/26/2024) * hours -> 8

** Finished the Unreal blueprint for the new GCSV camera. **

** Began studying how to implement flight logs. **

** Added an actor to the Unreal project for the purpose of data collection. **

** Started building the code for writing data from AirSim to a CSV file. **


---
# * (06/27/2024) * hours -> 5

** Created a short SOAR flight video for Brady. **

** Started working on importing more flight models (fixed-wing model) to AirSim. **

** Changed line 42 in SOAR/AirSim/GazeboDrone/scr/main.cpp from msr::airlib::MultirotorRpcLibClient client; to msr::airlib::MultirotorRpcLibClient client("172.29.192.1");. **

** Began installing Gazebo on WSL. **

** NOTE GAZEBO IS NOT WORKING AS OF TODAY BECAUSE OF BOOST::SIGNAL depreciation. **

** Began fixing the Gazebo dependance issues. **


---
# * (07/09/2024) * hours -> 1

** Continued setting up the project on personal machine. **


---
# * (07/11/2024) * hours -> 8

** Began searching for the best way to install Gazebo. **

** After fighting with make not being able to execute the command "make px4_sitl gz_x500" for hours. I found that it is dependent on the installation,
NOTE: PX4 requires the gz-garden binary; however, the gazebo binary and gz-garden CANNOT BE INSTALLED AT THE SAME TIME. **

** Sucessfully connected Gazebo and QGC. **

** Began working on connecting AirSim and Gazebo. **

** As of now, Gazebo does not seem like a good option for pairing with AirSim. **

** Got PX4 and Gazebo working. **

** Began researching AirSim code, so that we can write our own GazeboDrone driver. **


---
# * (07/12/2024) * hours -> 7.5

** Continued researching methods for connecting Gazebo and AirSim. **

** Cloned colosseum to WSL and built it with GCC. **

** Built GazeboDrone in GCC also. **

** Finished installing the multi-window extension. **

** Began looking into collecting vehicle information from PX4 directly. **

** Brady found the beginnings of what we could use to collect data. **


---
# * (07/14-15/2024) * hours -> 2

** Continued working on settung up the SOAR project on my personal machine. **


---
# * (07/16/2024) * hours -> 8

** Began working on the socket-based architecture for the data logging and the connection to Unreal from outside sources. **

** The current server program is under development and it is located in C:\...\source\repos\socketTests. **

** Completed a simplistic server-side socket connection protocol. NOTE: NEEDS TO BE TESTED. I'm working on that... **


---
# * (07/17/2024) * hours -> 6.5

** Continued working on the socket connections for the SOAR project. Working on turning them into a library. **

** Finished the Client-side now working on making it better. **

** The client server communication works, but not as expected. More work is required. **


---
# * (07/18/2024) * -> hours 2

** Added new system variables to take us directly to the SOAR project, and to the C:\...\source\repos folder. **

** The system variables can be accessed on the command line with %SOAR% and %codeprofile% respectively. **

** Continued developing the rfrl library for building sockets. **

** Began researching the type of connections that Flight Gear uses. **


---
# * (07/19/2024) * -> hours 1

** Continued working on the rfrl socket toolkit. **


---
# * (07/22/2024) * -> hours 2

** Continued working on rfrl socket toolkit. **


---
# * (07/23/2024) * -> hours 7.5

** Continued working on toolkit. **

** Continued working on connecting AirSim and FlightGear. **

** Continued working on data logging. **

** Added fgfs.exe (FlightGear) to the PATH to support future development. **

** Performed a clean install of FlightGear and got the FGFS command working on CMD. **

** Sucessfully connected sockets via the localhost. Next is FlightGear. **


---
# * (07/24/2024) * -> hours 8

** Fixed the toolkit not reading the correct number of bytes. **

** Continued researching connecting to FlightGear via TCP. **

** Sucessfully connected to FlightGear via TCP. **

** Working on getting data from FlightGear now. Seems like I will need to build an xml file in the FG root directory. **

** Added a soar_protocol.xml file to the FG root. **

** As of today, I cannot connect the socket library to the generic FG protocol. It connects via telnet, but it does not connect to generic. **

** Scratch that last thought. I got it working. NOTE you must connect to FG as a SERVER. The correct way to start FG is: "fgfs --generic=socket,out,10,localhost,62553,tcp,soar_protocol". **


---
# *(07/30/2024) * -> hours 8

** Accidentally deleted the log for this day, so this is a place holder because I forgor. **


---
# * (07/31/2024) * -> hours 8

** Fixed the tokenizer functions, AGAIN. **

** NOTE: We may need to proceed with development on a Linux environment since the current AirSim project has issues. **

** I have determined the method that we can use to perform data logging and FlightData injection, but I currently cannot implement it. **

** Downloaded VirtualBox and created an Ubuntu VM. **

** Verified that the TCP sockets work on Linux as well as Windows. **

** Began implementing UDP connections. **


---
# * (08/06/2024) * -> hours 7.5

** Continued working on the VM for testing AirSim. **

** VirtualBox does not seem to work with Ubuntu 24.04, so I downgraded to 22.04 to try again. **

** Continued working on rfrl toolkit. **

** Installed Ubuntu 22.04 (Jammy Jellyfish) onto the VirtualBox vm. PW: rfrl UN: rfrl. **

** Scratch all of that. All VMs despise Hyper-V, so we will need another drive for an Ubuntu installation. **

** Created a new Unreal project named actorTest for building an testing actors. **

** Built a data transmitter and a data collector in Unreal. **

** Changed some files in Unreal in order to get it to actually compiler. Line 1640 of BgScriptReader.cs was changed from 
```report.NotifyUsers.UnionWith(users);``` to ```if (users != null) report.NotifyUsers.UnionWith(users); ```. 
Changed line 87 of CheckForHacks.cs from ```Logger.LogInformation("Scanning files...", FilesToCheck.Count);``` to ```Logger.LogInformation("Scanning files... [{Arg0}]", FilesToCheck.Count);```. 

See [this link](https://forums.unrealengine.com/t/error-compiling-the-automation-tool-after-updating-visual-studio-today-unreal-5-3-2/1393088/18) **

** Disabled live coding in Unreal as it was causing errors with MSVS. **

** Sucessfully loaded an actor into the Blocks project. **

** Created an actor for data logging, and added bare-bones code for that actor. **

** Thanks to Matthew we got an external drive working with Ubuntu, so we can build the project in a native Linux environment. ** 


---
# * (08/07/2024) * -> hours 7.5

** Currently fighting with Unreal, the project isn't resolving my custom symbols despite the inclusion of my files in the actor source. **

** Currently working out how to get the blocks project to compile my custom files. **

** Downloaded SOAR on Ubuntu. **

** Updated Ubuntu. **

** The current version of our project is not working properly. The setup.sh does not install the required version of rpclib, **

** There are MANY things wrong with the Ubuntu installation of AirSim. **

** I got Unreal setup on Ubuntu. **


---
# * (08/10-11/2024) * -> hours 4

** Continued trying to build AirSim on Ubuntu. **


---
# * (08/13/2024) * -> hours 7.5

** Began working on getting the project running on Ubuntu 20.04. **

** Tested RFRL-Toolkit on Linux. **

** Partitioned the external drive, and installed Ubuntu 20.04. **

** Began researching possible GUI libraries for future GUI development. **

** Installed Java and Visual Basic for potential future GUI development. **

** Added the Java/bin to the path so that we have access to the jpackage.exe. **


---
# * (08/14/2024) * -> hours 6

** Continued researching GUI for future development. **

** Installed LLVM (Clang) for compiling C/C++ code without CL (MSVS). **

** Added LLVM/bin to the PATH. **

** I have thought about it, and it will probably be best to use Qt (C++ library) for GUI development. **

** Updated RFRL-Toolkit, removed CL compiler reliance. **

** Kinda leaning towards FLTK or something similar for GUI development now. **


---
# * (08/19/2024) * hours -> 4

** Started building Colosseum for UE 5.3 instead of AirSim. **

** Fixed some build issues with respect to the Colosseum project. **


---
# * (08/20/2024) * hours -> 2

** Continued trying to fix build errors in the Blocks project on Ubuntu 20.04. **

** Discovered that the issue is being caused in step 3/6 in the compilation process. (somtheing to do with a .so file) **


---
# * (08/21/2024) * hours -> 2.5

** The Raspet computer is not recognizing the SSD for some reason. Currently working through that. **

** NOTE: The RFRL desktop's version of GRUB does not boot the external Ubuntu SSD by default anymore, and I don't know how to fix it. 
To boot from the drive, do the following:

1. Press F8 at POST, and select the Ubuntu SSD as the boot device.
2. You should see the GRUB terminal. Enter the following commands.
	1. set root=(hd0,gpt2). PLEASE MAKE SURE THIS IS THE UBUNTU DRIVE FIRST BY USING THE COMMAND ls (hd0,gpt2).
	2. linux /boot/vmlinuz-5.15.0-119-generic root=/dev/sda2 AGAIN, THE SDA2 IS RELEVANT TO THE DRIVE ITSELF, PLEASE VERIFY.
	3. initrd /boot/initrd.img-5.15.0-119-generic
	4. boot
**



---
# * (08/22/2024) * hours -> 4

** Re-installed SOAR and Colosseum to see if that will make any difference when compiling. **

** Installed nvidia driver 555. So that the RFRL desktop can run Unreal. **

** Configured Ubuntu to work with the RFRL headset. **

** Fought to get the nvidia driver working with secure boot. That took WAY too long. **

** Still having build issues in the AirSim project. **


---
# * (08/26/2024) * hours -> 3

** Finally fixed the compilation issues in the Colosseum project. One of the .so files was missing. **

** Got AirSim, PX4, and QGC working on Ubuntu 20.04. WITH A SUCCESSFUL FLIGHT. **

** Continued working on getting the project setup on Ubuntu. **

** Continued developing the SOAR project. **


---
# * (08/27/2024) * -> hours 4

** Made some changes to the RFRL-Toolkit. **

** If I am being honest, I do not remember what else I did on this day. **

** I think I got PX4 and QGC working with the Colossuem project on Linux. **


---
# * (08/28/2024) * -> hours 3

** Most of this day was spent discussing the potential Agile Autonomy project. **

** Made a few more changes to the RFRL toolkit. E.g., I added two new functions that allow us to customize the EOT characters, and how the data is split on recieve. **


---
# * (08/29/2024) * -> hours 4

** Added some additional functionality to the rfrlSocket class. **

** Cloned the Cesium for Unreal projects from github. Currently trying to get that to work on Linux. **

** The Cesium for Unreal github clone did not work, so I will try the .zip files at [this link](https://github.com/CesiumGS/cesium-unreal/releases) instead. **

** This new source from Cesium seems to have worked, the plugin compiled succssfully. NOTE: This causes Unreal to crash if you do not also copy the shaders to the Plugins folder. **

** Got cesium up and running for Unreal on Linux. **

** Began researching for a potential survey. **

** Started compiling sources for a detect and avoid survey paper. **

** Created the baseline for a survey paper in Overleaf. **


---
# * (09/20/2024) *

** It has been many years since my last update. Most of it was spent trying to fix all the issues related to switching to Ubuntu 20.04. **

** So today, I finally got the build issues sorted out, thanks to someone on Github. **

** Now I just have to get Gazebo connected to AirSim. And Cesium, because it is not working now. **

** 


---