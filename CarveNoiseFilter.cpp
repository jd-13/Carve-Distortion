/*
 *	File:		CarveNoiseFilter.h
 *
 *	Version:	2.0.0
 *
 *	Created:	02/06/2016
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

#include "CarveNoiseFilter.h"

CarveNoiseFilter::CarveNoiseFilter() {
    setSampleRate(44100);
}

void CarveNoiseFilter::setSampleRate(double sampleRate) {
    const int lowCutHz {25};
    const int highCutHz {19000};
    
    monoLowCutFilter.setup(FILTER_ORDER, sampleRate, lowCutHz);
    stereoLowCutFilter.setup(FILTER_ORDER, sampleRate, lowCutHz);
    monoHighCutFilter.setup(FILTER_ORDER, sampleRate, highCutHz);
    stereoHighCutFilter.setup(FILTER_ORDER, sampleRate, highCutHz);
}

void CarveNoiseFilter::reset() {
    monoLowCutFilter.reset();
    monoHighCutFilter.reset();
    stereoLowCutFilter.reset();
    stereoHighCutFilter.reset();
}

void CarveNoiseFilter::ApplyMonoFiltering(float* inSample, int numSamples) {
    monoLowCutFilter.process(numSamples, &inSample);
    monoHighCutFilter.process(numSamples, &inSample);
}

void CarveNoiseFilter::ApplyStereoFiltering(float *inLeftSample, float *inRightSample, int numSamples) {
    float** channelsArray = new float*[2];
    channelsArray[0] = inLeftSample;
    channelsArray[1] = inRightSample;
    stereoLowCutFilter.process(numSamples, channelsArray);
    stereoHighCutFilter.process(numSamples, channelsArray);
    delete [] channelsArray;
}