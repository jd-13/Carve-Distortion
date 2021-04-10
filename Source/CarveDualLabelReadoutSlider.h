/*
 *    File:       CarveDualLabelReadoutSlider.h
 *
 *    Version:    2.0.0
 *
 *    Created:    08/07/2020
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
#include "CoreJUCEPlugin/LabelReadoutSlider.h"

typedef std::pair<Label*, String> LabelWrapper;

class CarveDualLabelReadoutSlider : public WECore::JUCEPlugin::SliderLabelUpdater {
public:
    explicit CarveDualLabelReadoutSlider(const String& componentName);

    void start(LabelWrapper label1, LabelWrapper label2);

    void stop();

private:
    LabelWrapper _label1;
    LabelWrapper _label2;
    bool _isRunning;

    void _updateLabel() override;
    void _resetLabel() override;
};
