/*
 *    File:       CarveDualLabelReadoutSlider.cpp
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

#include <tuple>
#include "CarveDualLabelReadoutSlider.h"

CarveDualLabelReadoutSlider::CarveDualLabelReadoutSlider(const String& componentName) :
        SliderLabelUpdater(componentName) {
}

void CarveDualLabelReadoutSlider::start(LabelWrapper label1,
                                        LabelWrapper label2,
                                        const ParameterDefinition::RangedParameter<float>* parameter) {
    _label1 = label1;
    _label2 = label2;
    _parameter = const_cast<ParameterDefinition::RangedParameter<float>*>(parameter);
    _isRunning = true;
}

void CarveDualLabelReadoutSlider::stop() {
    _isRunning = false;
}

void CarveDualLabelReadoutSlider::_updateLabel() {
    if (_isRunning) {
        String valueString(_parameter->NormalisedToInternal(getValue()), 2);
        _label1.first->setText(valueString, dontSendNotification);
        _label2.first->setText(valueString, dontSendNotification);
    }
}

void CarveDualLabelReadoutSlider::_resetLabel() {
    if (_isRunning) {
        _label1.first->setText(_label1.second, dontSendNotification);
        _label2.first->setText(_label2.second, dontSendNotification);
    }
}
