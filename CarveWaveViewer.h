/*
 *    File:       CarveWaveViewer.hpp
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

#pragma once

#include "JuceHeader.h"
#include "CarveDSP/CarveDSPUnit.h"

class CarveWaveViewer : public Component {
public:
    CarveWaveViewer() = default;
    
    void setMode(int wave) { _dspUnit.setMode(wave); }
    void setPreGain(double preGain) { _dspUnit.setPreGain(preGain); }
    void setPostGain(double postGain) { _dspUnit.setPostGain(postGain); }
    void setTweak(double tweak) { _dspUnit.setTweak(tweak); }

    virtual void paint(Graphics& g);
    
    enum ColourIds
    {
        highlightColourId = 0x1201200
    };
    
private:
    WECore::Carve::CarveDSPUnit<double> _dspUnit;
};
