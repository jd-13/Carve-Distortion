# Carve-Distortion
Carve is a two stage wave shaping distortion VST and Audio Unit, with multiple wave shapes and serial/parallel/stereo routing options.

For more details and a free download of the compiled plugin: https://www.whiteelephantaudio.com/plugins#Carve

![](https://whiteelephantaudio.com/thumbs/carveV2.4.1Animation.gif)  

## Built using:  

JUCE: https://www.juce.com/  

WECore: https://github.com/jd-13/WE-Core  

Catch (for tests): https://github.com/philsquared/Catch  

VST SDK:  https://www.steinberg.net/en/company/developers.html

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
  
Right click the project name, select add new group, name the group Graphics.  
![alt tag](https://whiteelephantaudio.com/buildScreenshots/BuildSteps9.png)  
  
Right click the newly created folder, select add existing files.  
Within this repo is a file in Graphics/background.jpeg. Add this file.  
![alt tag](https://whiteelephantaudio.com/buildScreenshots/BuildSteps10.png)  
  
### Add include paths
Click config in the top left, and then select a build configuration from the left pane. In the screenshot below I've selected a debug Xcode build. Add the include paths as shown below, prepending them with the directories you have them in on your system. (Ignore the DSPFilters path, this is no longer required)  
![alt tag](https://whiteelephantaudio.com/buildScreenshots/BuildSteps11.png)  

Finally, check the location of the VST SDK is set to the location of the VST SDK on your machine. This is specified in the Preferences menu. Here you can also specify the location of several other SDKs if you wish to do so.  
<img src="https://whiteelephantaudio.com/buildScreenshots/BuildSteps12.png" width="200">
<img src="https://whiteelephantaudio.com/buildScreenshots/BuildSteps13.png" width="500">

### Build the project
From the File menu select save all, then select "Save project and open in IDE" (bottom left corner of the main window). On Windows or Mac this will open the configured IDE which will be ready to compile the project. On Linux a makefile will now have been generated, which you can find in [name_of_the_project]/Builds/LinuxMakefile
