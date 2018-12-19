/*
 *    File:       CarveLookAndFeel.h
 *
 *    Version:    2.0.0
 *
 *    Created:    25/11/2018
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

#include "CoreJUCEPlugin/CoreLookAndFeel.h"

class CarveLookAndFeel : public WECore::JUCEPlugin::CoreLookAndFeel {
public:
    CarveLookAndFeel() : _fontName("Courier New") {}
    
    virtual void drawGroupComponentOutline(Graphics& g,
                                           int width,
                                           int height,
                                           const String& text,
                                           const Justification& justification,
                                           GroupComponent& group) override;
    void drawComboBox(Graphics& g,
                      int width,
                      int height,
                      const bool isButtonDown,
                      int buttonX,
                      int buttonY,
                      int buttonW,
                      int buttonH,
                      ComboBox& box) override;

    virtual Font getComboBoxFont(ComboBox& comboBox) override;
    
    virtual Font getPopupMenuFont() override;
    
    virtual void drawButtonText(Graphics& g,
                                TextButton& textButton,
                                bool isMouseOverButton,
                                bool isButtonDown) override;
    
    virtual void drawRotarySlider(Graphics& g,
                                  int x,
                                  int y,
                                  int width,
                                  int height,
                                  float sliderPosProportional,
                                  float rotaryStartAngle,
                                  float rotaryEndAngle,
                                  Slider &slider) override;
    
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
    
    virtual void drawLinearSliderBackground(Graphics& g,
                                            int x,
                                            int y,
                                            int width,
                                            int height,
                                            float sliderPos,
                                            float minSliderPos,
                                            float maxSliderPos,
                                            const Slider::SliderStyle, Slider& slider) override;
    
    virtual void drawPopupMenuItem(Graphics& g,
                                   const Rectangle<int>& area,
                                   bool isSeparator,
                                   bool isActive,
                                   bool isHighlighted,
                                   bool isTicked,
                                   bool hasSubMenu,
                                   const String& text,
                                   const String& shortcutKeyText,
                                   const Drawable* icon,
                                   const Colour* textColour) override;
    
    const Colour& getHighlightColour() const { return highlightColour; }
    
private:
    const char* _fontName;
};
