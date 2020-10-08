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

Carve::Carve() : routing(ROUTING.defaultValue),
                 dryLevel(DRYLEVEL.defaultValue),
                 outputGain(OUTPUTGAIN.defaultValue),
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

    // Do the waveshaping one sample at a time
    for (int iii {0}; iii < numSamples; iii++) {
        inSample[iii] = _process1ChannelMonoMode(inSample[iii]);
    }

    // Apply filtering to remove noise
    _filter.Process1in1out(inSample, numSamples);
}

void Carve::Process1in2out(float* inLeftSample, float* inRightSample, int numSamples) {

    // Do the waveshaping one sample at a time
    for (int iii {0}; iii < numSamples; iii++) {
        if (isStereo) {
            // Stereo mode processing

            // Do the right sample first as we need an unmodified copy of the left sample to process
            // it once for each channel
            inRightSample[iii] = _process1ChannelStereoMode(inLeftSample[iii], DSPUnit2);
            inLeftSample[iii] = _process1ChannelStereoMode(inLeftSample[iii], DSPUnit1);
        } else {
            // Non stereo mode processing
            inLeftSample[iii] = _process1ChannelMonoMode(inLeftSample[iii]);
            inRightSample[iii] = inLeftSample[iii];
        }
    }

    // Apply filtering to remove noise
    _filter.Process2in2out(inLeftSample, inRightSample, numSamples);
}

void Carve::Process2in2out(float* inLeftSample, float* inRightSample, int numSamples) {

    // Do the waveshaping one sample at a time
    for (int iii {0}; iii < numSamples; iii++) {
        if (isStereo) {
            // Stereo mode processing
            inLeftSample[iii] = _process1ChannelStereoMode(inLeftSample[iii], DSPUnit1);
            inRightSample[iii] = _process1ChannelStereoMode(inRightSample[iii], DSPUnit2);
        } else {
            // Non stereo mode processing
            inLeftSample[iii] = _process1ChannelMonoMode(inLeftSample[iii]);
            inRightSample[iii] = _process1ChannelMonoMode(inRightSample[iii]);
        }
    }

    // Apply filtering to remove noise
    _filter.Process2in2out(inLeftSample, inRightSample, numSamples);
}

double Carve::_processGainAndDry(double processedSample, double drySample) {
    return (processedSample + (dryLevel * drySample)) * outputGain;
}

double Carve::_process1ChannelMonoMode(double inSample) {
    auto processSerial = [this](double inSample) {
        return (DSPUnit2.process(DSPUnit1.process(inSample))) * (1 - routing);
    };

    auto processParallel = [this](double inSample) {
        return (DSPUnit1.process(inSample) + DSPUnit2.process(inSample)) * routing;
    };

    const double processedSample = processSerial(inSample) + processParallel(inSample);
    return _processGainAndDry(processedSample, inSample);
}

double Carve::_process1ChannelStereoMode(double inSample, WECore::Carve::CarveDSPUnit<double>& dspUnit) {
    return _processGainAndDry(dspUnit.process(inSample), inSample);
}
