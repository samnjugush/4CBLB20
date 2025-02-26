Hello fellow CBL groupmates! I am writing this document to make this folder
a bit more digestible. There are a lot of folders here - and truth be told
I do not know which does what exactly. So, I chose not to remove most of 
the stuff here. The following stuff is important to keep in mind though:

1. Please download everything necessary that is written out in one of the 
documents. To check if everything is installed, run the CheckAddons script
under the tooling folder.

2. The Simulink folder includes various Simulink files such as Ebox, lpos,
Ebox_RTScope and lpos_RTScope. Please note that the files ending with .slx
are the actual simulink project files. If I understand correctly, these are
the differences:
-Ebox: Ethercat-based Control Hardware, interfaces directly with SPERTE to
send signals to the robot. Typically used with real-time execution with
external hardware.
-lpos: (Local Positioning Version) Uses a simplified local positioning, 
more to be used when developing algorithms before testing on the physical
robot. Ideal for simulation without connecting to the robot.    
-RTscope suffix: RTScope integration for frequency response analysis, used
specifically for FRF stuff. So use Ebox_RTScope for measurement of the
system AND FRF analysis.
-I'd recommend first developing the software and controllers with lpos and 
then adding it to the ebox for testing on hardware. 