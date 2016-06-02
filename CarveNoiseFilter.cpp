/*
  ==============================================================================

    CarveNoiseFilter.cpp
    Created: 2 Jun 2016 8:20:08pm
    Author:  Jack Devlin

  ==============================================================================
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