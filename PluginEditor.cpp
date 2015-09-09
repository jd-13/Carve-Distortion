/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
CarveAudioProcessorEditor::CarveAudioProcessorEditor (CarveAudioProcessor& ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (PreGain1Sld = new Slider ("PreGain 1 Slider"));
    PreGain1Sld->setRange (0, 2, 0.1);
    PreGain1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PreGain1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    PreGain1Sld->addListener (this);

    addAndMakeVisible (PostGain1Sld = new Slider ("PostGain 1 Slider"));
    PostGain1Sld->setRange (0, 2, 0.1);
    PostGain1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PostGain1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    PostGain1Sld->addListener (this);

    addAndMakeVisible (Tweak1Sld = new Slider ("Tweak 1 Slider"));
    Tweak1Sld->setRange (-1, 1, 0.1);
    Tweak1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    Tweak1Sld->setTextBoxStyle (Slider::TextBoxLeft, false, 80, 20);
    Tweak1Sld->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);
    //[/Constructor]
}

CarveAudioProcessorEditor::~CarveAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    PreGain1Sld = nullptr;
    PostGain1Sld = nullptr;
    Tweak1Sld = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void CarveAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void CarveAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    PreGain1Sld->setBounds (104, 32, 150, 24);
    PostGain1Sld->setBounds (104, 64, 150, 24);
    Tweak1Sld->setBounds (104, 96, 150, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void CarveAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == PreGain1Sld)
    {
        //[UserSliderCode_PreGain1Sld] -- add your slider handling code here..
        //[/UserSliderCode_PreGain1Sld]
    }
    else if (sliderThatWasMoved == PostGain1Sld)
    {
        //[UserSliderCode_PostGain1Sld] -- add your slider handling code here..
        //[/UserSliderCode_PostGain1Sld]
    }
    else if (sliderThatWasMoved == Tweak1Sld)
    {
        //[UserSliderCode_Tweak1Sld] -- add your slider handling code here..
        //[/UserSliderCode_Tweak1Sld]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void CarveAudioProcessorEditor::timerCallback() {
    CarveAudioProcessor* ourProcessor = getProcessor();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="CarveAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor, public Timer"
                 constructorParams="CarveAudioProcessor&amp; ownerFilter" variableInitialisers="AudioProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="PreGain 1 Slider" id="f32c9f6afaac55bd" memberName="PreGain1Sld"
          virtualName="" explicitFocusOrder="0" pos="104 32 150 24" min="0"
          max="2" int="0.10000000000000000555" style="RotaryVerticalDrag"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="PostGain 1 Slider" id="6c5a77936be07efe" memberName="PostGain1Sld"
          virtualName="" explicitFocusOrder="0" pos="104 64 150 24" min="0"
          max="2" int="0.10000000000000000555" style="RotaryVerticalDrag"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Tweak 1 Slider" id="94990f0dcf6af35d" memberName="Tweak1Sld"
          virtualName="" explicitFocusOrder="0" pos="104 96 150 24" min="-1"
          max="1" int="0.10000000000000000555" style="RotaryVerticalDrag"
          textBoxPos="TextBoxLeft" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
