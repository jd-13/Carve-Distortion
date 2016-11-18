/*
  ==============================================================================

    ParameterTests.cpp
    Created: 13 Nov 2016 10:03:18am
    Author:  Jack Devlin

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "catch.hpp"
#include "CoreTestLib.h"

SCENARIO("Parameters can be set and retrieved correctly") {
    GIVEN("A new CarveAudioProcessor object") {
        CarveAudioProcessor mProcessor;
        
        WHEN("Nothing is changed") {
            THEN("Parameters have their default values") {
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::mode1) == 1);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::preGain1) == 0.5f);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::postGain1) == 0.25f);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::tweak1) == 0.5f);
                
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::mode2) == 1);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::preGain2) == 0.5f);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::postGain2) == 0.25f);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::tweak2) == 0.5f);
                
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::routing) == 0);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::stereo) == 0);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::dryLevel) == 0);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::masterVol) == 0.5f);

            }
        }
        
        WHEN("All parameters are changed to unique values") {
            mProcessor.setParameter(CarveAudioProcessor::mode1, 1);
            mProcessor.setParameter(CarveAudioProcessor::preGain1, 0.02);
            mProcessor.setParameter(CarveAudioProcessor::postGain1, 0.03);
            mProcessor.setParameter(CarveAudioProcessor::tweak1, 0.04);
            
            mProcessor.setParameter(CarveAudioProcessor::mode2, 2);
            mProcessor.setParameter(CarveAudioProcessor::preGain2, 0.22);
            mProcessor.setParameter(CarveAudioProcessor::postGain2, 0.23);
            mProcessor.setParameter(CarveAudioProcessor::tweak2, 0.24);
            
            mProcessor.setParameter(CarveAudioProcessor::routing, 0.31);
            mProcessor.setParameter(CarveAudioProcessor::stereo, 0);
            mProcessor.setParameter(CarveAudioProcessor::dryLevel, 0.33);
            mProcessor.setParameter(CarveAudioProcessor::masterVol, 0.34);
            
            THEN("They all get their correct unique values") {
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::mode1) == 1);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::preGain1) == 0.02f);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::postGain1) == 0.03f);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::tweak1) == 0.04f);
                
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::mode2) == 2);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::preGain2) == 0.22f);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::postGain2) == 0.23f);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::tweak2) == 0.24f);
                
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::routing) == 0.31f);
                //REQUIRE(mProcessor.getParameter(CarveAudioProcessor::stereo) == 0); KNOWN ISSUE: may need to invert some logic
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::dryLevel) == 0.33f);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::masterVol) == 0.34f);
            }
        }
    }
}

SCENARIO("Parameters enforce their bounds correctly") {
    GIVEN("A new CarveAudioProcessor object") {
        CarveAudioProcessor mProcessor;
        
        WHEN("All parameter values are too low") {
            mProcessor.setParameter(CarveAudioProcessor::mode1, -1);
            mProcessor.setParameter(CarveAudioProcessor::preGain1, -1);
            mProcessor.setParameter(CarveAudioProcessor::postGain1, -1);
            mProcessor.setParameter(CarveAudioProcessor::tweak1, -1);
            
            mProcessor.setParameter(CarveAudioProcessor::mode2, -1);
            mProcessor.setParameter(CarveAudioProcessor::preGain2, -1);
            mProcessor.setParameter(CarveAudioProcessor::postGain2, -1);
            mProcessor.setParameter(CarveAudioProcessor::tweak2, -1);
            
            mProcessor.setParameter(CarveAudioProcessor::routing, -1);
            mProcessor.setParameter(CarveAudioProcessor::stereo, -1);
            mProcessor.setParameter(CarveAudioProcessor::dryLevel, -1);
            mProcessor.setParameter(CarveAudioProcessor::masterVol, -1);
            
            THEN("Parameters enforce their lower bounds") {
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::mode1) == 1);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::preGain1) == 0);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::postGain1) == 0);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::tweak1) == 0);
                
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::mode2) == 1);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::preGain2) == 0);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::postGain2) == 0);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::tweak2) == 0);
                
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::routing) == 0);
                //REQUIRE(mProcessor.getParameter(CarveAudioProcessor::stereo) == 1); KNOWN ISSUE: may need to invert some logic
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::dryLevel) == 0);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::masterVol) == 0);
            }
        }
        
        WHEN("All parameter values are too high") {
            mProcessor.setParameter(CarveAudioProcessor::mode1, 10);
            mProcessor.setParameter(CarveAudioProcessor::preGain1, 2);
            mProcessor.setParameter(CarveAudioProcessor::postGain1, 2);
            mProcessor.setParameter(CarveAudioProcessor::tweak1, 2);
            
            mProcessor.setParameter(CarveAudioProcessor::mode2, 10);
            mProcessor.setParameter(CarveAudioProcessor::preGain2, 2);
            mProcessor.setParameter(CarveAudioProcessor::postGain2, 2);
            mProcessor.setParameter(CarveAudioProcessor::tweak2, 2);
            
            mProcessor.setParameter(CarveAudioProcessor::routing, 2);
            mProcessor.setParameter(CarveAudioProcessor::stereo, 2);
            mProcessor.setParameter(CarveAudioProcessor::dryLevel, 2);
            mProcessor.setParameter(CarveAudioProcessor::masterVol, 2);
            
            THEN("Parameters enforce their upper bounds") {
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::mode1) == 7);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::preGain1) == 1);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::postGain1) == 1);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::tweak1) == 1);
                
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::mode2) == 7);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::preGain2) == 1);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::postGain2) == 1);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::tweak2) == 1);
                
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::routing) == 1);
                //REQUIRE(mProcessor.getParameter(CarveAudioProcessor::stereo) == 1); KNOWN ISSUE: may need to invert some logic
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::dryLevel) == 1);
                REQUIRE(mProcessor.getParameter(CarveAudioProcessor::masterVol) == 1);
            }
        }
    }
}

SCENARIO("Parameter combinations that should result in silence output for any input") {
    GIVEN("A new CarveAudioProcessor object and a 400Hz sine wave") {
        AudioSampleBuffer mSampleBuffer(2, 1024);
        CarveAudioProcessor mProcessor;
        
        // turn both units on
        mProcessor.setParameter(CarveAudioProcessor::mode1, 2);
        mProcessor.setParameter(CarveAudioProcessor::mode2, 2);
        
        const int sampleRate {44100};
        
        ToneGeneratorAudioSource sineGenerator;
        sineGenerator.setAmplitude(0.5);
        sineGenerator.setFrequency(400);
        
        WHEN("The master vol is set to 0 and audio is processed") {
            sineGenerator.prepareToPlay(mSampleBuffer.getNumSamples(), sampleRate);
            sineGenerator.getNextAudioBlock(AudioSourceChannelInfo(mSampleBuffer));
            
            mProcessor.setParameter(CarveAudioProcessor::masterVol, 0);
            
            mProcessor.prepareToPlay(sampleRate, mSampleBuffer.getNumSamples());
            MidiBuffer mMidiBuffer;
            mProcessor.processBlock(mSampleBuffer, mMidiBuffer);
            
            THEN("The output is silence") {
                const float* readPointer1 {mSampleBuffer.getReadPointer(0)};
                const float* readPointer2 {mSampleBuffer.getReadPointer(1)};
                
                for (int iii {0}; iii < mSampleBuffer.getNumSamples(); iii++) {
                    REQUIRE(CoreTestLib::compareFloats(readPointer1[iii], 0.0f));
                    REQUIRE(CoreTestLib::compareFloats(readPointer2[iii], 0.0f));
                }
            }
        }
        
        WHEN("The first unit is turned off in a serial configuration") {
            sineGenerator.prepareToPlay(mSampleBuffer.getNumSamples(), sampleRate);
            sineGenerator.getNextAudioBlock(AudioSourceChannelInfo(mSampleBuffer));
            
            mProcessor.setParameter(CarveAudioProcessor::masterVol, 0.5);
            mProcessor.setParameter(CarveAudioProcessor::mode1, 1);
            
            mProcessor.prepareToPlay(sampleRate, mSampleBuffer.getNumSamples());
            MidiBuffer mMidiBuffer;
            mProcessor.processBlock(mSampleBuffer, mMidiBuffer);
            
            THEN("The output is silence") {
                const float* readPointer1 {mSampleBuffer.getReadPointer(0)};
                const float* readPointer2 {mSampleBuffer.getReadPointer(1)};
                
                for (int iii {0}; iii < mSampleBuffer.getNumSamples(); iii++) {
                    REQUIRE(CoreTestLib::compareFloats(readPointer1[iii], 0.0f));
                    REQUIRE(CoreTestLib::compareFloats(readPointer2[iii], 0.0f));
                }
            }
        }
        
        WHEN("The second unit is turned off in a serial configuration") {
            sineGenerator.prepareToPlay(mSampleBuffer.getNumSamples(), sampleRate);
            sineGenerator.getNextAudioBlock(AudioSourceChannelInfo(mSampleBuffer));
            
            mProcessor.setParameter(CarveAudioProcessor::mode1, 2);
            mProcessor.setParameter(CarveAudioProcessor::mode2, 1);
            
            mProcessor.prepareToPlay(sampleRate, mSampleBuffer.getNumSamples());
            MidiBuffer mMidiBuffer;
            mProcessor.processBlock(mSampleBuffer, mMidiBuffer);
            
            THEN("The output is silence") {
                const float* readPointer1 {mSampleBuffer.getReadPointer(0)};
                const float* readPointer2 {mSampleBuffer.getReadPointer(1)};
                
                for (int iii {0}; iii < mSampleBuffer.getNumSamples(); iii++) {
                    REQUIRE(CoreTestLib::compareFloats(readPointer1[iii], 0.0f));
                    REQUIRE(CoreTestLib::compareFloats(readPointer2[iii], 0.0f));
                }
            }
        }
        
        WHEN("Both units are turned off in a parallel configuration") {
            sineGenerator.prepareToPlay(mSampleBuffer.getNumSamples(), sampleRate);
            sineGenerator.getNextAudioBlock(AudioSourceChannelInfo(mSampleBuffer));
            
            mProcessor.setParameter(CarveAudioProcessor::mode1, 1);
            mProcessor.setParameter(CarveAudioProcessor::mode2, 1);
            mProcessor.setParameter(CarveAudioProcessor::routing, 1);
            
            mProcessor.prepareToPlay(sampleRate, mSampleBuffer.getNumSamples());
            MidiBuffer mMidiBuffer;
            mProcessor.processBlock(mSampleBuffer, mMidiBuffer);
            
            THEN("The output is silence") {
                const float* readPointer1 {mSampleBuffer.getReadPointer(0)};
                const float* readPointer2 {mSampleBuffer.getReadPointer(1)};
                
                for (int iii {0}; iii < mSampleBuffer.getNumSamples(); iii++) {
                    REQUIRE(CoreTestLib::compareFloats(readPointer1[iii], 0.0f));
                    REQUIRE(CoreTestLib::compareFloats(readPointer2[iii], 0.0f));
                }
            }
        }
        
        WHEN("Both units are on but have 0 pregain in a parallel configuration") {
            sineGenerator.prepareToPlay(mSampleBuffer.getNumSamples(), sampleRate);
            sineGenerator.getNextAudioBlock(AudioSourceChannelInfo(mSampleBuffer));
            
            mProcessor.setParameter(CarveAudioProcessor::mode1, 2);
            mProcessor.setParameter(CarveAudioProcessor::mode2, 2);
            mProcessor.setParameter(CarveAudioProcessor::preGain1, 0);
            mProcessor.setParameter(CarveAudioProcessor::preGain2, 0);
            
            mProcessor.prepareToPlay(sampleRate, mSampleBuffer.getNumSamples());
            MidiBuffer mMidiBuffer;
            mProcessor.processBlock(mSampleBuffer, mMidiBuffer);
            
            THEN("The output is silence") {
                const float* readPointer1 {mSampleBuffer.getReadPointer(0)};
                const float* readPointer2 {mSampleBuffer.getReadPointer(1)};
                
                for (int iii {0}; iii < mSampleBuffer.getNumSamples(); iii++) {
                    REQUIRE(CoreTestLib::compareFloats(readPointer1[iii], 0.0f));
                    REQUIRE(CoreTestLib::compareFloats(readPointer2[iii], 0.0f));
                }
            }
        }
        
        WHEN("Both units are on but have 0 postgain in a parallel configuration") {
            sineGenerator.prepareToPlay(mSampleBuffer.getNumSamples(), sampleRate);
            sineGenerator.getNextAudioBlock(AudioSourceChannelInfo(mSampleBuffer));
            
            mProcessor.setParameter(CarveAudioProcessor::preGain1, 0.5);
            mProcessor.setParameter(CarveAudioProcessor::preGain2, 0.5);
            mProcessor.setParameter(CarveAudioProcessor::postGain1, 0);
            mProcessor.setParameter(CarveAudioProcessor::postGain2, 0);
            
            mProcessor.prepareToPlay(sampleRate, mSampleBuffer.getNumSamples());
            MidiBuffer mMidiBuffer;
            mProcessor.processBlock(mSampleBuffer, mMidiBuffer);
            
            THEN("The output is silence") {
                const float* readPointer1 {mSampleBuffer.getReadPointer(0)};
                const float* readPointer2 {mSampleBuffer.getReadPointer(1)};
                
                for (int iii {0}; iii < mSampleBuffer.getNumSamples(); iii++) {
                    REQUIRE(CoreTestLib::compareFloats(readPointer1[iii], 0.0f));
                    REQUIRE(CoreTestLib::compareFloats(readPointer2[iii], 0.0f));
                }
            }
        }
    }
}

SCENARIO("Parameter combinations that should result in left or right channel silence output for any input") {
    GIVEN("A new CarveAudioProcessor object and a 400Hz sine wave") {
        AudioSampleBuffer mSampleBuffer(2, 1024);
        CarveAudioProcessor mProcessor;
        
        // turn both units on
        mProcessor.setParameter(CarveAudioProcessor::mode1, 2);
        mProcessor.setParameter(CarveAudioProcessor::mode2, 2);
        
        mProcessor.setParameter(CarveAudioProcessor::stereo, 0);
        
        const int sampleRate {44100};
        
        ToneGeneratorAudioSource sineGenerator;
        sineGenerator.setAmplitude(0.5);
        sineGenerator.setFrequency(400);
        
        float expectedValues[] {-1.12493e-08, 0.0250704, 0.0779938, 0.118302, 0.157725, 0.199625, 0.232654, 0.268783, 0.297762, 0.32561, 0.350111, 0.370029, 0.388864, 0.402269, 0.41483, 0.423125, 0.429825, 0.434059, 0.436101, 0.437082, 0.435947, 0.434447, 0.431473, 0.428304, 0.424468, 0.420414, 0.416308, 0.411976, 0.407858, 0.403555, 0.399406, 0.395077, 0.390629, 0.385872, 0.38061, 0.374734, 0.367914, 0.360029, 0.350732, 0.339842, 0.32707, 0.312188, 0.294995, 0.275277, 0.252923, 0.227804, 0.199906, 0.169234, 0.135887, 0.100024, 0.0618686, 0.0217248, -0.02006, -0.0630676, -0.106853, -0.150929, -0.194799, -0.237965, -0.279937, -0.32026, -0.358511, -0.394329, -0.427405, -0.457503, -0.484458, -0.508175, -0.528633, -0.545876, -0.560009, -0.571193, -0.579629, -0.585556, -0.589236, -0.590949, -0.590976, -0.589599, -0.587088, -0.583693, -0.579645, -0.575143, -0.570355, -0.565415, -0.560417, -0.555421, -0.550444, -0.545466, -0.540429, -0.535237, -0.52976, -0.523835, -0.517271, -0.509854, -0.501348, -0.491508, -0.480081, -0.466816, -0.451475, -0.433838, -0.413716, -0.390959, -0.365463, -0.337181, -0.306127, -0.272384, -0.236101, -0.197499, -0.156867, -0.114552, -0.0709588, -0.0265349, 0.0182408, 0.0628712, 0.106856, 0.149706, 0.190958, 0.230188, 0.267023, 0.30115, 0.332323, 0.360366, 0.385178, 0.406727, 0.42505, 0.440245, 0.452466, 0.46191, 0.468811, 0.473429, 0.476042, 0.476933, 0.476382, 0.474662, 0.472027, 0.468709, 0.464911, 0.460806, 0.456532, 0.452189, 0.44784, 0.443508, 0.439178, 0.434795, 0.43027, 0.425475, 0.420253, 0.414415, 0.40775, 0.400024, 0.390993, 0.380405, 0.368007, 0.35356, 0.336842, 0.317658, 0.295853, 0.271318, 0.243997, 0.213897, 0.181091, 0.145722, 0.108, 0.0682051, 0.0266798, -0.0161789, -0.0599284, -0.104093, -0.148177, -0.191679, -0.234108, -0.274998, -0.313918, -0.350489, -0.384389, -0.415363, -0.443228, -0.467873, -0.489256, -0.507408, -0.522418, -0.534434, -0.543648, -0.55029, -0.554618, -0.556908, -0.557441, -0.5565, -0.554359, -0.551274, -0.547479, -0.543184, -0.538564, -0.533761, -0.528881, -0.523991, -0.519119, -0.514254, -0.509349, -0.504315, -0.499032, -0.493344, -0.487068, -0.479993, -0.471891, -0.462516, -0.451616, -0.438941, -0.424248, -0.407311, -0.387933, -0.365953, -0.341255, -0.313777, -0.283518, -0.250541, -0.214981, -0.17704, -0.13699, -0.0951652, -0.0519564, -0.00780119, 0.036828, 0.0814373, 0.125526, 0.1686, 0.210189, 0.249858, 0.28722, 0.321947, 0.353774, 0.382509, 0.408031, 0.430292, 0.449312, 0.465175, 0.47802, 0.488036, 0.495447, 0.500509, 0.503496, 0.504689, 0.504372, 0.502819, 0.500289, 0.497021, 0.493225, 0.489083, 0.48474, 0.480307, 0.475856, 0.471421, 0.466994, 0.462533, 0.457955, 0.453143, 0.447945, 0.442182, 0.435647, 0.428111, 0.419332, 0.409059, 0.39704, 0.38303, 0.366802, 0.348154, 0.32692, 0.302978, 0.276259, 0.246753, 0.214518, 0.179676, 0.142423, 0.103021, 0.0617982, 0.019138, -0.0245272, -0.0687285, -0.112974, -0.156762, -0.199599, -0.24101, -0.280554, -0.317838, -0.352525, -0.384344, -0.413093, -0.438642, -0.460933, -0.479979, -0.495856, -0.508696, -0.518681, -0.526035, -0.531008, -0.533872, -0.534909, -0.534402, -0.532627, -0.529845, -0.526298, -0.5222, -0.517737, -0.513058, -0.508279, -0.503477, -0.498689, -0.493915, -0.489116, -0.484213, -0.479094, -0.473612, -0.46759, -0.460824, -0.453089, -0.444143, -0.433736, -0.421616, -0.407536, -0.391267, -0.372603, -0.351372, -0.327448, -0.300754, -0.271273, -0.239052, -0.204207, -0.166925, -0.127458, -0.0861276, -0.0433105, 0.000566453, 0.0450382, 0.0896149, 0.133796, 0.177085, 0.219003, 0.259107, 0.296996, 0.332325, 0.364815, 0.394254, 0.420504, 0.443498, 0.463241, 0.479799, 0.493301, 0.503921, 0.511879, 0.517422, 0.52082, 0.522353, 0.522306, 0.520956, 0.518567, 0.515381, 0.511619, 0.507468, 0.503084, 0.498585, 0.494055, 0.489535, 0.485029, 0.480504, 0.475886, 0.471066, 0.465902, 0.46022, 0.45382, 0.446479, 0.437956, 0.428003, 0.416366, 0.402798, 0.387067, 0.368964, 0.348313, 0.32498, 0.298883, 0.269995, 0.238357, 0.204075, 0.167327, 0.128359, 0.0874816, 0.0450666, 0.00153483, -0.0426528, -0.0870088, -0.131033, -0.174228, -0.216112, -0.256235, -0.294192, -0.329631, -0.362262, -0.391867, -0.418297, -0.441477, -0.461402, -0.478133, -0.491789, -0.502542, -0.510603, -0.516218, -0.519655, -0.521194, -0.521118, -0.519705, -0.517223, -0.513917, -0.510009, -0.505692, -0.501125, -0.496433, -0.491701, -0.486979, -0.482273, -0.477555, -0.472757, -0.467773, -0.462467, -0.456667, -0.450176, -0.442773, -0.434222, -0.424272, -0.412671, -0.399171, -0.383537, -0.365557, -0.34505, -0.321875, -0.295945, -0.267225, -0.235747, -0.20161, -0.164982, -0.1261, -0.0852683, -0.0428502, 0.000738579, 0.0450414, 0.0895734, 0.133835, 0.177328, 0.219568, 0.2601, 0.298513, 0.334447, 0.367605, 0.397759, 0.424751, 0.448498, 0.468987, 0.486268, 0.500456, 0.511716, 0.520254, 0.526314, 0.530159, 0.53207, 0.53233, 0.531219, 0.529003, 0.525934, 0.522236, 0.518105, 0.513705, 0.509166, 0.504577, 0.499992, 0.495424, 0.490849, 0.486203, 0.481386, 0.476264, 0.47067, 0.46441, 0.457267, 0.449004, 0.439373, 0.428122, 0.415001, 0.399773, 0.382223, 0.362166, 0.339455, 0.313996, 0.285747, 0.254732, 0.22104, 0.184831, 0.146335, 0.105845, 0.0637208, 0.0203701, -0.0237546, -0.0681711, -0.112381, -0.155885, -0.198195, -0.238854, -0.277443, -0.313596, -0.347008, -0.37744, -0.404728, -0.428778, -0.449568, -0.467143, -0.481607, -0.493121, -0.501887, -0.508142, -0.512151, -0.514191, -0.514545, -0.513494, -0.511307, -0.508238, -0.504513, -0.500334, -0.495869, -0.49125, -0.486574, -0.481898, -0.47724, -0.472581, -0.467862, -0.462988, -0.457827, -0.452219, -0.445971, -0.438868, -0.430677, -0.42115, -0.410035, -0.397082, -0.382052, -0.364726, -0.344914, -0.322466, -0.297279, -0.269304, -0.238558, -0.205121, -0.169144, -0.130847, -0.0905189, -0.0485078, -0.00521779, 0.0389038, 0.0833779, 0.127707, 0.171392, 0.213942, 0.254896, 0.293828, 0.330365, 0.364195, 0.395072, 0.42282, 0.447337, 0.468592, 0.486622, 0.501524, 0.513453, 0.522605, 0.529216, 0.533545, 0.535868, 0.53647, 0.535632, 0.533625, 0.530703, 0.527099, 0.523016, 0.518627, 0.514069, 0.509443, 0.504811, 0.500197, 0.495586, 0.490923, 0.486118, 0.481045, 0.475544, 0.469429, 0.462486, 0.454484, 0.445178, 0.434314, 0.421642, 0.406922, 0.389931, 0.370475, 0.348398, 0.323592, 0.296001, 0.265631, 0.232556, 0.196918, 0.158929, 0.118868, 0.077076, 0.0339518, -0.0100626, -0.0544913, -0.0988386, -0.142604, -0.185295, -0.226447, -0.265628, -0.302458, -0.336618, -0.367851, -0.395975, -0.420876, -0.442517, -0.460925, -0.476191, -0.488461, -0.497929, -0.504825, -0.509406, -0.511948, -0.512733, -0.512043, -0.510152, -0.507316, -0.503771, -0.499724, -0.495351, -0.490795, -0.486162, -0.481517, -0.47689, -0.47227, -0.467608, -0.462817, -0.457776, -0.45233, -0.446295, -0.439461, -0.431598, -0.422462, -0.411802, -0.399364, -0.384908, -0.368208, -0.349066, -0.327321, -0.302857, -0.275613, -0.245587, -0.212843, -0.177515, -0.139806, -0.0999864, -0.0583915, -0.0154121, 0.0285144, 0.0729155, 0.117297, 0.161159, 0.204007, 0.24537, 0.284814, 0.321952, 0.356455, 0.388059, 0.416572, 0.441873, 0.463913, 0.482712, 0.498355, 0.510981, 0.520778, 0.527972, 0.532817, 0.535587, 0.536564, 0.536031, 0.534263, 0.531519, 0.528038, 0.524029, 0.519674, 0.51512, 0.510477, 0.505815, 0.50117, 0.496534, 0.491865, 0.487079, 0.482059, 0.476655, 0.470686, 0.463946, 0.456205, 0.447222, 0.436745, 0.424523, 0.410311, 0.393881, 0.375032, 0.353598, 0.329456, 0.302538, 0.272834, 0.240401, 0.205362, 0.167912, 0.128314, 0.0868958, 0.0440407, 0.000181273, -0.0442136, -0.088652, -0.132633, -0.175662, -0.217263, -0.256998, -0.294472, -0.329349, -0.361357, -0.390294, -0.41603, -0.438508, -0.45774, -0.473802, -0.486828, -0.496998, -0.504536, -0.509692, -0.512739, -0.513958, -0.513632, -0.512038, -0.509436, -0.506069, -0.502151, -0.497866, -0.493365, -0.488764, -0.484138, -0.479526, -0.474928, -0.470303, -0.465575, -0.46063, -0.455321, -0.449472, -0.442878, -0.435314, -0.426539, -0.416303, -0.404352, -0.390441, -0.374341, -0.355845, -0.334782, -0.311025, -0.284497, -0.255181, -0.223125, -0.188445, -0.151326, -0.112023, -0.0708552, -0.0282002, 0.0155151, 0.0598258, 0.104242, 0.148263, 0.191393, 0.233153, 0.273098, 0.310829, 0.346001, 0.378335, 0.407618, 0.433712, 0.456552, 0.47614, 0.492545, 0.505894, 0.516362, 0.524168, 0.529559, 0.532806, 0.53419, 0.533993, 0.532494, 0.529956, 0.526622, 0.522712, 0.518415, 0.513884, 0.50924, 0.504564, 0.499899, 0.49525, 0.49058, 0.485819, 0.480857, 0.475551, 0.469728, 0.463187, 0.455706, 0.447043, 0.43695, 0.425175, 0.411469, 0.395601, 0.377361, 0.356573, 0.333104, 0.306871, 0.277849, 0.246076, 0.211661, 0.174779, 0.135678, 0.094669, 0.0521223, 0.00845944, -0.0358588, -0.0803448, -0.124499, -0.167822, -0.209835, -0.250086, -0.288171, -0.323736, -0.356494, -0.386224, -0.41278, -0.436085, -0.456134, -0.472989, -0.486768, -0.497643, -0.505827, -0.511564, -0.515122, -0.516781, -0.516825, -0.515532, -0.513169, -0.509981, -0.506192, -0.501992, -0.497543, -0.492967, -0.488351, -0.483744, -0.479153, -0.47455, -0.469865, -0.464995, -0.459802, -0.454114, -0.447735, -0.440444, -0.432004, -0.422164, -0.410673, -0.397283, -0.381758, -0.363886, -0.343487, -0.32042, -0.294596, -0.265983, -0.234611, -0.20058, -0.164056, -0.125279, -0.0845512, -0.0422366, 0.00124907, 0.0454494, 0.0898793, 0.13404, 0.177431, 0.219571, 0.260003, 0.298316, 0.33415, 0.36721, 0.397265, 0.42416, 0.44781, 0.468201, 0.485387, 0.499479, 0.510643, 0.519087, 0.525052, 0.528803, 0.530621, 0.530788, 0.529584, 0.527276, 0.524116, 0.520326, 0.516105, 0.511615, 0.506985, 0.502307, 0.497633, 0.492977, 0.488314, 0.483581, 0.478677, 0.473468, 0.467788, 0.461443, 0.454215, 0.445867, 0.436152, 0.424816, 0.411612, 0.396302, 0.378669, 0.35853, 0.335738, 0.310197, 0.281868, 0.250772, 0.217001, 0.180713, 0.142137, 0.10157, 0.0593669, 0.0159386, -0.0282632, -0.0727564, -0.117043, -0.160622, -0.203008, -0.243742, -0.282406, -0.318633, -0.352118, -0.382623, -0.409984, -0.434107, -0.454969, -0.472615, -0.48715, -0.498735, -0.50757, -0.513896, -0.517974, -0.520083, -0.520505, -0.519522, -0.517404, -0.514401, -0.510744, -0.506631, -0.502232, -0.497679, -0.493068, -0.488457, -0.483864, -0.479269, -0.474613, -0.469802, -0.464704, -0.459158, -0.452972, -0.445931, -0.437801, -0.428335, -0.41728, -0.404387, -0.389417, -0.37215, -0.352397, -0.330007, -0.304877, -0.276961, -0.246272, -0.212891, -0.176971, -0.13873, -0.0984572, -0.0565014, -0.0132661, 0.030801, 0.0752211, 0.119497, 0.163128, 0.205626, 0.246526, 0.285406, 0.321892, 0.355671, 0.386496, 0.414194, 0.43866, 0.459866, 0.477846, 0.4927, 0.504579, 0.513683, 0.520246, 0.524527, 0.526803, 0.527358, 0.526474, 0.52442, 0.521453, 0.517803, 0.513675, 0.509241, 0.504639, 0.499969, 0.495294, 0.490637, 0.485983, 0.481277};
        
        WHEN("The first unit is turned off in stereo mode") {
            sineGenerator.prepareToPlay(mSampleBuffer.getNumSamples(), sampleRate);
            sineGenerator.getNextAudioBlock(AudioSourceChannelInfo(mSampleBuffer));
            
            mProcessor.setParameter(CarveAudioProcessor::mode1, 1);
            
            mProcessor.prepareToPlay(sampleRate, mSampleBuffer.getNumSamples());
            MidiBuffer mMidiBuffer;
            mProcessor.processBlock(mSampleBuffer, mMidiBuffer);
    
            THEN("The output of the left channel is silence") {
                const float* readPointer1 {mSampleBuffer.getReadPointer(0)};
                const float* readPointer2 {mSampleBuffer.getReadPointer(1)};
                
                for (int iii {0}; iii < mSampleBuffer.getNumSamples(); iii++) {
                    REQUIRE(CoreTestLib::compareFloats(readPointer1[iii], 0.0f));
                    REQUIRE(CoreTestLib::compareFloats(readPointer2[iii], expectedValues[iii], CoreTestLib::HIGHER_TOLERANCE));
                }
            }
        }
    
        WHEN("The second unit is turned off in stereo mode") {
            sineGenerator.prepareToPlay(mSampleBuffer.getNumSamples(), sampleRate);
            sineGenerator.getNextAudioBlock(AudioSourceChannelInfo(mSampleBuffer));
            
            mProcessor.setParameter(CarveAudioProcessor::mode1, 2);
            mProcessor.setParameter(CarveAudioProcessor::mode2, 1);
            
            mProcessor.prepareToPlay(sampleRate, mSampleBuffer.getNumSamples());
            MidiBuffer mMidiBuffer;
            mProcessor.processBlock(mSampleBuffer, mMidiBuffer);
            
            THEN("The output of the left channel is silence") {
                const float* readPointer1 {mSampleBuffer.getReadPointer(0)};
                const float* readPointer2 {mSampleBuffer.getReadPointer(1)};
                
                for (int iii {0}; iii < mSampleBuffer.getNumSamples(); iii++) {
                    REQUIRE(CoreTestLib::compareFloats(readPointer1[iii], expectedValues[iii], CoreTestLib::HIGHER_TOLERANCE));
                    REQUIRE(CoreTestLib::compareFloats(readPointer2[iii], 0.0f));
                }
            }
        }
        
        WHEN("Both units are turned on, but the first unit has 0 pregain in stereo mode") {
            sineGenerator.prepareToPlay(mSampleBuffer.getNumSamples(), sampleRate);
            sineGenerator.getNextAudioBlock(AudioSourceChannelInfo(mSampleBuffer));
            
            mProcessor.setParameter(CarveAudioProcessor::mode2, 2);
            mProcessor.setParameter(CarveAudioProcessor::preGain1, 0);
            
            mProcessor.prepareToPlay(sampleRate, mSampleBuffer.getNumSamples());
            MidiBuffer mMidiBuffer;
            mProcessor.processBlock(mSampleBuffer, mMidiBuffer);
            
            THEN("The output of the left channel is silence") {
                const float* readPointer1 {mSampleBuffer.getReadPointer(0)};
                const float* readPointer2 {mSampleBuffer.getReadPointer(1)};
                
                for (int iii {0}; iii < mSampleBuffer.getNumSamples(); iii++) {
                    REQUIRE(CoreTestLib::compareFloats(readPointer1[iii], 0.0f));
                    REQUIRE(CoreTestLib::compareFloats(readPointer2[iii], expectedValues[iii], CoreTestLib::HIGHER_TOLERANCE));
                }
            }
        }
        
        WHEN("Both units are turned on, but the second unit has 0 pregain in stereo mode") {
            sineGenerator.prepareToPlay(mSampleBuffer.getNumSamples(), sampleRate);
            sineGenerator.getNextAudioBlock(AudioSourceChannelInfo(mSampleBuffer));
            
            mProcessor.setParameter(CarveAudioProcessor::preGain1, 0.5);
            mProcessor.setParameter(CarveAudioProcessor::preGain2, 0);
            
            mProcessor.prepareToPlay(sampleRate, mSampleBuffer.getNumSamples());
            MidiBuffer mMidiBuffer;
            mProcessor.processBlock(mSampleBuffer, mMidiBuffer);
            
            THEN("The output of the right channel is silence") {
                const float* readPointer1 {mSampleBuffer.getReadPointer(0)};
                const float* readPointer2 {mSampleBuffer.getReadPointer(1)};
                
                for (int iii {0}; iii < mSampleBuffer.getNumSamples(); iii++) {
                    REQUIRE(CoreTestLib::compareFloats(readPointer1[iii], expectedValues[iii], CoreTestLib::HIGHER_TOLERANCE));
                    REQUIRE(CoreTestLib::compareFloats(readPointer2[iii], 0.0f));
                }
            }
        }
        
        WHEN("Both units are turned on, but the first unit has 0 postgain in stereo mode") {
            sineGenerator.prepareToPlay(mSampleBuffer.getNumSamples(), sampleRate);
            sineGenerator.getNextAudioBlock(AudioSourceChannelInfo(mSampleBuffer));
            
            mProcessor.setParameter(CarveAudioProcessor::preGain2, 0.5);
            mProcessor.setParameter(CarveAudioProcessor::postGain1, 0);

            
            mProcessor.prepareToPlay(sampleRate, mSampleBuffer.getNumSamples());
            MidiBuffer mMidiBuffer;
            mProcessor.processBlock(mSampleBuffer, mMidiBuffer);
            
            THEN("The output of the left channel is silence") {
                const float* readPointer1 {mSampleBuffer.getReadPointer(0)};
                const float* readPointer2 {mSampleBuffer.getReadPointer(1)};
                
                for (int iii {0}; iii < mSampleBuffer.getNumSamples(); iii++) {
                    REQUIRE(CoreTestLib::compareFloats(readPointer1[iii], 0.0f));
                    REQUIRE(CoreTestLib::compareFloats(readPointer2[iii], expectedValues[iii], CoreTestLib::HIGHER_TOLERANCE));
                }
            }
        }
        
        WHEN("Both units are turned on, but the second unit has 0 postgain in stereo mode") {
            sineGenerator.prepareToPlay(mSampleBuffer.getNumSamples(), sampleRate);
            sineGenerator.getNextAudioBlock(AudioSourceChannelInfo(mSampleBuffer));
            
            mProcessor.setParameter(CarveAudioProcessor::postGain1, 0.25);
            mProcessor.setParameter(CarveAudioProcessor::postGain2, 0);

            
            mProcessor.prepareToPlay(sampleRate, mSampleBuffer.getNumSamples());
            MidiBuffer mMidiBuffer;
            mProcessor.processBlock(mSampleBuffer, mMidiBuffer);
            
            THEN("The output of the left channel is silence") {
                const float* readPointer1 {mSampleBuffer.getReadPointer(0)};
                const float* readPointer2 {mSampleBuffer.getReadPointer(1)};
                
                for (int iii {0}; iii < mSampleBuffer.getNumSamples(); iii++) {
                    REQUIRE(CoreTestLib::compareFloats(readPointer1[iii], expectedValues[iii], CoreTestLib::HIGHER_TOLERANCE));
                    REQUIRE(CoreTestLib::compareFloats(readPointer2[iii], 0.0f));
                }
            }
        }
    }
}

SCENARIO("Silence in = silence out") {
    GIVEN("A CarveAudioProcessor and a buffer of silent samples") {
        AudioSampleBuffer mSampleBuffer(2, 1024);
        CarveAudioProcessor mProcessor;
        
        float* writePointer1 {mSampleBuffer.getWritePointer(0)};
        float* writePointer2 {mSampleBuffer.getWritePointer(1)};
        for (int iii {0}; iii < mSampleBuffer.getNumSamples(); iii++) {
            writePointer1[iii] = 0;
            writePointer2[iii] = 0;
        }
        
        WHEN("The silence samples are processed") {
            mProcessor.prepareToPlay(44100, mSampleBuffer.getNumSamples());
            MidiBuffer mMidiBuffer;
            mProcessor.reset();
            mProcessor.processBlock(mSampleBuffer, mMidiBuffer);
            mProcessor.releaseResources();
            
            THEN("The output is silence") {
                const float* readPointer1 {mSampleBuffer.getReadPointer(0)};
                const float* readPointer2 {mSampleBuffer.getReadPointer(1)};

                for (int iii {0}; iii < mSampleBuffer.getNumSamples(); iii++) {
                    REQUIRE(CoreTestLib::compareFloats(readPointer1[iii], 0.0f));
                    REQUIRE(CoreTestLib::compareFloats(readPointer2[iii], 0.0f));
                }
            }
        }
    }
}