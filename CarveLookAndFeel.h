/*
  ==============================================================================

    CarveLookAndFeel.h
    Created: 17 Sep 2015 10:39:00pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef CARVELOOKANDFEEL_H_INCLUDED
#define CARVELOOKANDFEEL_H_INCLUDED

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
    
    
    /*virtual void drawPopupMenuBackground(Graphics& g,
                                         int width,
                                         int height);
    */
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CarveLookAndFeel);
    
    Colour  lightGrey,
            darkGrey,
            neonBlue;
    
};


#endif  // CARVELOOKANDFEEL_H_INCLUDED
