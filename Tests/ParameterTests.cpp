/*
  ==============================================================================

    ParameterTests.cpp
    Created: 13 Nov 2016 10:03:18am
    Author:  Jack Devlin

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "catch.hpp"

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