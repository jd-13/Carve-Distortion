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

CarveLookAndFeel::CarveLookAndFeel() {
    _regularFont = Font(Typeface::createSystemTypefaceFor(BinaryData::AnonymousProRegular_ttf,
                                                          BinaryData::AnonymousProRegular_ttfSize));
    _boldFont = Font(Typeface::createSystemTypefaceFor(BinaryData::AnonymousProBold_ttf,
                                                       BinaryData::AnonymousProBold_ttfSize));
    jassert(_regularFont.getTypefaceName().isNotEmpty());
    jassert(_boldFont.getTypefaceName().isNotEmpty());
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

Typeface::Ptr CarveLookAndFeel::getTypefaceForFont(const Font& font) {
    return font.isBold() ? _boldFont.getTypeface() : _regularFont.getTypeface();
}

