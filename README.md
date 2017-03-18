# Carve-Distortion
Carve is a two stage wave shaping distortion VST and Audio Unit, with multiple wave shapes and serial/parallel/stereo routing options.

For more details and a free download of the compiled plugin: http://whiteelephantaudio.com/plugins/carve/

![alt tag](https://whiteelephantaudio.com/wp/wp-content/uploads/2015/10/Carve-v2b.png)  

## Built using:  

JUCE: https://www.juce.com/  

A Collection of Useful C++ Classes for Digital Signal Processing: https://github.com/vinniefalco/DSPFilters

WECore: https://github.com/jd-13/WE-Core  

Catch (for tests): https://github.com/philsquared/Catch  

## Build Instructions (draft version):

The easiest way to build this project for any OS is using the Projucer. To do this you'll need to download all of the above libraries and the files in this repo (excluding catch, unless you want to run unit tests).  

### Setup a new project
Open the JUCE folder (which will have been downloaded from one of the above links) and start the Projucer.  
  
Note: If you are using Linux the Projucer may have issues starting. If this happens, you'll need to compile the Projucer yourself. To do this navigate to JUCE/extras/Projucer/Builds/LinuxMakefile and run the make command. This will build a Projucer binary that you can then run.  
  
You should now see the screen below. Select the Audio Plug-in project.
![alt tag](https://whiteelephantaudio.com/buildScreenshots/BuildSteps1.png)  
  
Now give the project a name and a directory, and select your target platforms.  
![alt tag](https://whiteelephantaudio.com/buildScreenshots/BuildSteps2.png)  
  
### Add source files 
Select all files under the source folder and delete them.  
![alt tag](https://whiteelephantaudio.com/buildScreenshots/BuildSteps3.png)  
  
Right click the source folder, select add existing files.
![alt tag](https://whiteelephantaudio.com/buildScreenshots/BuildSteps4.png)  

Navigate to the directory containing the Carve source which you downloaded earlier, and select the files as shown below.  
![alt tag](https://whiteelephantaudio.com/buildScreenshots/BuildSteps5.png)  
  
Right click the project name, select add new group, name the group DSPFilters.
![alt tag](https://whiteelephantaudio.com/buildScreenshots/BuildSteps6.png)  
  
Right click the newly created folder, select add existing files.  
![alt tag](https://whiteelephantaudio.com/buildScreenshots/BuildSteps7.png)  

Navigate to the folder containing the DSPFilters library which you will have downloaded earlier, and find the directory as in the screenshot below. Select all of the files in this directory.  
![alt tag](https://whiteelephantaudio.com/buildScreenshots/BuildSteps8.png)  
  
Right click the project name, select add new group, name the group Graphics.  
![alt tag](https://whiteelephantaudio.com/buildScreenshots/BuildSteps9.png)  
  
Right click the newly created folder, select add existing files.  
Within this repo is a file in Graphics/background.jpeg. Add this file.  
![alt tag](https://whiteelephantaudio.com/buildScreenshots/BuildSteps10.png)  
  
### Add include paths
Click config in the top left, and then select a build configuration from the left pane. In the screenshot below I've selected a debug Xcode build. Add the include paths as shown below, prepending them with the directories you have them in on your system.  
![alt tag](https://whiteelephantaudio.com/buildScreenshots/BuildSteps11.png)  

### Build the project
From the File menu select save all, then select "Save project and open in IDE" (bottom left corner of the main window). On Windows or Mac this will open the configured IDE which will be ready to compile the project. On Linux a makefile will now have been generated, which you can find in [name_of_the_project]/Builds/LinuxMakefile
