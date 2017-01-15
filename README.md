# Carve-Distortion
Carve is a two stage wave shaping distortion VST and Audio Unit, with multiple wave shapes and serial/parallel/stereo routing options.

For more details and a free download of the compiled plugin: http://whiteelephantaudio.com/plugins/carve/

The master branch reflects the latest release available on the website, the dev branch reflects the latest updates before they get released.  

![alt tag](https://whiteelephantaudio.com/wp/wp-content/uploads/2015/10/Carve-v2b.png)  

## Built using:  

JUCE: https://www.juce.com/  

A Collection of Useful C++ Classes for Digital Signal Processing: https://github.com/vinniefalco/DSPFilters

WECore: https://github.com/jd-13/WE-Core  

Catch (for tests): https://github.com/philsquared/Catch  

## Build Instructions:

The easiest way to build this project for any OS is using the Projucer. To do this you'll need to download all of the above libraries, (excluding catch, unless you want to run unit tests), and create a new project using the Projucer.
