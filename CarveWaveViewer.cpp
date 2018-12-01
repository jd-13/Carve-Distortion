/*
 *    File:       CarveWaveViewer.cpp
 *
 *    Version:    2.0.0
 *
 *    Created:    26/11/2018
 *
 *    This file is part of Carve.
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
#include "CarveWaveViewer.h"

void CarveWaveViewer::paint(Graphics &g) {
    
    // Sample the behaviour of the dsp unit through the values -1 to 1,
    // drawing it on a path
    constexpr int NUM_SAMPLES {25};
    constexpr float RANGE {2};
    constexpr float INCREMENT {RANGE / NUM_SAMPLES};
    
    Path p;
    for (size_t idx {0}; idx < NUM_SAMPLES; idx++) {
        // Get the sample for this value
        const double sample {_dspUnit.process(-1 + idx * INCREMENT)};
        
        // Scale the sample to the height of this component
        const double sampleX {(static_cast<double>(idx) / NUM_SAMPLES) * getWidth()};
        const double sampleY {((sample + 1) / RANGE) * getHeight()};
        
        // Add it to the path
        if (idx == 0) {
            p.startNewSubPath(0, sampleY);
        } else {
            p.lineTo(sampleX, sampleY);
        }
    }

    g.setColour(findColour(highlightColourId));
    g.strokePath(p, PathStrokeType(2.0f));
    
}
