/*
 *	File:		ParameterData.h
 *
 *	Version:	2.0.0
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
#include "General/ParameterDefinition.h"

const ParameterDefinition::RangedParameter<float>   ROUTING(0, 1, 0), // 0 = SERIAL, 1 = PARALLEL
                                                    DRYLEVEL(0, 2, 0),
                                                    OUTPUTGAIN(0, 2, 1);

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
                OUTPUTGAIN_STR = "OutputGain",
                GROUP_UNIT1 = "UNIT 1",
                GROUP_LEFT = "LEFT",
                GROUP_UNIT2 = "UNIT 2",
                GROUP_RIGHT = "RIGHT";

#endif  // PARAMETERDATA_H_INCLUDED
