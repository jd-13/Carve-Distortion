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
                    routing(ROUTING.defaultValue),
                    dryLevel(DRYLEVEL.defaultValue),
                    masterVol(MASTERVOL.defaultValue),
                    isStereo(STEREO_DEFAULT),
                    _filter(25, 19000) {
}

Carve::~Carve(){}

void Carve::setSampleRate(double sampleRate) {
    _filter.setSampleRate(sampleRate);
}

void Carve::reset() {
    _filter.reset();
}

void Carve::Process1in1out(float* inSample, int numSamples) {
    
    // do the waveshaping one sample at a time
    for (int iii {0}; iii < numSamples; iii++) {
        float sample {inSample[iii]};
    
        sample = ProcessSerial(sample) * (1 - routing) + ProcessParallel(sample) * routing;
        
        // dry level and master vol
        ProcessMaster(sample, &(inSample[iii]));
    }
    
    // apply filtering to remove noise
    _filter.Process1in1out(inSample, numSamples);
}

void Carve::Process1in2out(float* inLeftSample, float* inRightSample, int numSamples) {
    
    // do the waveshaping one sample at a time
    for (int iii {0}; iii < numSamples; iii++) {
        float leftSample {inLeftSample[iii]};
        float rightSample {inRightSample[iii]};
        
        // stereo mode processing
        if (isStereo) {
            leftSample = DSPUnit1.process(leftSample);
            rightSample = DSPUnit2.process(leftSample);
        } else { // non stereo mode processing
            leftSample = ProcessSerial(leftSample) * (1 - routing) + ProcessParallel(leftSample) * routing;
            rightSample = leftSample;
        }
        
        // dry level and master vol
        ProcessMaster(leftSample, &inLeftSample[iii]);
        ProcessMaster(rightSample, &inRightSample[iii]);
    }
    
    // apply filtering to remove noise
    _filter.Process2in2out(inLeftSample, inRightSample, numSamples);
}

void Carve::Process2in2out(float* inLeftSample, float* inRightSample, int numSamples) {
    
    // do the waveshaping one sample at a time
    for (int iii {0}; iii < numSamples; iii++) {
        float leftSample {inLeftSample[iii]};
        float rightSample {inRightSample[iii]};
        
        // stereo mode processing
        if (isStereo) {
            leftSample = DSPUnit1.process(leftSample);
            rightSample = DSPUnit2.process(rightSample);
        } else { // non stereo mode processing
            leftSample = ProcessSerial(leftSample) * (1 - routing) + ProcessParallel(leftSample) * routing;
            rightSample = ProcessSerial(rightSample) * (1 - routing) + ProcessParallel(rightSample) * routing;
        }
        
        // dry level and master vol
        ProcessMaster(leftSample, &inLeftSample[iii]);
        ProcessMaster(rightSample, &inRightSample[iii]);
    }
    
    
    // apply filtering to remove noise
    _filter.Process2in2out(inLeftSample, inRightSample, numSamples);
}
