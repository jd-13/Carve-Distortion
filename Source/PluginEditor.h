/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "CarveLookAndFeel.h"
#include "CarveWaveViewer.h"
#include "CarveDualLabelReadoutSlider.h"
#include "CoreJUCEPlugin/CoreProcessorEditor.h"
#include "CoreJUCEPlugin/LabelReadoutSlider.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class CarveAudioProcessorEditor  : public WECore::JUCEPlugin::CoreProcessorEditor,
                                   public juce::Slider::Listener,
                                   public juce::ComboBox::Listener,
                                   public juce::Button::Listener
{
public:
    //==============================================================================
    CarveAudioProcessorEditor (CarveAudioProcessor& ownerFilter);
    ~CarveAudioProcessorEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    CarveAudioProcessor* getProcessor() const {
        return static_cast<CarveAudioProcessor*>(getAudioProcessor());
    }
    void sliderDragStarted(Slider* slider) override;
    void sliderDragEnded(Slider* slider) override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    CarveLookAndFeel _customLookAndFeel;
    const Colour _highlightColour;

    virtual void _onParameterUpdate() override;
    void _drawDividers(Graphics& g) const;
    void _drawWaves();
    void _enableDoubleClickToDefault();
    void _startSliderReadouts();
    void _stopSliderReadouts();
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> RoutingGroup;
    std::unique_ptr<juce::GroupComponent> Unit1Group;
    std::unique_ptr<juce::GroupComponent> Unit2Group;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> PreGain1Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> PostGain1Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> Tweak1Sld;
    std::unique_ptr<juce::ComboBox> Mode1Cmb;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> PreGain2Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> PostGain2Sld;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<double>> Tweak2Sld;
    std::unique_ptr<juce::ComboBox> Mode2Cmb;
    std::unique_ptr<CarveDualLabelReadoutSlider> RoutingSld;
    std::unique_ptr<juce::Label> PreGain1Lbl;
    std::unique_ptr<juce::Label> PostGain1Lbl;
    std::unique_ptr<juce::Label> Tweak1Lbl;
    std::unique_ptr<juce::Label> SerialLbl;
    std::unique_ptr<juce::Label> ParallelLbl;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<float>> OutputGainSld;
    std::unique_ptr<juce::Label> OutputGainLbl;
    std::unique_ptr<juce::Label> PreGain2Lbl;
    std::unique_ptr<juce::Label> PostGain2Lbl;
    std::unique_ptr<juce::Label> Tweak2Lbl;
    std::unique_ptr<WECore::JUCEPlugin::LabelReadoutSlider<float>> DryLevelSld;
    std::unique_ptr<juce::Label> DryLevelLbl;
    std::unique_ptr<juce::TextButton> StereoBtn;
    std::unique_ptr<CarveWaveViewer> Wave1View;
    std::unique_ptr<CarveWaveViewer> Wave2View;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CarveAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

