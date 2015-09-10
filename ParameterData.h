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


const int   MODE_SINE = 0,
            MODE_PARABOLIC_SOFT = 1,
            MODE_PARABOLIC_HARD = 2,
            MODE_ASYMMETRIC_SINE = 3,
            MODE_EXPONENT = 4,
            MODE_DEFAULT = MODE_SINE,
            MODE_MIN = MODE_SINE,
            MODE_MAX = MODE_EXPONENT,

            ROUTING_SERIAL = 0,
            ROUTING_PARALLEL = 1,
            ROUTING_STEREO = 2;

const float PREGAIN_DEFAULT = 1,
            PREGAIN_MIN = 0,
            PREGAIN_MAX = 2,

            POSTGAIN_DEFAULT = 0.5,
            POSTGAIN_MIN = 0,
            POSTGAIN_MAX = 2,
            
            TWEAK_DEFAULT = 0,
            TWEAK_MIN = -1,
            TWEAK_MAX = 1,
            
            DRYLEVEL_DEFAULT = 0,
            DRYLEVEL_MIN = 0,
            DRYLEVEL_MAX = 2,
            
            MASTERVOL_DEFAULT = 1,
            MASTERVOL_MIN = 0,
            MASTERVOL_MAX = 2;

const String    MODE_STR = "Mode",
                ROUTING_STR = "Routing",
                PREGAIN_STR = "Pre Gain",
                POSTGAIN_STR = "Post Gain",
                TWEAK_STR = "Tweak",
                DRYLEVEL_STR = "Dry Level",
                MASTERVOL_STR = "Master Vol";


#endif  // PARAMETERDATA_H_INCLUDED
