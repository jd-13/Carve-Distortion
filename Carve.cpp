/*
 *	File:		Carve.cpp
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

#include "Carve.h"

Carve::Carve() :    DSPUnit1(), DSPUnit2(),
                    routing(ROUTING_DEFAULT), dryLevel(DRYLEVEL_DEFAULT), masterVol(MASTERVOL_DEFAULT),
                    isStereo(STEREO_DEFAULT) {
}

Carve::~Carve(){}

inline float Carve::ProcessSerial(float inSample) {
    return DSPUnit2.process(DSPUnit1.process(inSample));
}

inline float Carve::ProcessParallel(float inSample) {
    return DSPUnit1.process(inSample) + DSPUnit2.process(inSample);
}

inline void Carve::ProcessMaster(float sample, float* inSample) {
    *inSample = (sample + (dryLevel * *inSample)) * masterVol;
}

void Carve::ClockProcess1in1out(float* inSample) {
    
    float sample {*inSample};
    
    sample = ProcessSerial(sample) * (1 - routing) + ProcessParallel(sample) * routing;
    
    // dry level and master vol
    ProcessMaster(sample, inSample);
}

void Carve::ClockProcess1in2out(float* inLeftSample, float* inRightSample) {
    
    float leftSample {*inLeftSample};
    float rightSample {*inRightSample};
    
    // stereo mode processing
    if (isStereo) {
        leftSample = DSPUnit1.process(leftSample);
        rightSample = DSPUnit2.process(leftSample);
    } else { // non stereo mode processing
        leftSample = ProcessSerial(leftSample) * (1 - routing) + ProcessParallel(leftSample) * routing;
        rightSample = leftSample;
    }
    
    // dry level and master vol
    ProcessMaster(leftSample, inLeftSample);
    ProcessMaster(rightSample, inRightSample);
}

void Carve::ClockProcess2in2out(float* inLeftSample, float* inRightSample) {
    
    float leftSample {*inLeftSample};
    float rightSample {*inRightSample};
    
    // stereo mode processing
    if (isStereo) {
        leftSample = DSPUnit1.process(leftSample);
        rightSample = DSPUnit2.process(rightSample);
    } else { // non stereo mode processing
        leftSample = ProcessSerial(leftSample) * (1 - routing) + ProcessParallel(leftSample) * routing;
        rightSample = ProcessSerial(rightSample) * (1 - routing) + ProcessParallel(rightSample) * routing;
    }
    
    // dry level and master vol
    ProcessMaster(leftSample, inLeftSample);
    ProcessMaster(rightSample, inRightSample);
}