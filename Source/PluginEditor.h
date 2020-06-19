/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "CarveLookAndFeel.h"
#include "CarveWaveViewer.h"
#include "CoreJUCEPlugin/CoreProcessorEditor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class CarveAudioProcessorEditor  : public WECore::JUCEPlugin::CoreProcessorEditor,
                                   public Timer,
                                   public Slider::Listener,
                                   public ComboBox::Listener,
                                   public Button::Listener
{
public:
    //==============================================================================
    CarveAudioProcessorEditor (CarveAudioProcessor& ownerFilter);
    ~CarveAudioProcessorEditor();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback() override;
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
    CarveLookAndFeel _customLookAndFeel;
    const Colour _highlightColour;

    void _drawDividers(Graphics& g) const;
    void _drawWaves();
    void _enableDoubleClickToDefault();
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<GroupComponent> RoutingGroup;
    std::unique_ptr<GroupComponent> Unit1Group;
    std::unique_ptr<GroupComponent> Unit2Group;
    std::unique_ptr<Slider> PreGain1Sld;
    std::unique_ptr<Slider> PostGain1Sld;
    std::unique_ptr<Slider> Tweak1Sld;
    std::unique_ptr<ComboBox> Mode1Cmb;
    std::unique_ptr<Slider> PreGain2Sld;
    std::unique_ptr<Slider> PostGain2Sld;
    std::unique_ptr<Slider> Tweak2Sld;
    std::unique_ptr<ComboBox> Mode2Cmb;
    std::unique_ptr<Slider> RoutingSld;
    std::unique_ptr<Label> PreGain1Lbl;
    std::unique_ptr<Label> PostGain1Lbl;
    std::unique_ptr<Label> Tweak1Lbl;
    std::unique_ptr<Label> SerialLbl;
    std::unique_ptr<Label> ParallelLbl;
    std::unique_ptr<Slider> OutputGainSld;
    std::unique_ptr<Label> OutputGainLbl;
    std::unique_ptr<Label> PreGain2Lbl;
    std::unique_ptr<Label> PostGain2Lbl;
    std::unique_ptr<Label> Tweak2Lbl;
    std::unique_ptr<Slider> DryLevelSld;
    std::unique_ptr<Label> DryLevelLbl;
    std::unique_ptr<TextButton> StereoBtn;
    std::unique_ptr<CarveWaveViewer> Wave1View;
    std::unique_ptr<CarveWaveViewer> Wave2View;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CarveAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
