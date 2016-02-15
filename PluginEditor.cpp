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

    addAndMakeVisible (MasterGroup = new GroupComponent ("Master Group",
                                                         TRANS("Master")));
    MasterGroup->setTextLabelPosition (Justification::centred);

    addAndMakeVisible (Unit1Group = new GroupComponent ("Unit 1 Group",
                                                        TRANS("Unit 1")));
    Unit1Group->setTextLabelPosition (Justification::centred);

    addAndMakeVisible (Unit2Group = new GroupComponent ("Unit 2 Group",
                                                        TRANS("Unit 2")));
    Unit2Group->setTextLabelPosition (Justification::centred);

    addAndMakeVisible (PreGain1Sld = new Slider ("PreGain 1 Slider"));
    PreGain1Sld->setRange (0, 1, 0.01);
    PreGain1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PreGain1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PreGain1Sld->addListener (this);

    addAndMakeVisible (PostGain1Sld = new Slider ("PostGain 1 Slider"));
    PostGain1Sld->setRange (0, 1, 0.01);
    PostGain1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PostGain1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PostGain1Sld->addListener (this);

    addAndMakeVisible (Tweak1Sld = new Slider ("Tweak 1 Slider"));
    Tweak1Sld->setRange (0, 1, 0.01);
    Tweak1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    Tweak1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    Tweak1Sld->addListener (this);

    addAndMakeVisible (Mode1Cmb = new ComboBox ("Mode 1 Combo Box"));
    Mode1Cmb->setEditableText (false);
    Mode1Cmb->setJustificationType (Justification::centredLeft);
    Mode1Cmb->setTextWhenNothingSelected (String::empty);
    Mode1Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    Mode1Cmb->addItem (TRANS("Sine"), 1);
    Mode1Cmb->addItem (TRANS("Parabolic Soft"), 2);
    Mode1Cmb->addItem (TRANS("Parabolic Hard"), 3);
    Mode1Cmb->addItem (TRANS("Asymmetric Sine"), 4);
    Mode1Cmb->addItem (TRANS("Exponent"), 5);
    Mode1Cmb->addItem (TRANS("Clipper"), 6);
    Mode1Cmb->addListener (this);

    addAndMakeVisible (PreGain2Sld = new Slider ("PreGain 2 Slider"));
    PreGain2Sld->setRange (0, 1, 0.01);
    PreGain2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PreGain2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PreGain2Sld->addListener (this);

    addAndMakeVisible (PostGain2Sld = new Slider ("PostGain 2 Slider"));
    PostGain2Sld->setRange (0, 1, 0.01);
    PostGain2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PostGain2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PostGain2Sld->addListener (this);

    addAndMakeVisible (Tweak2Sld = new Slider ("Tweak 2 Slider"));
    Tweak2Sld->setRange (0, 1, 0.01);
    Tweak2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    Tweak2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    Tweak2Sld->addListener (this);

    addAndMakeVisible (Mode2Cmb = new ComboBox ("Mode 2 Combo Box"));
    Mode2Cmb->setEditableText (false);
    Mode2Cmb->setJustificationType (Justification::centredLeft);
    Mode2Cmb->setTextWhenNothingSelected (String::empty);
    Mode2Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    Mode2Cmb->addItem (TRANS("Sine"), 1);
    Mode2Cmb->addItem (TRANS("Parabolic Soft"), 2);
    Mode2Cmb->addItem (TRANS("Parabolic Hard"), 3);
    Mode2Cmb->addItem (TRANS("Asymmetric Sine"), 4);
    Mode2Cmb->addItem (TRANS("Exponent"), 5);
    Mode2Cmb->addItem (TRANS("Clipper"), 6);
    Mode2Cmb->addListener (this);

    addAndMakeVisible (RoutingSld = new Slider ("Routing Slider"));
    RoutingSld->setRange (0, 1, 0.01);
    RoutingSld->setSliderStyle (Slider::LinearHorizontal);
    RoutingSld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    RoutingSld->addListener (this);

    addAndMakeVisible (PreGain1Lbl = new Label ("PreGain 1 Label",
                                                TRANS("Pre Gain")));
    PreGain1Lbl->setFont (Font (15.00f, Font::plain));
    PreGain1Lbl->setJustificationType (Justification::centredLeft);
    PreGain1Lbl->setEditable (false, false, false);
    PreGain1Lbl->setColour (TextEditor::textColourId, Colours::black);
    PreGain1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (PostGain1Lbl = new Label ("PostGain 1 Label",
                                                 TRANS("Post Gain")));
    PostGain1Lbl->setFont (Font (15.00f, Font::plain));
    PostGain1Lbl->setJustificationType (Justification::centredLeft);
    PostGain1Lbl->setEditable (false, false, false);
    PostGain1Lbl->setColour (TextEditor::textColourId, Colours::black);
    PostGain1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (Tweak1Lbl = new Label ("Tweak 1 Label",
                                              TRANS("Tweak")));
    Tweak1Lbl->setFont (Font (15.00f, Font::plain));
    Tweak1Lbl->setJustificationType (Justification::centredLeft);
    Tweak1Lbl->setEditable (false, false, false);
    Tweak1Lbl->setColour (TextEditor::textColourId, Colours::black);
    Tweak1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (SerialLbl = new Label ("Serial Label",
                                              TRANS("Serial")));
    SerialLbl->setFont (Font (15.00f, Font::plain));
    SerialLbl->setJustificationType (Justification::centred);
    SerialLbl->setEditable (false, false, false);
    SerialLbl->setColour (TextEditor::textColourId, Colours::black);
    SerialLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (ParallelLbl = new Label ("Parallel Label",
                                                TRANS("Parallel")));
    ParallelLbl->setFont (Font (15.00f, Font::plain));
    ParallelLbl->setJustificationType (Justification::centredLeft);
    ParallelLbl->setEditable (false, false, false);
    ParallelLbl->setColour (TextEditor::textColourId, Colours::black);
    ParallelLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (MasterVolSld = new Slider ("Master Vol Slider"));
    MasterVolSld->setRange (0, 1, 0.01);
    MasterVolSld->setSliderStyle (Slider::LinearHorizontal);
    MasterVolSld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    MasterVolSld->addListener (this);

    addAndMakeVisible (MasterVolLbl = new Label ("Master Vol Label",
                                                 TRANS("Master Vol")));
    MasterVolLbl->setFont (Font (15.00f, Font::plain));
    MasterVolLbl->setJustificationType (Justification::centred);
    MasterVolLbl->setEditable (false, false, false);
    MasterVolLbl->setColour (TextEditor::textColourId, Colours::black);
    MasterVolLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (PreGain2Lbl = new Label ("PreGain 2 Label",
                                                TRANS("Pre Gain")));
    PreGain2Lbl->setFont (Font (15.00f, Font::plain));
    PreGain2Lbl->setJustificationType (Justification::centredLeft);
    PreGain2Lbl->setEditable (false, false, false);
    PreGain2Lbl->setColour (TextEditor::textColourId, Colours::black);
    PreGain2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (PostGain2Lbl = new Label ("PostGain 2 Label",
                                                 TRANS("Post Gain")));
    PostGain2Lbl->setFont (Font (15.00f, Font::plain));
    PostGain2Lbl->setJustificationType (Justification::centredLeft);
    PostGain2Lbl->setEditable (false, false, false);
    PostGain2Lbl->setColour (TextEditor::textColourId, Colours::black);
    PostGain2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (Tweak2Lbl = new Label ("Tweak 2 Label",
                                              TRANS("Tweak")));
    Tweak2Lbl->setFont (Font (15.00f, Font::plain));
    Tweak2Lbl->setJustificationType (Justification::centredLeft);
    Tweak2Lbl->setEditable (false, false, false);
    Tweak2Lbl->setColour (TextEditor::textColourId, Colours::black);
    Tweak2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (DryLevelSld = new Slider ("Dry Level Slider"));
    DryLevelSld->setRange (0, 1, 0.01);
    DryLevelSld->setSliderStyle (Slider::LinearHorizontal);
    DryLevelSld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DryLevelSld->addListener (this);

    addAndMakeVisible (DryLevelLbl = new Label ("Dry Level Label",
                                                TRANS("Dry Level")));
    DryLevelLbl->setFont (Font (15.00f, Font::plain));
    DryLevelLbl->setJustificationType (Justification::centred);
    DryLevelLbl->setEditable (false, false, false);
    DryLevelLbl->setColour (TextEditor::textColourId, Colours::black);
    DryLevelLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (StereoBtn = new TextButton ("Stereo Button"));
    StereoBtn->setButtonText (TRANS("Stereo"));
    StereoBtn->addListener (this);
    StereoBtn->setColour (TextButton::buttonColourId, Colour (0xffb8b8c4));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (375, 340);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);
    LookAndFeel::setDefaultLookAndFeel(&customLookAndFeel);
    // disable stereo mode if only single output
    CarveAudioProcessor* ourProcessor {getProcessor()};
    StereoBtn->setEnabled(ourProcessor->getNumOutputChannels() == 2);
    //[/Constructor]
}

CarveAudioProcessorEditor::~CarveAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    MasterGroup = nullptr;
    Unit1Group = nullptr;
    Unit2Group = nullptr;
    PreGain1Sld = nullptr;
    PostGain1Sld = nullptr;
    Tweak1Sld = nullptr;
    Mode1Cmb = nullptr;
    PreGain2Sld = nullptr;
    PostGain2Sld = nullptr;
    Tweak2Sld = nullptr;
    Mode2Cmb = nullptr;
    RoutingSld = nullptr;
    PreGain1Lbl = nullptr;
    PostGain1Lbl = nullptr;
    Tweak1Lbl = nullptr;
    SerialLbl = nullptr;
    ParallelLbl = nullptr;
    MasterVolSld = nullptr;
    MasterVolLbl = nullptr;
    PreGain2Lbl = nullptr;
    PostGain2Lbl = nullptr;
    Tweak2Lbl = nullptr;
    DryLevelSld = nullptr;
    DryLevelLbl = nullptr;
    StereoBtn = nullptr;


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
    Image bg = ImageCache::getFromMemory(BinaryData::background_jpeg, BinaryData::background_jpegSize);
    g.drawImage(bg, 0, 0, 375, 340, 0, 0, 5 * 375, 5 * 340);
    //[/UserPaint]
}

void CarveAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    MasterGroup->setBounds (16, 208, 344, 120);
    Unit1Group->setBounds (16, 48, 168, 152);
    Unit2Group->setBounds (192, 48, 168, 152);
    PreGain1Sld->setBounds (128, 104, 32, 24);
    PostGain1Sld->setBounds (128, 136, 32, 24);
    Tweak1Sld->setBounds (128, 168, 32, 24);
    Mode1Cmb->setBounds (24, 72, 150, 24);
    PreGain2Sld->setBounds (304, 104, 32, 24);
    PostGain2Sld->setBounds (304, 136, 32, 24);
    Tweak2Sld->setBounds (304, 168, 32, 24);
    Mode2Cmb->setBounds (200, 72, 150, 24);
    RoutingSld->setBounds (104, 232, 96, 24);
    PreGain1Lbl->setBounds (32, 104, 64, 24);
    PostGain1Lbl->setBounds (32, 136, 64, 24);
    Tweak1Lbl->setBounds (32, 168, 64, 24);
    SerialLbl->setBounds (24, 232, 80, 24);
    ParallelLbl->setBounds (208, 232, 56, 24);
    MasterVolSld->setBounds (104, 295, 240, 24);
    MasterVolLbl->setBounds (24, 295, 80, 24);
    PreGain2Lbl->setBounds (208, 104, 64, 24);
    PostGain2Lbl->setBounds (208, 136, 64, 24);
    Tweak2Lbl->setBounds (208, 168, 64, 24);
    DryLevelSld->setBounds (104, 264, 240, 24);
    DryLevelLbl->setBounds (24, 264, 80, 24);
    StereoBtn->setBounds (272, 232, 70, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void CarveAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    CarveAudioProcessor* ourProcessor {getProcessor()};
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == PreGain1Sld)
    {
        //[UserSliderCode_PreGain1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::preGain1, static_cast<float>(PreGain1Sld->getValue()));
        //[/UserSliderCode_PreGain1Sld]
    }
    else if (sliderThatWasMoved == PostGain1Sld)
    {
        //[UserSliderCode_PostGain1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::postGain1, static_cast<float>(PostGain1Sld->getValue()));
        //[/UserSliderCode_PostGain1Sld]
    }
    else if (sliderThatWasMoved == Tweak1Sld)
    {
        //[UserSliderCode_Tweak1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::tweak1, static_cast<float>(Tweak1Sld->getValue()));
        //[/UserSliderCode_Tweak1Sld]
    }
    else if (sliderThatWasMoved == PreGain2Sld)
    {
        //[UserSliderCode_PreGain2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::preGain2, static_cast<float>(PreGain2Sld->getValue()));
        //[/UserSliderCode_PreGain2Sld]
    }
    else if (sliderThatWasMoved == PostGain2Sld)
    {
        //[UserSliderCode_PostGain2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::postGain2, static_cast<float>(PostGain2Sld->getValue()));
        //[/UserSliderCode_PostGain2Sld]
    }
    else if (sliderThatWasMoved == Tweak2Sld)
    {
        //[UserSliderCode_Tweak2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::tweak2, static_cast<float>(Tweak2Sld->getValue()));
        //[/UserSliderCode_Tweak2Sld]
    }
    else if (sliderThatWasMoved == RoutingSld)
    {
        //[UserSliderCode_RoutingSld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::routing, static_cast<float>(RoutingSld->getValue()));
        //[/UserSliderCode_RoutingSld]
    }
    else if (sliderThatWasMoved == MasterVolSld)
    {
        //[UserSliderCode_MasterVolSld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::masterVol, static_cast<float>(MasterVolSld->getValue()));
        //[/UserSliderCode_MasterVolSld]
    }
    else if (sliderThatWasMoved == DryLevelSld)
    {
        //[UserSliderCode_DryLevelSld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::dryLevel, static_cast<float>(DryLevelSld->getValue()));
        //[/UserSliderCode_DryLevelSld]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void CarveAudioProcessorEditor::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    CarveAudioProcessor* ourProcessor {getProcessor()};
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == Mode1Cmb)
    {
        //[UserComboBoxCode_Mode1Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::mode1, static_cast<float>(Mode1Cmb->getSelectedId()));
        //[/UserComboBoxCode_Mode1Cmb]
    }
    else if (comboBoxThatHasChanged == Mode2Cmb)
    {
        //[UserComboBoxCode_Mode2Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::mode2, static_cast<float>(Mode2Cmb->getSelectedId()));
        //[/UserComboBoxCode_Mode2Cmb]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void CarveAudioProcessorEditor::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    CarveAudioProcessor* ourProcessor {getProcessor()};
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == StereoBtn)
    {
        //[UserButtonCode_StereoBtn] -- add your button handler code here..
        ourProcessor->setParameter(CarveAudioProcessor::stereo, static_cast<float>(StereoBtn->getToggleState()));
        //[/UserButtonCode_StereoBtn]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void CarveAudioProcessorEditor::timerCallback() {
    CarveAudioProcessor* ourProcessor {getProcessor()};

    if (ourProcessor->NeedsUIUpdate()) {

        // change group titles if in stereo mode
        if (ourProcessor->getParameter(CarveAudioProcessor::stereo)) {
            Unit1Group->setText(GROUP_LEFT);
            Unit2Group->setText(GROUP_RIGHT);
        } else {
            Unit1Group->setText(GROUP_UNIT1);
            Unit2Group->setText(GROUP_UNIT2);
        }
        
        // disable tweak control for hard clipper wave shape
        Tweak1Sld->setEnabled(ourProcessor->getParameter(CarveAudioProcessor::mode1) != MODE_CLIPPER);
        Tweak2Sld->setEnabled(ourProcessor->getParameter(CarveAudioProcessor::mode2) != MODE_CLIPPER);
        
        
        
        Mode1Cmb->setSelectedId(ourProcessor->getParameter(CarveAudioProcessor::mode1), dontSendNotification);
        PreGain1Sld->setValue(ourProcessor->getParameter(CarveAudioProcessor::preGain1), dontSendNotification);
        PostGain1Sld->setValue(ourProcessor->getParameter(CarveAudioProcessor::postGain1), dontSendNotification);
        Tweak1Sld->setValue(ourProcessor->getParameter(CarveAudioProcessor::tweak1), dontSendNotification);



        Mode2Cmb->setSelectedId(ourProcessor->getParameter(CarveAudioProcessor::mode2), dontSendNotification);
        PreGain2Sld->setValue(ourProcessor->getParameter(CarveAudioProcessor::preGain2), dontSendNotification);
        PostGain2Sld->setValue(ourProcessor->getParameter(CarveAudioProcessor::postGain2), dontSendNotification);
        Tweak2Sld->setValue(ourProcessor->getParameter(CarveAudioProcessor::tweak2), dontSendNotification);



        RoutingSld->setValue(ourProcessor->getParameter(CarveAudioProcessor::routing), dontSendNotification);
        RoutingSld->setEnabled(!ourProcessor->getParameter(CarveAudioProcessor::stereo));   // disable routing if in stereo mode
        StereoBtn->setToggleState(ourProcessor->getParameter(CarveAudioProcessor::stereo), dontSendNotification);
        DryLevelSld->setValue(ourProcessor->getParameter(CarveAudioProcessor::dryLevel), dontSendNotification);
        MasterVolSld->setValue(ourProcessor->getParameter(CarveAudioProcessor::masterVol), dontSendNotification);


    }
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
                 fixedSize="1" initialWidth="375" initialHeight="340">
  <BACKGROUND backgroundColour="ffffffff"/>
  <GROUPCOMPONENT name="Master Group" id="a0ae877bd426411a" memberName="MasterGroup"
                  virtualName="" explicitFocusOrder="0" pos="16 208 344 120" title="Master"
                  textpos="36"/>
  <GROUPCOMPONENT name="Unit 1 Group" id="540af1b8b630cc1f" memberName="Unit1Group"
                  virtualName="" explicitFocusOrder="0" pos="16 48 168 152" title="Unit 1"
                  textpos="36"/>
  <GROUPCOMPONENT name="Unit 2 Group" id="ab152c6e7348165e" memberName="Unit2Group"
                  virtualName="" explicitFocusOrder="0" pos="192 48 168 152" title="Unit 2"
                  textpos="36"/>
  <SLIDER name="PreGain 1 Slider" id="f32c9f6afaac55bd" memberName="PreGain1Sld"
          virtualName="" explicitFocusOrder="0" pos="128 104 32 24" min="0"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="PostGain 1 Slider" id="6c5a77936be07efe" memberName="PostGain1Sld"
          virtualName="" explicitFocusOrder="0" pos="128 136 32 24" min="0"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Tweak 1 Slider" id="94990f0dcf6af35d" memberName="Tweak1Sld"
          virtualName="" explicitFocusOrder="0" pos="128 168 32 24" min="0"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="Mode 1 Combo Box" id="823a631a257df62e" memberName="Mode1Cmb"
            virtualName="" explicitFocusOrder="0" pos="24 72 150 24" editable="0"
            layout="33" items="Sine&#10;Parabolic Soft&#10;Parabolic Hard&#10;Asymmetric Sine&#10;Exponent&#10;Clipper"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="PreGain 2 Slider" id="11f2eb8d84599245" memberName="PreGain2Sld"
          virtualName="" explicitFocusOrder="0" pos="304 104 32 24" min="0"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="PostGain 2 Slider" id="aa9e67169e105a0" memberName="PostGain2Sld"
          virtualName="" explicitFocusOrder="0" pos="304 136 32 24" min="0"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="Tweak 2 Slider" id="63c918fd331adc1c" memberName="Tweak2Sld"
          virtualName="" explicitFocusOrder="0" pos="304 168 32 24" min="0"
          max="1" int="0.010000000000000000208" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <COMBOBOX name="Mode 2 Combo Box" id="13e9b245e523351d" memberName="Mode2Cmb"
            virtualName="" explicitFocusOrder="0" pos="200 72 150 24" editable="0"
            layout="33" items="Sine&#10;Parabolic Soft&#10;Parabolic Hard&#10;Asymmetric Sine&#10;Exponent&#10;Clipper"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="Routing Slider" id="f14b87e6d580ecee" memberName="RoutingSld"
          virtualName="" explicitFocusOrder="0" pos="104 232 96 24" min="0"
          max="1" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="PreGain 1 Label" id="23c42a895f3ddaf2" memberName="PreGain1Lbl"
         virtualName="" explicitFocusOrder="0" pos="32 104 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Pre Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="PostGain 1 Label" id="d4ad48771666454" memberName="PostGain1Lbl"
         virtualName="" explicitFocusOrder="0" pos="32 136 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Post Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="Tweak 1 Label" id="33e8e0f78b54327f" memberName="Tweak1Lbl"
         virtualName="" explicitFocusOrder="0" pos="32 168 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Tweak" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="Serial Label" id="c969ac5b46238aca" memberName="SerialLbl"
         virtualName="" explicitFocusOrder="0" pos="24 232 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Serial" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="Parallel Label" id="a189167740b46f3f" memberName="ParallelLbl"
         virtualName="" explicitFocusOrder="0" pos="208 232 56 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Parallel" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="Master Vol Slider" id="98dbad60d21a006b" memberName="MasterVolSld"
          virtualName="" explicitFocusOrder="0" pos="104 295 240 24" min="0"
          max="1" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Master Vol Label" id="7ced186274c6d879" memberName="MasterVolLbl"
         virtualName="" explicitFocusOrder="0" pos="24 295 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Master Vol" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <LABEL name="PreGain 2 Label" id="1b1fcd244dbb837c" memberName="PreGain2Lbl"
         virtualName="" explicitFocusOrder="0" pos="208 104 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Pre Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="PostGain 2 Label" id="10dbd505cd27ccc1" memberName="PostGain2Lbl"
         virtualName="" explicitFocusOrder="0" pos="208 136 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Post Gain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="Tweak 2 Label" id="1ff0730a1fb3a90b" memberName="Tweak2Lbl"
         virtualName="" explicitFocusOrder="0" pos="208 168 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Tweak" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="Dry Level Slider" id="7d8198da2503bb12" memberName="DryLevelSld"
          virtualName="" explicitFocusOrder="0" pos="104 264 240 24" min="0"
          max="1" int="0.010000000000000000208" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="Dry Level Label" id="877aa0a163a23de7" memberName="DryLevelLbl"
         virtualName="" explicitFocusOrder="0" pos="24 264 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Dry Level" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="Stereo Button" id="e450c34398554a3f" memberName="StereoBtn"
              virtualName="" explicitFocusOrder="0" pos="272 232 70 24" bgColOff="ffb8b8c4"
              buttonText="Stereo" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
