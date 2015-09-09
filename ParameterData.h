/*
  ==============================================================================

    ParameterData.h
    Created: 9 Sep 2015 9:26:10pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef PARAMETERDATA_H_INCLUDED
#define PARAMETERDATA_H_INCLUDED

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


#endif  // PARAMETERDATA_H_INCLUDED
