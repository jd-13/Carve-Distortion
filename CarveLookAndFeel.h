//
//  CarveLookAndFeel.h
//  Carve
//
//  Created by Jack Devlin on 22/11/2018.
//  Copyright © 2018 White Elephant Audio. All rights reserved.
//

#ifndef CarveLookAndFeel_h
#define CarveLookAndFeel_h

#include "CoreJUCEPlugin/CoreLookAndFeel.h"

class CarveLookAndFeel : public WECore::JUCEPlugin::CoreLookAndFeel {
public:
    CarveLookAndFeel() : _fontName("Courier New") {}
    
    virtual void drawGroupComponentOutline(Graphics& g,
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
    
    virtual void drawButtonBackground(Graphics& g,
                                      Button& button,
                                      const Colour& /*backgroundColour*/,
                                      bool /*isMouseOverButton*/,
                                      bool /*isButtonDown*/) override {
        
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
    
    virtual void drawButtonText(Graphics& g,
                                TextButton& textButton,
                                bool /*isMouseOverButton*/,
                                bool /*isButtonDown*/) override {
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
    
    virtual void drawRotarySlider(Graphics& g,
                                  int /*x*/,
                                  int /*y*/,
                                  int width,
                                  int height,
                                  float /*sliderPosProportional*/,
                                  float /*rotaryStartAngle*/,
                                  float /*rotaryEndAngle*/,
                                  Slider &slider) override {
        
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
    
    virtual void drawLinearSliderThumb(Graphics& g,
                                       int x,
                                       int y,
                                       int width,
                                       int height,
                                       float sliderPos,
                                       float minSliderPos,
                                       float maxSliderPos,
                                       const Slider::SliderStyle style,
                                       Slider& slider) override {
        
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
    
    virtual void drawLinearSliderBackground(Graphics& g,
                                            int x,
                                            int y,
                                            int width,
                                            int height,
                                            float /*sliderPos*/,
                                            float /*minSliderPos*/,
                                            float /*maxSliderPos*/,
                                            const Slider::SliderStyle, Slider& slider) override {
        
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
    
private:
    const char* _fontName;
};


#endif /* CarveLookAndFeel_h */
