/*
 *	File:		CarveDSPUnit.cpp
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

#include "CarveDSPUnit.h"

template<typename T>
T CarveDSPUnit::boundsCheck(T param, T min, T max) {
    if (param < min) param = min;
    if (param > max) param = max;
    
    return param;
}

inline float CarveDSPUnit::processSine(float inSample) const {
    return sin(M_PI * inSample * preGain + (tweak * M_PI)) * postGain;
}

inline float CarveDSPUnit::processParabolicSoft(float inSample) const {
    return (inSample * ((4 * tweak) - sqrt((4 - preGain) * pow(inSample, 2))) * 0.5) * postGain;
}

inline float CarveDSPUnit::processParabolicHard(float inSample) const {
    return (atan(preGain * 4 * inSample + (tweak * M_PI)) / 1.5) * postGain;
}

inline float CarveDSPUnit::processAsymmetricSine(float inSample) const {
    return (cos(inSample * (tweak + 1)) * atan(4 * inSample * preGain)) * postGain;
}

inline float CarveDSPUnit::processExponent(float inSample) const {
    return (sin(tweak * pow(M_E, (inSample + preGain)))) * postGain;
}

CarveDSPUnit::CarveDSPUnit() {
}

// set parameter methods, w/ integrated bounds checks
void CarveDSPUnit::setMode(int val) {
    mode = val;
    mode = boundsCheck<int>(mode, MODE_MIN, MODE_MAX);
}

void CarveDSPUnit::setPreGain(float val) {
    preGain = val;
    preGain = boundsCheck(preGain, PREGAIN_MIN, PREGAIN_MAX);
}

void CarveDSPUnit::setPostGain(float val) {
    postGain = val;
    postGain = boundsCheck(postGain, POSTGAIN_MIN, POSTGAIN_MAX);
}

void CarveDSPUnit::setTweak(float val) {
    tweak = val;
    tweak = boundsCheck(tweak, TWEAK_MIN, TWEAK_MAX);
}

// process methods
float CarveDSPUnit::process (float inSample) const {
    switch (mode) {
        case MODE_SINE:
            return processSine(inSample);
            
        case MODE_PARABOLIC_SOFT:
            return processParabolicSoft(inSample);
            
        case MODE_PARABOLIC_HARD:
            return processParabolicHard(inSample);
            
        case MODE_ASYMMETRIC_SINE:
            return processAsymmetricSine(inSample);
            
        case MODE_EXPONENT:
            return processExponent(inSample);
            
        default:
            return processSine(inSample);
    }
}