/*
 *	File:		Carve.h
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

#ifndef CARVE_H_INCLUDED
#define CARVE_H_INCLUDED

#include "CarveDSP/CarveDSPUnit.h"
#include "CarveDSP/CarveNoiseFilter.h"
#include "ParameterData.h"
#include "../JuceLibraryCode/JuceHeader.h"

class Carve {
public:
    Carve();
    ~Carve();

    WECore::Carve::CarveDSPUnit<double> DSPUnit1, DSPUnit2;


    /* Process1in1out
     *
     * Performs the effect processing on inSample. Use for mono in->mono out signals.
     *
     * args: inSample   Pointer to the sample to be processed
     *       numSamples      Number of samples loaded into the buffer
     */
    void Process1in1out(float* inSample, int numSamples);

    /* Process1in2out
     *
     * Performs the effect processing on inLeftSample. Provides stereo processing for
     * mono in->stereo out signals by processing inLeftSample differently for the left
     * and right samples.
     *
     * args: inLeftSample    Pointer to the sample to be processed
     *       inRightSample   Pointer to a location in an empty sample buffer
     *       numSamples      Number of samples loaded into the buffer
     */
    void Process1in2out(float* inLeftSample, float* inRightSample, int numSamples);

    /* Process2in2out
     *
     * Performs the effect processing on inLeftSample and inRightSample. Use for
     * stereo in->stereo out signals.
     *
     * args: inLeftSample    Pointer to the left sample to be processed
     *       inRightSample   Pointer to the right sample to be processed
     *       numSamples      Number of samples loaded into the buffer
     */
    void Process2in2out(float* inLeftSample, float* inRightSample, int numSamples);

    void reset();

    double getRouting() const { return routing; }
    bool getStereo() const { return isStereo; }
    double getDryLevel() const { return dryLevel; }
    double getOutputGain() const { return outputGain; }

    void setRouting(double val) { routing = ROUTING.BoundsCheck(val); }
    void setStereo(bool val) { isStereo = val; }
    void setDryLevel(double val) { dryLevel = DRYLEVEL.BoundsCheck(val); }
    void setOutputGain(double val) { outputGain = OUTPUTGAIN.BoundsCheck(val); }
    void setSampleRate(double sampleRate);

private:
    double  routing,
            dryLevel,
            outputGain;

    bool    isStereo;

    WECore::Carve::NoiseFilter<float> _filter;

    double _processGainAndDry(double processedSample, double drySample);

    double _process1ChannelMonoMode(double inSample);
    double _process1ChannelStereoMode(double inSample, WECore::Carve::CarveDSPUnit<double>& dspUnit);
};

#endif  // CARVE_H_INCLUDED
