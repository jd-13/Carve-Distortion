/*
  ==============================================================================

    CustomLookAndFeel.h
    Created: 17 Sep 2015 10:39:00pm
    Author:  Jack Devlin

  ==============================================================================
*/

#ifndef CUSTOMLOOKANDFEEL_H_INCLUDED
#define CUSTOMLOOKANDFEEL_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class CustomLookAndFeel : public LookAndFeel_V2 {
public:
    CustomLookAndFeel();
        
    virtual void drawRotarySlider(Graphics& g,
                                  int x,
                                  int y,
                                  int width,
                                  int height,
                                  float sliderPosProportional,
                                  float rotaryStartAngle,
                                  float rotaryEndAngle,
                                  Slider& slider);
    
    virtual void drawLinearSliderThumb(Graphics& g,
                                       int x,
                                       int y,
                                       int width,
                                       int height,
                                       float sliderPos,
                                       float minSliderPos,
                                       float maxSliderPos,
                                       const Slider::SliderStyle style,
                                       Slider& slider);
    
    virtual void drawButtonBackground(Graphics& g,
                                      Button& button,
                                      const Colour& backgroundColour,
                                      bool isMouseOverButton,
                                      bool isButtonDown);
    
    virtual void drawComboBox(Graphics& g,
                              int width,
                              int height,
                              const bool isButtonDown,
                              int buttonX,
                              int buttonY,
                              int buttonW,
                              int buttonH,
                              ComboBox& box);
    
    
private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CustomLookAndFeel);
    
    Colour  lightGrey,
            darkGrey,
            neonBlue;
    
    bool isStereo;
};


#endif  // CUSTOMLOOKANDFEEL_H_INCLUDED
