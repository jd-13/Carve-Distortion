/*
  ==============================================================================

    Carve.h
    Created: 9 Sep 2015 9:12:58pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef CARVE_H_INCLUDED
#define CARVE_H_INCLUDED

#include "CarveDSPUnit.h"

class Carve {
public:
    Carve();
    ~Carve();
    
    void ClockProcess(float* leftSample, float* rightSample);
    
    CarveDSPUnit DSPUnit1;
};



#endif  // CARVE_H_INCLUDED
