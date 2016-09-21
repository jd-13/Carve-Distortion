/*
 *	File:		CarveLookAndFeel.h
 *
 *	Version:	2.0.0
 *
 *	Created:	17/09/2015
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

#ifndef CARVELOOKANDFEEL_H_INCLUDED
#define CARVELOOKANDFEEL_H_INCLUDED

#define _USE_MATH_DEFINES

#include "math.h"
#include "../JuceLibraryCode/JuceHeader.h"



class CarveLookAndFeel : public LookAndFeel_V2 {
public:
    CarveLookAndFeel();
        
    virtual void drawRotarySlider(Graphics& g,
                                  int x,
                                  int y,
                                  int width,
                                  int height,
                                  float sliderPosProportional,
                                  float rotaryStartAngle,
                                  float rotaryEndAngle,
                                  Slider& slider) override;
    
    virtual void drawLinearSliderThumb(Graphics& g,
                                       int x,
                                       int y,
                                       int width,
                                       int height,
                                       float sliderPos,
                                       float minSliderPos,
                                       float maxSliderPos,
                                       const Slider::SliderStyle style,
                                       Slider& slider) override;
    
    virtual void drawButtonBackground(Graphics& g,
                                      Button& button,
                                      const Colour& backgroundColour,
                                      bool isMouseOverButton,
                                      bool isButtonDown) override;
    
    virtual void drawComboBox(Graphics& g,
                              int width,
                              int height,
                              const bool isButtonDown,
                              int buttonX,
                              int buttonY,
                              int buttonW,
                              int buttonH,
                              ComboBox& box) override;
    
    
    virtual void drawTooltip(Graphics& g,
                             const String& text,
                             int width,
                             int height) override;
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CarveLookAndFeel)
    
    Colour  lightGrey,
            darkGrey,
            neonBlue;
    
};


#endif  // CARVELOOKANDFEEL_H_INCLUDED
