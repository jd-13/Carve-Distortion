/*
  ==============================================================================

    CarveLookAndFeel.cpp
    Created: 17 Sep 2015 10:39:00pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "CarveLookAndFeel.h"

CarveLookAndFeel::CarveLookAndFeel() :  LookAndFeel_V2(),
                                        lightGrey(200, 200, 200),
                                        darkGrey(107, 107, 107),
                                        neonBlue(34, 252, 255) {
                                                
    setColour(PopupMenu::highlightedBackgroundColourId, darkGrey);
    setColour(PopupMenu::backgroundColourId, lightGrey);
}

void CarveLookAndFeel::drawRotarySlider(Graphics& g,
                                        int x,
                                        int y,
                                        int width,
                                        int height,
                                        float sliderPosProportional,
                                        float rotaryStartAngle,
                                        float rotaryEndAngle,
                                        Slider &slider) {
    // calculate useful constants
    const double rangeOfMotion {260 * (M_PI / 180)};
    const double rotation {((slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum())) * rangeOfMotion - rangeOfMotion / 2};

    const int margin {1};
    const double diameter {static_cast<double>(height - margin * 2)};
    
    // draw centre circle
    Path p;
    g.setColour(darkGrey);
    p.addEllipse(width / 2 - diameter / 2, height / 2 - diameter / 2, diameter, diameter);
    g.fillPath(p);
    
    // draw outer ring
    if (slider.isEnabled()) {
        g.setColour(neonBlue);
    } else {
        g.setColour(lightGrey);
    }
    
    p.clear();
    
    const double gap {0.4};
    p.addCentredArc(width / 2, height / 2, diameter / 2, diameter / 2, rotation, gap, 2 * M_PI - gap, true);
    
    g.strokePath(p, PathStrokeType(2.0f));
    
}

void CarveLookAndFeel::drawLinearSliderThumb(Graphics& g,
                                             int x,
                                             int y,
                                             int width,
                                             int height,
                                             float sliderPos,
                                             float minSliderPos,
                                             float maxSliderPos,
                                             const Slider::SliderStyle style,
                                             Slider& slider) {
    
    const float sliderRadius = static_cast<float>(getSliderThumbRadius(slider) - 2);
    
    Colour* ring;
    
    if (slider.isEnabled()) {
        ring = &neonBlue;
    } else {
        ring = &lightGrey;
    }
    
    if (style == Slider::LinearHorizontal || style == Slider::LinearVertical)
    {
        float kx, ky;
        
        if (style == Slider::LinearVertical)
        {
            kx = x + width * 0.5f;
            ky = sliderPos;
        }
        else
        {
            kx = sliderPos;
            ky = y + height * 0.5f;
        }
        
        Path p;
        p.addEllipse(kx - sliderRadius, ky - sliderRadius, sliderRadius * 2, sliderRadius * 2);
        
        g.setColour(darkGrey);
        g.fillPath(p);
        
        g.setColour(*ring);
        g.strokePath(p, PathStrokeType(2.0f));
    }
    
}

void CarveLookAndFeel::drawButtonBackground(Graphics& g,
                                            Button& button,
                                            const Colour& backgroundColour,
                                            bool isMouseOverButton,
                                            bool isButtonDown) {
    const int width {button.getWidth()};
    const int height {button.getHeight()};
    
    const float indent {2.0f};
    const int cornerSize {jmin (roundToInt(width * 0.4f),
                                roundToInt(height * 0.4f))};

    Path p;
    p.addRoundedRectangle(indent, indent, width - indent, height - indent, static_cast<float>(cornerSize));
    
    Colour* bc;
    
    if (button.isEnabled()) {
        if (button.getToggleState()) {
            bc = &neonBlue;
        } else {
            bc = &darkGrey;
        }
    } else {
        bc = &lightGrey;
    }
    
    
    g.setColour(*bc);
    g.fillPath(p);
}

void CarveLookAndFeel::drawComboBox(Graphics& g,
                                    int width,
                                    int height,
                                    const bool isButtonDown,
                                    int buttonX,
                                    int buttonY,
                                    int buttonW,
                                    int buttonH,
                                    ComboBox& box) {
    
    g.fillAll(lightGrey);
    g.setColour(darkGrey);
    g.fillRect(buttonX, buttonY, buttonW, buttonH);
    
    const float arrowX {0.2f};
    const float arrowH {0.3f};
    
    if (box.isEnabled()) {
        Path p;
        p.addTriangle(buttonX + buttonW * 0.5f,                 buttonY + buttonH * (0.45f - arrowH),
                      buttonX + buttonW * (1.0f - arrowX),      buttonY + buttonH * 0.45f,
                      buttonX + buttonW * arrowX,               buttonY + buttonH * 0.45f);
        
        p.addTriangle(buttonX + buttonW * 0.5f,                 buttonY + buttonH * (0.55f + arrowH),
                      buttonX + buttonW * (1.0f -arrowX),       buttonY + buttonH * 0.55f,
                      buttonX + buttonW * arrowX,               buttonY + buttonH * 0.55f);
        
        g.setColour(box.isPopupActive() ? neonBlue : lightGrey);
        
        g.fillPath(p);
    }
}

void CarveLookAndFeel::drawTooltip(Graphics& g,
                                   const String& text,
                                   int width,
                                   int height) {
    g.setColour(lightGrey);
    g.fillRect(0, 0, width, height);
    
    g.setColour(darkGrey);
    g.drawFittedText(text, 0, 0, width, height, Justification::centred, 3);
}
