/*
 *    File:       CarveLookAndFeel.cpp
 *
 *    Version:    2.0.0
 *
 *    Created:    01/12/2018
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

#include "CarveLookAndFeel.h"

void CarveLookAndFeel::drawGroupComponentOutline(Graphics& g,
                                                 int width,
                                                 int height,
                                                 const String& text,
                                                 const Justification& justification,
                                                 GroupComponent& group) {
    
    constexpr int MARGIN {2};
    
    g.setColour(highlightColour);
    
    Font font;
    font.setTypefaceName(_fontName);
    g.setFont(font);
    
    g.drawText(text,
               MARGIN,
               MARGIN,
               width,
               height,
               Justification::topLeft,
               true);
}

void CarveLookAndFeel::drawComboBox(Graphics& g,
                                    int width,
                                    int height,
                                    const bool /*isButtonDown*/,
                                    int buttonX,
                                    int buttonY,
                                    int buttonW,
                                    int buttonH,
                                    ComboBox& box) {
    
    g.setColour(highlightColour);
    //g.drawRoundedRectangle(0, 0, width, height, 10, 2);
    
    
    Path p;
    constexpr float LINE_WIDTH {0.5};
    const int arrowMarginX {buttonY / 4};
    const int arrowMarginY {buttonH / 3};
    const int arrowTipX {buttonX + (buttonW / 2)};
    const int arrowTipY {buttonY + buttonH - arrowMarginY};
    
    // Left side
    p.addLineSegment(Line<float>(buttonX + arrowMarginX,
                                 buttonY + arrowMarginY,
                                 arrowTipX,
                                 arrowTipY),
                     LINE_WIDTH);
    
    // Right side
    p.addLineSegment(Line<float>(buttonX + buttonW - arrowMarginX,
                                 buttonY + arrowMarginY,
                                 arrowTipX,
                                 arrowTipY),
                     LINE_WIDTH);
    
    g.strokePath(p, PathStrokeType(1));
}

Font CarveLookAndFeel::getComboBoxFont(ComboBox& /*comboBox*/) {
    Font comboFont;
    comboFont.setTypefaceName(_fontName);
    return comboFont;
}

Font CarveLookAndFeel::getPopupMenuFont() {
    Font comboFont;
    comboFont.setTypefaceName(_fontName);
    return comboFont;
}

void CarveLookAndFeel::drawButtonBackground(Graphics& g,
                                            Button& button,
                                            const Colour& /*backgroundColour*/,
                                            bool /*isMouseOverButton*/,
                                            bool /*isButtonDown*/) {
    
    const int width {button.getWidth()};
    const int height {button.getHeight()};
    
    const float indent {2.0f};
    const int cornerSize {jmin (roundToInt(width * 0.4f),
                                roundToInt(height * 0.4f))};
    
    Path p;
    PathStrokeType pStroke(1);
    Colour* bc {nullptr};
    
    if (button.isEnabled()) {
        if (button.getToggleState()) {
            bc = &highlightColour;
        } else {
            bc = &lightColour;
        }
    } else {
        bc = &darkColour;
    }
    
    p.addRoundedRectangle(indent, indent, width - 2 * indent, height - 2 * indent, static_cast<float>(cornerSize));
    
    
    g.setColour(*bc);
    g.strokePath(p, pStroke);
}

void CarveLookAndFeel::drawButtonText(Graphics& g,
                                      TextButton& textButton,
                                      bool /*isMouseOverButton*/,
                                      bool /*isButtonDown*/) {
    Colour* textColour {nullptr};
    
    if (textButton.isEnabled()) {
        if (textButton.getToggleState() || textButton.getWidth() < 24) {
            textColour = &highlightColour;
        } else {
            textColour = &lightColour;
        }
    } else {
        textColour = &darkColour;
    }
    
    g.setColour(*textColour);
    constexpr int MARGIN {0};
    
    Font font;
    font.setTypefaceName(_fontName);
    g.setFont(font);
    
    g.drawFittedText(textButton.getButtonText(),
                     MARGIN,
                     0,
                     textButton.getWidth() - 2 * MARGIN,
                     textButton.getHeight(),
                     Justification::centred,
                     0);
}

void CarveLookAndFeel::drawRotarySlider(Graphics& g,
                                        int /*x*/,
                                        int /*y*/,
                                        int width,
                                        int height,
                                        float /*sliderPosProportional*/,
                                        float /*rotaryStartAngle*/,
                                        float /*rotaryEndAngle*/,
                                        Slider &slider) {
    
    // calculate useful constants
    constexpr double arcGap {CoreMath::DOUBLE_TAU / 4};
    constexpr double rangeOfMotion {CoreMath::DOUBLE_TAU - arcGap};
    
    const double sliderNormalisedValue {(slider.getValue() - slider.getMinimum()) /
        (slider.getMaximum() - slider.getMinimum())};
    const double arcEndPoint {sliderNormalisedValue * rangeOfMotion + arcGap / 2};
    
    constexpr double margin {1.5};
    const double diameter {static_cast<float>(height - margin * 2)};
    
    if (slider.isEnabled()) {
        g.setColour(highlightColour);
    } else {
        g.setColour(lightColour);
    }
    
    Path p;
    
    // Draw inner ring
    constexpr int arcSpacing {3};
    p.addCentredArc(width / 2,
                    height / 2,
                    diameter / 2 - arcSpacing,
                    diameter / 2 - arcSpacing,
                    CoreMath::DOUBLE_PI,
                    arcGap / 2,
                    CoreMath::DOUBLE_TAU - (arcGap / 2),
                    true);
    
    g.strokePath(p, PathStrokeType(0.7f));
    
    // Draw outer ring
    p.clear();
    p.addCentredArc(width / 2,
                    height / 2,
                    diameter / 2,
                    diameter / 2,
                    CoreMath::DOUBLE_PI,
                    arcGap / 2,
                    arcEndPoint,
                    true);
    g.strokePath(p, PathStrokeType(3.0f));
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
    
    constexpr float MARGIN {2};
    
    if (style == Slider::LinearHorizontal || style == Slider::LinearVertical) {
        
        float rectangleX {static_cast<float>(minSliderPos)};
        float rectangleY {static_cast<float>(y) + MARGIN};
        float rectangleWidth {sliderPos - minSliderPos};
        float rectangleHeight {static_cast<float>(height) - 3 * MARGIN};
        
        if (style == Slider::LinearVertical) {
            rectangleX = x + MARGIN;
            rectangleY = maxSliderPos;
            rectangleWidth = width - 3 * MARGIN;
            rectangleHeight = -(sliderPos - minSliderPos);
        }
        
        if (slider.isEnabled()) {
            g.setColour(highlightColour);
        } else {
            g.setColour(lightColour);
        }
        
        g.fillRect(Rectangle<float>(rectangleX, rectangleY, rectangleWidth, rectangleHeight));
    }
}

void CarveLookAndFeel::drawLinearSliderBackground(Graphics& g,
                                                  int x,
                                                  int y,
                                                  int width,
                                                  int height,
                                                  float /*sliderPos*/,
                                                  float /*minSliderPos*/,
                                                  float /*maxSliderPos*/,
                                                  const Slider::SliderStyle, Slider& slider) {
    
    constexpr int MARGIN {2};
    constexpr int LINE_WIDTH {1};
    
    if (slider.isEnabled()) {
        g.setColour(highlightColour);
    } else {
        g.setColour(lightColour);
    }
    
    g.fillRect(Rectangle<float>(x,
                                y + height - MARGIN - (LINE_WIDTH / 2),
                                width,
                                LINE_WIDTH));
}

void CarveLookAndFeel::drawPopupMenuItem(Graphics& g,
                                         const Rectangle<int>& area,
                                         bool /*isSeparator*/,
                                         bool /*isActive*/,
                                         bool isHighlighted,
                                         bool isTicked,
                                         bool /*hasSubMenu*/,
                                         const String& text,
                                         const String& /*shortcutKeyText*/,
                                         const Drawable* /*icon*/,
                                         const Colour* /*textColour*/) {

    Rectangle r = area.reduced(1);

    if (isHighlighted) {
        g.setColour(findColour(PopupMenu::highlightedBackgroundColourId));
        g.fillRect(r);
        
        g.setColour(findColour(PopupMenu::highlightedTextColourId));
    } else if (isTicked) {
        g.setColour(highlightColour.withAlpha(0.2f));
        g.fillRect(r);
        
        g.setColour(findColour(PopupMenu::textColourId));
    } else {
        g.setColour(findColour(PopupMenu::textColourId));
    }

    Font font(getPopupMenuFont());

    const float maxFontHeight {area.getHeight() / 1.3f};

    if (font.getHeight() > maxFontHeight) {
        font.setHeight(maxFontHeight);
    }

    g.setFont(font);

    r.removeFromLeft(3);
    g.drawFittedText (text, r, Justification::centredLeft, 1);
}
