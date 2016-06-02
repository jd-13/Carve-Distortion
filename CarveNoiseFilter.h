/*
  ==============================================================================

    CarveNoiseFilter.h
    Created: 2 Jun 2016 8:20:08pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef CARVENOISEFILTER_H_INCLUDED
#define CARVENOISEFILTER_H_INCLUDED

#include "DspFilters/Butterworth.h"
#include "../JuceLibraryCode/JuceHeader.h"


class CarveNoiseFilter {
public:
    CarveNoiseFilter();
    
    void setSampleRate(double sampleRate);
    
    void reset();
    
    void ApplyMonoFiltering(float* inSample, int numSamples);
    
    void ApplyStereoFiltering(float* inLeftSample, float* inRightSample, int numSamples);
    
    
    
private:
    static const int FILTER_ORDER {4};
    Dsp::SimpleFilter<Dsp::Butterworth::LowPass<4>, 1> monoHighCutFilter;
    Dsp::SimpleFilter<Dsp::Butterworth::LowPass<4>, 2> stereoHighCutFilter;
    
    Dsp::SimpleFilter<Dsp::Butterworth::HighPass<4>, 1> monoLowCutFilter;
    Dsp::SimpleFilter<Dsp::Butterworth::HighPass<4>, 2> stereoLowCutFilter;
};



#endif  // CARVENOISEFILTER_H_INCLUDED
