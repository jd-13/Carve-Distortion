/*
  ==============================================================================

    CustomLookAndFeel.cpp
    Created: 17 Sep 2015 10:39:00pm
    Author:  Jack Devlin

  ==============================================================================
*/

#include "CustomLookAndFeel.h"

CustomLookAndFeel::CustomLookAndFeel() :    LookAndFeel_V2(),
                                            lightGrey(200, 200, 200),
                                            darkGrey(107, 107, 107),
                                            neonBlue(34, 252, 255),
                                            isStereo(false) {
}

void CustomLookAndFeel::drawRotarySlider(Graphics& g,
                                         int x,
                                         int y,
                                         int width,
                                         int height,
                                         float sliderPosProportional,
                                         float rotaryStartAngle,
                                         float rotaryEndAngle,
                                         Slider &slider) {
    
    Image image = ImageCache::getFromMemory(BinaryData::RotarySliderStrip_png, BinaryData::RotarySliderStrip_pngSize);
    
    const double rotation = (slider.getValue() - slider.getMinimum()) / (slider.getMaximum() - slider.getMinimum());
    const int nFrames = image.getHeight() / image.getWidth();
    const int frameIdx = static_cast<int>(ceil(rotation * (static_cast<double>(nFrames) - 1.0)));
    
    const float radius = jmin(width / 2.0f, height / 2.0f);
    const float centreX = x + width * 0.5f;
    const float centreY = y + height * 0.5f;
    const float rx = centreX - radius - 1.0f;
    const float ry = centreY - radius - 1.0f;
    
    g.drawImage(image,
                (int)rx,
                (int)ry,
                2 * (int)radius,
                2 * (int)radius,
                0,
                frameIdx * image.getWidth(),
                image.getWidth(),
                image.getWidth());
}

void CustomLookAndFeel::drawLinearSliderThumb(Graphics& g,
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
    
    Image image;
    
    if (slider.isEnabled()) {
        image = ImageCache::getFromMemory(BinaryData::LinearSlider1_png, BinaryData::LinearSlider1_pngSize);
    } else {
        // TODO: disabled graphic
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
        
        g.drawImage(image,
                    kx - sliderRadius,
                    ky - sliderRadius,
                    sliderRadius * 2,
                    sliderRadius * 2,
                    0,
                    0,
                    image.getWidth(),
                    image.getHeight());

    }
    
}

void CustomLookAndFeel::drawButtonBackground(Graphics& g,
                                             Button& button,
                                             const Colour& backgroundColour,
                                             bool isMouseOverButton,
                                             bool isButtonDown) {
    const int width = button.getWidth();
    const int height = button.getHeight();
    
    const float indent = 2.0f;
    const int cornerSize = jmin (roundToInt(width * 0.4f),
                                 roundToInt(height * 0.4f));

    Path p;
    p.addRoundedRectangle(indent, indent, width - indent, height - indent, static_cast<float>(cornerSize));
    
    if (isButtonDown) {
        isStereo = !isStereo; //TODO: replace this with a direct check of the carve object's isStereo member?
    }
    
    Colour* bc;
    
    if (isStereo) {
        bc = &neonBlue;
    } else {
        bc = &lightGrey;
    }
    
    g.setColour(*bc);
    g.fillPath(p);
}

void CustomLookAndFeel::drawComboBox(Graphics& g,
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
    g.fillRect(buttonX, buttonY, buttonW, buttonY);
    
    const float arrowX = 0.2f;
    const float arrowH = 0.3f;
    
    if (box.isEnabled()) {
        Path p;
        p.addTriangle(buttonX + buttonW * 0.5f,                 buttonY + buttonH * (0.45f - arrowH),
                      buttonX + buttonW * (1.0f - arrowX),      buttonY + buttonH * 0.45f,
                      buttonX + buttonW * arrowX,               buttonY + buttonH * 0.45f);
        
        p.addTriangle(buttonX + buttonW * 0.5f,                 buttonY + buttonH * (0.55f + arrowH),
                      buttonX + buttonW * (1.0f -arrowX),       buttonY + buttonH * 0.55f,
                      buttonX + buttonW * arrowX,               buttonY + buttonH * 0.55f);
        
        g.setColour(isButtonDown ? neonBlue : lightGrey);
        
        g.fillPath(p);
    }
}


