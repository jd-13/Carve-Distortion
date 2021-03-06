[![CI Main](https://github.com/jd-13/Carve-Distortion/workflows/CI%20Main/badge.svg)](https://github.com/jd-13/Carve-Distortion/actions?query=workflow%3A%22CI+Main%22)
![](https://img.shields.io/badge/C%2B%2B-17-informational)
![](https://img.shields.io/badge/license-GPLv3-informational)

# Carve-Distortion
Carve is a two stage wave shaping distortion VST3 and Audio Unit, with multiple wave shapes and serial/parallel/stereo routing options.

For more details and a free download of the compiled plugin: https://www.whiteelephantaudio.com/plugins/carve

![](https://whiteelephantaudio.com/images/thumbs/originals/carveV2.4.1Animation.gif)  

## Built using:  

JUCE: https://www.juce.com/  

WECore: https://github.com/jd-13/WE-Core  

Catch2 (for tests): https://github.com/catchorg/Catch2  

VST SDK:  https://www.steinberg.net/en/company/developers.html

## Build Instructions

Like other JUCE applications, Carve is built using the Projucer. There are however 2 steps needed
before it will build successfully:

1. Update the header search paths to point to the location of WECore on your machine
2. Download the font [Montserrat](https://fonts.google.com/specimen/Montserrat) and place the
regular and bold ttf files in Source/Graphics
