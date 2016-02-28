/*
 *	File:		CarveDSPUnit.cpp
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

#include "CarveDSPUnit.h"

inline float CarveDSPUnit::processSine(float inSample) const {
    return sin(M_PI * inSample * preGain + (tweak * M_PI)) * postGain;
}

inline float CarveDSPUnit::processParabolicSoft(float inSample) const {
    return (M_PI * inSample * preGain * ((4 * tweak) - sqrt(4 * pow(inSample * M_PI * preGain, 2))) * 0.5) * postGain;
}

inline float CarveDSPUnit::processParabolicHard(float inSample) const {
    return (atan(preGain * 4 * M_PI * inSample + (tweak * M_PI)) / 1.5) * postGain;
}

inline float CarveDSPUnit::processAsymmetricSine(float inSample) const {
    return (cos(M_PI * inSample * (tweak + 1)) * atan(4 * M_PI * inSample * preGain)) * postGain;
}

inline float CarveDSPUnit::processExponent(float inSample) const {
    return (sin(tweak * pow(M_E, (inSample + preGain)))) * postGain;
}

inline float CarveDSPUnit::processClipper(float inSample) const {
    inSample *= M_PI * preGain;
    
    return (sin(0.5 * inSample) +
            0.3 * sin(1.5 * inSample) +
            0.15 * sin(2.5 * inSample) *
            0.075 * sin(3.5 * inSample) +
            0.0375 * sin(4.5 * inSample) +
            0.01875 * sin(5.5 * inSample) +
            0.009375 * sin(6.5 * inSample)) * postGain / 1.5;
}

CarveDSPUnit::CarveDSPUnit() :  preGain(PREGAIN_DEFAULT),
                                postGain(POSTGAIN_DEFAULT),
                                tweak(TWEAK_DEFAULT),
                                mode(MODE_DEFAULT) {
}

// set parameter methods, w/ integrated bounds checks
void CarveDSPUnit::setMode(int val) {
    mode = boundsCheck<int>(val, MODE_MIN, MODE_MAX);
}

void CarveDSPUnit::setPreGain(float val) {
    preGain = boundsCheck(val, PREGAIN_MIN, PREGAIN_MAX);
}

void CarveDSPUnit::setPostGain(float val) {
    postGain = boundsCheck(val, POSTGAIN_MIN, POSTGAIN_MAX);
}

void CarveDSPUnit::setTweak(float val) {
    tweak = boundsCheck(val, TWEAK_MIN, TWEAK_MAX);
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
            
        case MODE_CLIPPER:
            return processClipper(inSample);
            
        default:
            return processSine(inSample);
    }
}