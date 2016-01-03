/*
 *	File:		ParameterData.h
 *
 *	Version:	0.02.00
 *
 *	Created:	09/09/2015
 *
 *	This file is part of Carve.
 *
 *  Carve is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Carve is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Carve.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef PARAMETERDATA_H_INCLUDED
#define PARAMETERDATA_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


const int   MODE_SINE = 1,
            MODE_PARABOLIC_SOFT = 2,
            MODE_PARABOLIC_HARD = 3,
            MODE_ASYMMETRIC_SINE = 4,
            MODE_EXPONENT = 5,
            MODE_CLIPPER = 6,
            MODE_DEFAULT = MODE_SINE,
            MODE_MIN = MODE_SINE,
            MODE_MAX = MODE_CLIPPER;

const float PREGAIN_DEFAULT = 1,
            PREGAIN_MIN = 0,
            PREGAIN_MAX = 2,

            POSTGAIN_DEFAULT = 0.5,
            POSTGAIN_MIN = 0,
            POSTGAIN_MAX = 2,
            
            TWEAK_DEFAULT = 0,
            TWEAK_MIN = -1,
            TWEAK_MAX = 1,

            ROUTING_SERIAL = 0,
            ROUTING_PARALLEL = 1,
            ROUTING_DEFAULT = ROUTING_SERIAL,

            DRYLEVEL_DEFAULT = 0,
            DRYLEVEL_MIN = 0,
            DRYLEVEL_MAX = 2,
            
            MASTERVOL_DEFAULT = 1,
            MASTERVOL_MIN = 0,
            MASTERVOL_MAX = 2;

const bool  STEREO_OFF = false,
            STEREO_ON = true,
STEREO_DEFAULT = STEREO_OFF;

const String    MODE1_STR = "Mode1",
                MODE2_STR = "Mode2",
                PREGAIN1_STR = "PreGain1",
                PREGAIN2_STR = "PreGain2",
                POSTGAIN1_STR = "PostGain1",
                POSTGAIN2_STR = "PostGain2",
                TWEAK1_STR = "Tweak1",
                TWEAK2_STR = "Tweak2",
                ROUTING_STR = "Routing",
                STEREO_STR = "Stereo",
                DRYLEVEL_STR = "DryLevel",
                MASTERVOL_STR = "MasterVol",
                GROUP_UNIT1 = "Unit1",
                GROUP_LEFT = "Left",
                GROUP_UNIT2 = "Unit2",
                GROUP_RIGHT = "Right";

// Translates betweeen the normalised 0 - 1 range used by VSTs and the ranges used by the plugin internally
inline float TranslateParam_Norm2Inter(float val, float min, float max) {
    return val * (max - min) + min;
}

inline float TranslateParam_Inter2Norm(float val, float min, float max) {
    return (val - min) / (max - min);
}


#endif  // PARAMETERDATA_H_INCLUDED
