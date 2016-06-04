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
