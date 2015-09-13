/*
 *	File:		Carve.h
 *
 *	Version:	0.02.00
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

#include "CarveDSPUnit.h"
#include "ParameterData.h"

class Carve {
public:
    Carve();
    ~Carve();
    
    CarveDSPUnit DSPUnit1, DSPUnit2;
    
    void ClockProcess(float* leftSample, float* rightSample);
    
    float getRouting() const { return routing; }
    
    void setRouting(float val) { routing = val; }

    
    
private:
    float routing;
    
    inline float ProcessSerial(float inSample);
    
    inline float ProcessParallel(float inSample);
};



#endif  // CARVE_H_INCLUDED