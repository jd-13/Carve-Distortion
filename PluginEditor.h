/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_38B84E4BE27E0F78__
#define __JUCE_HEADER_38B84E4BE27E0F78__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "CarveLookAndFeel.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class CarveAudioProcessorEditor  : public AudioProcessorEditor,
                                   public Timer,
                                   public SliderListener,
                                   public ComboBoxListener,
                                   public ButtonListener
{
public:
    //==============================================================================
    CarveAudioProcessorEditor (CarveAudioProcessor& ownerFilter);
    ~CarveAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback();
    CarveAudioProcessor* getProcessor() const {
        return static_cast<CarveAudioProcessor*>(getAudioProcessor());
    }
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    CarveLookAndFeel customLookAndFeel;
    SharedResourcePointer<TooltipWindow> tooltipWindow;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> MasterGroup;
    ScopedPointer<GroupComponent> Unit1Group;
    ScopedPointer<GroupComponent> Unit2Group;
    ScopedPointer<Slider> PreGain1Sld;
    ScopedPointer<Slider> PostGain1Sld;
    ScopedPointer<Slider> Tweak1Sld;
    ScopedPointer<ComboBox> Mode1Cmb;
    ScopedPointer<Slider> PreGain2Sld;
    ScopedPointer<Slider> PostGain2Sld;
    ScopedPointer<Slider> Tweak2Sld;
    ScopedPointer<ComboBox> Mode2Cmb;
    ScopedPointer<Slider> RoutingSld;
    ScopedPointer<Label> PreGain1Lbl;
    ScopedPointer<Label> PostGain1Lbl;
    ScopedPointer<Label> Tweak1Lbl;
    ScopedPointer<Label> SerialLbl;
    ScopedPointer<Label> ParallelLbl;
    ScopedPointer<Slider> MasterVolSld;
    ScopedPointer<Label> MasterVolLbl;
    ScopedPointer<Label> PreGain2Lbl;
    ScopedPointer<Label> PostGain2Lbl;
    ScopedPointer<Label> Tweak2Lbl;
    ScopedPointer<Slider> DryLevelSld;
    ScopedPointer<Label> DryLevelLbl;
    ScopedPointer<TextButton> StereoBtn;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CarveAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_38B84E4BE27E0F78__
