/*
 *	File:		CarveDSPUnit.h
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


#ifndef Carve_CarveDSPUnit_h
#define Carve_CarveDSPUnit_h

#define _USE_MATH_DEFINES

#include "math.h"
#include "ParameterData.h"

class CarveDSPUnit {
private:
    float   preGain,
            postGain,
            tweak;
    
    int mode;
    
    template<typename T>
    T boundsCheck(T param, T min, T max) {
        if (param < min) param = min;
        if (param > max) param = max;
        
        return param;
    }
    
    // private process methods
    float processSine(float inSample) const;
    
    float processParabolicSoft(float inSample) const;
    
    float processParabolicHard(float inSample) const;
    
    float processAsymmetricSine(float inSample) const;
    
    float processExponent(float inSample) const;
    
    float processClipper(float inSample) const;
    
public:
    CarveDSPUnit();
    
    // set parameter methods, w/ integrated bounds checks
    void setMode(int val);
    
    void setPreGain(float val);
    
    void setPostGain(float val);
    
    void setTweak(float val);
    
    // get parameter methods
    int getMode() { return mode; }
    
    float getPreGain() { return preGain; }
    
    float getPostGain() { return postGain; }
    
    float getTweak() { return tweak; }
    
    /* process
     *
     * Performs the processing on the sample, by calling the appropriate
     * private processing methods.
     *
     * args:   inSample    The value of the sample to process
     * 
     * return: The value of inSample after processing
     */
    float process (float inSample) const;
};

#endif
