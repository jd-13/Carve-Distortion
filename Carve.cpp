/*
  ==============================================================================

    Carve.cpp
    Created: 9 Sep 2015 9:12:41pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "Carve.h"
#include "ParameterData.h"

Carve::Carve() : DSPUnit1() {
}

Carve::~Carve(){}

void Carve::ClockProcess(float* leftSample, float* rightSample) {
    *leftSample = DSPUnit1.process(*leftSample);
    *rightSample = DSPUnit1.process(*rightSample);
}