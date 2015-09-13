/*
 *	File:		Carve.cpp
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

#include "Carve.h"

Carve::Carve() : DSPUnit1(), DSPUnit2(), routing(ROUTING_DEFAULT) {
}

Carve::~Carve(){}

inline float Carve::ProcessSerial(float inSample) {
    return DSPUnit2.process(DSPUnit1.process(inSample));
}

inline float Carve::ProcessParallel(float inSample) {
    return DSPUnit1.process(inSample) + DSPUnit2.process(inSample);
}

void Carve::ClockProcess(float* leftSample, float* rightSample) {
    
    *leftSample = ProcessSerial(*leftSample) * (1 - routing) + ProcessParallel(*leftSample) * routing;
    *rightSample = ProcessSerial(*rightSample) * (1 - routing) + ProcessParallel(*rightSample) * routing;
}