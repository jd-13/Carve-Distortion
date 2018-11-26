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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
CarveAudioProcessorEditor::CarveAudioProcessorEditor (CarveAudioProcessor& ownerFilter)
    : CoreProcessorEditor(ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    MasterGroup.reset (new GroupComponent ("Master Group",
                                           TRANS("MASTER")));
    addAndMakeVisible (MasterGroup.get());
    MasterGroup->setTextLabelPosition (Justification::centred);

    MasterGroup->setBounds (16, 208, 344, 120);

    Unit1Group.reset (new GroupComponent ("Unit 1 Group",
                                          TRANS("UNIT 1")));
    addAndMakeVisible (Unit1Group.get());
    Unit1Group->setTextLabelPosition (Justification::centred);

    Unit1Group->setBounds (16, 48, 168, 152);

    Unit2Group.reset (new GroupComponent ("Unit 2 Group",
                                          TRANS("UNIT 2")));
    addAndMakeVisible (Unit2Group.get());
    Unit2Group->setTextLabelPosition (Justification::centred);

    Unit2Group->setBounds (192, 48, 168, 152);

    PreGain1Sld.reset (new Slider ("PreGain 1 Slider"));
    addAndMakeVisible (PreGain1Sld.get());
    PreGain1Sld->setTooltip (TRANS("Gain applied to the signal before processing"));
    PreGain1Sld->setRange (0, 1, 0.01);
    PreGain1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PreGain1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PreGain1Sld->addListener (this);

    PreGain1Sld->setBounds (128, 104, 32, 24);

    PostGain1Sld.reset (new Slider ("PostGain 1 Slider"));
    addAndMakeVisible (PostGain1Sld.get());
    PostGain1Sld->setTooltip (TRANS("Gain applied to the signal after processing"));
    PostGain1Sld->setRange (0, 1, 0.01);
    PostGain1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PostGain1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PostGain1Sld->addListener (this);

    PostGain1Sld->setBounds (128, 136, 32, 24);

    Tweak1Sld.reset (new Slider ("Tweak 1 Slider"));
    addAndMakeVisible (Tweak1Sld.get());
    Tweak1Sld->setTooltip (TRANS("Morphs the wave shape applied to the signal"));
    Tweak1Sld->setRange (0, 1, 0.01);
    Tweak1Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    Tweak1Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    Tweak1Sld->addListener (this);

    Tweak1Sld->setBounds (128, 168, 32, 24);

    Mode1Cmb.reset (new ComboBox ("Mode 1 Combo Box"));
    addAndMakeVisible (Mode1Cmb.get());
    Mode1Cmb->setTooltip (TRANS("Wave shape applied to the signal"));
    Mode1Cmb->setEditableText (false);
    Mode1Cmb->setJustificationType (Justification::centredLeft);
    Mode1Cmb->setTextWhenNothingSelected (String());
    Mode1Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    Mode1Cmb->addItem (TRANS("Off"), 1);
    Mode1Cmb->addItem (TRANS("Sine"), 2);
    Mode1Cmb->addItem (TRANS("Parabolic Soft"), 3);
    Mode1Cmb->addItem (TRANS("Parabolic Hard"), 4);
    Mode1Cmb->addItem (TRANS("Asymmetric Sine"), 5);
    Mode1Cmb->addItem (TRANS("Exponent"), 6);
    Mode1Cmb->addItem (TRANS("Clipper"), 7);
    Mode1Cmb->addListener (this);

    Mode1Cmb->setBounds (24, 72, 150, 24);

    PreGain2Sld.reset (new Slider ("PreGain 2 Slider"));
    addAndMakeVisible (PreGain2Sld.get());
    PreGain2Sld->setTooltip (TRANS("Gain applied to the signal before processing"));
    PreGain2Sld->setRange (0, 1, 0.01);
    PreGain2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PreGain2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PreGain2Sld->addListener (this);

    PreGain2Sld->setBounds (304, 104, 32, 24);

    PostGain2Sld.reset (new Slider ("PostGain 2 Slider"));
    addAndMakeVisible (PostGain2Sld.get());
    PostGain2Sld->setTooltip (TRANS("Gain applied to the signal after processing"));
    PostGain2Sld->setRange (0, 1, 0.01);
    PostGain2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    PostGain2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    PostGain2Sld->addListener (this);

    PostGain2Sld->setBounds (304, 136, 32, 24);

    Tweak2Sld.reset (new Slider ("Tweak 2 Slider"));
    addAndMakeVisible (Tweak2Sld.get());
    Tweak2Sld->setTooltip (TRANS("Morphs the wave shape applied to the signal"));
    Tweak2Sld->setRange (0, 1, 0.01);
    Tweak2Sld->setSliderStyle (Slider::RotaryVerticalDrag);
    Tweak2Sld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    Tweak2Sld->addListener (this);

    Tweak2Sld->setBounds (304, 168, 32, 24);

    Mode2Cmb.reset (new ComboBox ("Mode 2 Combo Box"));
    addAndMakeVisible (Mode2Cmb.get());
    Mode2Cmb->setTooltip (TRANS("Wave shape applied to the signal"));
    Mode2Cmb->setEditableText (false);
    Mode2Cmb->setJustificationType (Justification::centredLeft);
    Mode2Cmb->setTextWhenNothingSelected (String());
    Mode2Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    Mode2Cmb->addItem (TRANS("Off"), 1);
    Mode2Cmb->addItem (TRANS("Sine"), 2);
    Mode2Cmb->addItem (TRANS("Parabolic Soft"), 3);
    Mode2Cmb->addItem (TRANS("Parabolic Hard"), 4);
    Mode2Cmb->addItem (TRANS("Asymmetric Sine"), 5);
    Mode2Cmb->addItem (TRANS("Exponent"), 6);
    Mode2Cmb->addItem (TRANS("Clipper"), 7);
    Mode2Cmb->addListener (this);

    Mode2Cmb->setBounds (200, 72, 150, 24);

    RoutingSld.reset (new Slider ("Routing Slider"));
    addAndMakeVisible (RoutingSld.get());
    RoutingSld->setTooltip (TRANS("Routing of the signal between the two distortion units"));
    RoutingSld->setRange (0, 1, 0.01);
    RoutingSld->setSliderStyle (Slider::LinearHorizontal);
    RoutingSld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    RoutingSld->addListener (this);

    RoutingSld->setBounds (104, 232, 96, 24);

    PreGain1Lbl.reset (new Label ("PreGain 1 Label",
                                  TRANS("Pre Gain")));
    addAndMakeVisible (PreGain1Lbl.get());
    PreGain1Lbl->setFont (Font ("Courier New", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    PreGain1Lbl->setJustificationType (Justification::centredLeft);
    PreGain1Lbl->setEditable (false, false, false);
    PreGain1Lbl->setColour (Label::textColourId, Colour (0xffc6cd66));
    PreGain1Lbl->setColour (Label::outlineColourId, Colour (0x00d83535));
    PreGain1Lbl->setColour (TextEditor::textColourId, Colours::black);
    PreGain1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PreGain1Lbl->setBounds (32, 104, 88, 24);

    PostGain1Lbl.reset (new Label ("PostGain 1 Label",
                                   TRANS("Post Gain")));
    addAndMakeVisible (PostGain1Lbl.get());
    PostGain1Lbl->setFont (Font ("Courier New", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    PostGain1Lbl->setJustificationType (Justification::centredLeft);
    PostGain1Lbl->setEditable (false, false, false);
    PostGain1Lbl->setColour (Label::textColourId, Colour (0xffc6cd66));
    PostGain1Lbl->setColour (TextEditor::textColourId, Colours::black);
    PostGain1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PostGain1Lbl->setBounds (32, 136, 88, 24);

    Tweak1Lbl.reset (new Label ("Tweak 1 Label",
                                TRANS("Tweak")));
    addAndMakeVisible (Tweak1Lbl.get());
    Tweak1Lbl->setFont (Font ("Courier New", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    Tweak1Lbl->setJustificationType (Justification::centredLeft);
    Tweak1Lbl->setEditable (false, false, false);
    Tweak1Lbl->setColour (Label::textColourId, Colour (0xffc6cd66));
    Tweak1Lbl->setColour (TextEditor::textColourId, Colours::black);
    Tweak1Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Tweak1Lbl->setBounds (32, 168, 64, 24);

    SerialLbl.reset (new Label ("Serial Label",
                                TRANS("Serial")));
    addAndMakeVisible (SerialLbl.get());
    SerialLbl->setFont (Font ("Courier New", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    SerialLbl->setJustificationType (Justification::centred);
    SerialLbl->setEditable (false, false, false);
    SerialLbl->setColour (Label::textColourId, Colour (0xffc6cd66));
    SerialLbl->setColour (TextEditor::textColourId, Colours::black);
    SerialLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    SerialLbl->setBounds (24, 232, 80, 24);

    ParallelLbl.reset (new Label ("Parallel Label",
                                  TRANS("Parallel")));
    addAndMakeVisible (ParallelLbl.get());
    ParallelLbl->setFont (Font ("Courier New", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    ParallelLbl->setJustificationType (Justification::centredLeft);
    ParallelLbl->setEditable (false, false, false);
    ParallelLbl->setColour (Label::textColourId, Colour (0xffc6cd66));
    ParallelLbl->setColour (TextEditor::textColourId, Colours::black);
    ParallelLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    ParallelLbl->setBounds (200, 232, 64, 24);

    MasterVolSld.reset (new Slider ("Master Vol Slider"));
    addAndMakeVisible (MasterVolSld.get());
    MasterVolSld->setTooltip (TRANS("Master volume"));
    MasterVolSld->setRange (0, 1, 0.01);
    MasterVolSld->setSliderStyle (Slider::LinearHorizontal);
    MasterVolSld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    MasterVolSld->addListener (this);

    MasterVolSld->setBounds (104, 295, 240, 24);

    MasterVolLbl.reset (new Label ("Master Vol Label",
                                   TRANS("Master Vol")));
    addAndMakeVisible (MasterVolLbl.get());
    MasterVolLbl->setFont (Font ("Courier New", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    MasterVolLbl->setJustificationType (Justification::centred);
    MasterVolLbl->setEditable (false, false, false);
    MasterVolLbl->setColour (Label::textColourId, Colour (0xffc6cd66));
    MasterVolLbl->setColour (TextEditor::textColourId, Colours::black);
    MasterVolLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    MasterVolLbl->setBounds (24, 295, 80, 24);

    PreGain2Lbl.reset (new Label ("PreGain 2 Label",
                                  TRANS("Pre Gain")));
    addAndMakeVisible (PreGain2Lbl.get());
    PreGain2Lbl->setFont (Font ("Courier New", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    PreGain2Lbl->setJustificationType (Justification::centredLeft);
    PreGain2Lbl->setEditable (false, false, false);
    PreGain2Lbl->setColour (Label::textColourId, Colour (0xffc6cd66));
    PreGain2Lbl->setColour (TextEditor::textColourId, Colours::black);
    PreGain2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PreGain2Lbl->setBounds (208, 104, 88, 24);

    PostGain2Lbl.reset (new Label ("PostGain 2 Label",
                                   TRANS("Post Gain")));
    addAndMakeVisible (PostGain2Lbl.get());
    PostGain2Lbl->setFont (Font ("Courier New", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    PostGain2Lbl->setJustificationType (Justification::centredLeft);
    PostGain2Lbl->setEditable (false, false, false);
    PostGain2Lbl->setColour (Label::textColourId, Colour (0xffc6cd66));
    PostGain2Lbl->setColour (TextEditor::textColourId, Colours::black);
    PostGain2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    PostGain2Lbl->setBounds (208, 136, 88, 24);

    Tweak2Lbl.reset (new Label ("Tweak 2 Label",
                                TRANS("Tweak")));
    addAndMakeVisible (Tweak2Lbl.get());
    Tweak2Lbl->setFont (Font ("Courier New", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    Tweak2Lbl->setJustificationType (Justification::centredLeft);
    Tweak2Lbl->setEditable (false, false, false);
    Tweak2Lbl->setColour (Label::textColourId, Colour (0xffc6cd66));
    Tweak2Lbl->setColour (TextEditor::textColourId, Colours::black);
    Tweak2Lbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    Tweak2Lbl->setBounds (208, 168, 64, 24);

    DryLevelSld.reset (new Slider ("Dry Level Slider"));
    addAndMakeVisible (DryLevelSld.get());
    DryLevelSld->setTooltip (TRANS("Adds the unprocessed signal into the output"));
    DryLevelSld->setRange (0, 1, 0.01);
    DryLevelSld->setSliderStyle (Slider::LinearHorizontal);
    DryLevelSld->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    DryLevelSld->addListener (this);

    DryLevelSld->setBounds (104, 264, 240, 24);

    DryLevelLbl.reset (new Label ("Dry Level Label",
                                  TRANS("Dry Level")));
    addAndMakeVisible (DryLevelLbl.get());
    DryLevelLbl->setFont (Font ("Courier New", 15.0f, Font::plain).withTypefaceStyle ("Regular"));
    DryLevelLbl->setJustificationType (Justification::centred);
    DryLevelLbl->setEditable (false, false, false);
    DryLevelLbl->setColour (Label::textColourId, Colour (0xffc6cd66));
    DryLevelLbl->setColour (TextEditor::textColourId, Colours::black);
    DryLevelLbl->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    DryLevelLbl->setBounds (24, 264, 80, 24);

    StereoBtn.reset (new TextButton ("Stereo Button"));
    addAndMakeVisible (StereoBtn.get());
    StereoBtn->setTooltip (TRANS("Allows unit 1 and unit 2 to process the left and right channels independently"));
    StereoBtn->setButtonText (TRANS("Stereo"));
    StereoBtn->addListener (this);
    StereoBtn->setColour (TextButton::buttonColourId, Colour (0xffb8b8c4));

    StereoBtn->setBounds (272, 232, 70, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (375, 340);


    //[Constructor] You can add your own custom stuff here..
    startTimer(200);

    customLookAndFeel.setHighlightColour(Colour(0.15f, 1.0f, 1.0f, 1.0f));
    _assignLookAndFeelToAllChildren(customLookAndFeel);

    // disable stereo mode if only single output
    CarveAudioProcessor* ourProcessor {getProcessor()};
    StereoBtn->setEnabled(ourProcessor->getNumOutputChannels() == 2);

    // set double click to default for sliders
    PreGain1Sld->setDoubleClickReturnValue(true,
        WECore::Carve::Parameters::PREGAIN.InteralToNormalised(WECore::Carve::Parameters::PREGAIN.defaultValue));
    PostGain1Sld->setDoubleClickReturnValue(true,
        WECore::Carve::Parameters::POSTGAIN.InteralToNormalised(WECore::Carve::Parameters::POSTGAIN.defaultValue));
    Tweak1Sld->setDoubleClickReturnValue(true,
        WECore::Carve::Parameters::TWEAK.InteralToNormalised(WECore::Carve::Parameters::TWEAK.defaultValue));

    PreGain2Sld->setDoubleClickReturnValue(true,
        WECore::Carve::Parameters::PREGAIN.InteralToNormalised(WECore::Carve::Parameters::PREGAIN.defaultValue));
    PostGain2Sld->setDoubleClickReturnValue(true,
        WECore::Carve::Parameters::POSTGAIN.InteralToNormalised(WECore::Carve::Parameters::POSTGAIN.defaultValue));
    Tweak2Sld->setDoubleClickReturnValue(true,
        WECore::Carve::Parameters::TWEAK.InteralToNormalised(WECore::Carve::Parameters::TWEAK.defaultValue));

    RoutingSld->setDoubleClickReturnValue(true, ROUTING.InteralToNormalised(ROUTING.defaultValue));
    DryLevelSld->setDoubleClickReturnValue(true, DRYLEVEL.InteralToNormalised(DRYLEVEL.defaultValue));
    MasterVolSld->setDoubleClickReturnValue(true, MASTERVOL.InteralToNormalised(MASTERVOL.defaultValue));
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

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    Image bg = ImageCache::getFromMemory(BinaryData::background_jpeg, BinaryData::background_jpegSize);
    g.drawImage(bg, 0, 0, 375, 340, 0, 0, 5 * 375, 5 * 340);

    _drawDividers(g);
    //[/UserPaint]
}

void CarveAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void CarveAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    CarveAudioProcessor* ourProcessor {getProcessor()};
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == PreGain1Sld.get())
    {
        //[UserSliderCode_PreGain1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::preGain1, static_cast<float>(PreGain1Sld->getValue()));
        //[/UserSliderCode_PreGain1Sld]
    }
    else if (sliderThatWasMoved == PostGain1Sld.get())
    {
        //[UserSliderCode_PostGain1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::postGain1, static_cast<float>(PostGain1Sld->getValue()));
        //[/UserSliderCode_PostGain1Sld]
    }
    else if (sliderThatWasMoved == Tweak1Sld.get())
    {
        //[UserSliderCode_Tweak1Sld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::tweak1, static_cast<float>(Tweak1Sld->getValue()));
        //[/UserSliderCode_Tweak1Sld]
    }
    else if (sliderThatWasMoved == PreGain2Sld.get())
    {
        //[UserSliderCode_PreGain2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::preGain2, static_cast<float>(PreGain2Sld->getValue()));
        //[/UserSliderCode_PreGain2Sld]
    }
    else if (sliderThatWasMoved == PostGain2Sld.get())
    {
        //[UserSliderCode_PostGain2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::postGain2, static_cast<float>(PostGain2Sld->getValue()));
        //[/UserSliderCode_PostGain2Sld]
    }
    else if (sliderThatWasMoved == Tweak2Sld.get())
    {
        //[UserSliderCode_Tweak2Sld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::tweak2, static_cast<float>(Tweak2Sld->getValue()));
        //[/UserSliderCode_Tweak2Sld]
    }
    else if (sliderThatWasMoved == RoutingSld.get())
    {
        //[UserSliderCode_RoutingSld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::routing, static_cast<float>(RoutingSld->getValue()));
        //[/UserSliderCode_RoutingSld]
    }
    else if (sliderThatWasMoved == MasterVolSld.get())
    {
        //[UserSliderCode_MasterVolSld] -- add your slider handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::masterVol, static_cast<float>(MasterVolSld->getValue()));
        //[/UserSliderCode_MasterVolSld]
    }
    else if (sliderThatWasMoved == DryLevelSld.get())
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

    if (comboBoxThatHasChanged == Mode1Cmb.get())
    {
        //[UserComboBoxCode_Mode1Cmb] -- add your combo box handling code here..
        ourProcessor->setParameter(CarveAudioProcessor::mode1, static_cast<float>(Mode1Cmb->getSelectedId()));
        //[/UserComboBoxCode_Mode1Cmb]
    }
    else if (comboBoxThatHasChanged == Mode2Cmb.get())
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

    if (buttonThatWasClicked == StereoBtn.get())
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

    if (ourProcessor->needsUIUpdate()) {

        // change group titles if in stereo mode
        if (ourProcessor->getParameter(CarveAudioProcessor::stereo)) {
            Unit1Group->setText(GROUP_LEFT);
            Unit2Group->setText(GROUP_RIGHT);
        } else {
            Unit1Group->setText(GROUP_UNIT1);
            Unit2Group->setText(GROUP_UNIT2);
        }

        // disable tweak control for exponent and hard clipper wave shape
        const float mode1 {ourProcessor->getParameter(CarveAudioProcessor::mode1)};
        if (mode1 == WECore::Carve::Parameters::MODE.EXPONENT || mode1 == WECore::Carve::Parameters::MODE.CLIPPER) {
            Tweak1Sld->setEnabled(false);
        } else {
            Tweak1Sld->setEnabled(true);
        }

        const float mode2 {ourProcessor->getParameter(CarveAudioProcessor::mode2)};
        if (mode2 == WECore::Carve::Parameters::MODE.EXPONENT || mode2 == WECore::Carve::Parameters::MODE.CLIPPER) {
            Tweak2Sld->setEnabled(false);
        } else {
            Tweak2Sld->setEnabled(true);
        }


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

void CarveAudioProcessorEditor::_drawDividers(Graphics &g) const {

    auto drawDivider = [&g](Line<float> line) -> void {
        // Set the gradient
        const float lineXLength {std::abs(line.getStartX() - line.getEndX())};
        const float lineYLength {std::abs(line.getStartY() - line.getEndY())};

        g.setGradientFill(ColourGradient(Colour(0.15f, 1.0f, 0.5f, 1.0f),
                                         line.getStartX() + lineXLength / 2,
                                         line.getStartY() + lineYLength /2,
                                         Colour(0.15f, 1.0f, 0.5f, 0.1f),
                                         line.getStartX(),
                                         line.getStartY(),
                                         true));

        // Calculate and draw the dashes
        constexpr float dashLength {4};
        const int numDashes {static_cast<int>(line.getLength() / (dashLength * 2))};

        const std::vector<float> dashLengths(numDashes * 2, dashLength);

        g.drawDashedLine(line, &dashLengths[0], 4);

    };

    drawDivider(Line<float>(187, 51, 187, 51 + 140));
    drawDivider(Line<float>(52, 206, 52 + 270, 206));
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="CarveAudioProcessorEditor"
                 componentName="" parentClasses="public WECore::JUCEPlugin::CoreProcessorEditor, public Timer"
                 constructorParams="CarveAudioProcessor&amp; ownerFilter" variableInitialisers="CoreProcessorEditor(ownerFilter)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.33"
                 fixedSize="1" initialWidth="375" initialHeight="340">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GROUPCOMPONENT name="Master Group" id="a0ae877bd426411a" memberName="MasterGroup"
                  virtualName="" explicitFocusOrder="0" pos="16 208 344 120" title="MASTER"
                  textpos="36"/>
  <GROUPCOMPONENT name="Unit 1 Group" id="540af1b8b630cc1f" memberName="Unit1Group"
                  virtualName="" explicitFocusOrder="0" pos="16 48 168 152" title="UNIT 1"
                  textpos="36"/>
  <GROUPCOMPONENT name="Unit 2 Group" id="ab152c6e7348165e" memberName="Unit2Group"
                  virtualName="" explicitFocusOrder="0" pos="192 48 168 152" title="UNIT 2"
                  textpos="36"/>
  <SLIDER name="PreGain 1 Slider" id="f32c9f6afaac55bd" memberName="PreGain1Sld"
          virtualName="" explicitFocusOrder="0" pos="128 104 32 24" tooltip="Gain applied to the signal before processing"
          min="0.0" max="1.0" int="0.01000000000000000021" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="PostGain 1 Slider" id="6c5a77936be07efe" memberName="PostGain1Sld"
          virtualName="" explicitFocusOrder="0" pos="128 136 32 24" tooltip="Gain applied to the signal after processing"
          min="0.0" max="1.0" int="0.01000000000000000021" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Tweak 1 Slider" id="94990f0dcf6af35d" memberName="Tweak1Sld"
          virtualName="" explicitFocusOrder="0" pos="128 168 32 24" tooltip="Morphs the wave shape applied to the signal"
          min="0.0" max="1.0" int="0.01000000000000000021" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <COMBOBOX name="Mode 1 Combo Box" id="823a631a257df62e" memberName="Mode1Cmb"
            virtualName="" explicitFocusOrder="0" pos="24 72 150 24" tooltip="Wave shape applied to the signal"
            editable="0" layout="33" items="Off&#10;Sine&#10;Parabolic Soft&#10;Parabolic Hard&#10;Asymmetric Sine&#10;Exponent&#10;Clipper"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="PreGain 2 Slider" id="11f2eb8d84599245" memberName="PreGain2Sld"
          virtualName="" explicitFocusOrder="0" pos="304 104 32 24" tooltip="Gain applied to the signal before processing"
          min="0.0" max="1.0" int="0.01000000000000000021" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="PostGain 2 Slider" id="aa9e67169e105a0" memberName="PostGain2Sld"
          virtualName="" explicitFocusOrder="0" pos="304 136 32 24" tooltip="Gain applied to the signal after processing"
          min="0.0" max="1.0" int="0.01000000000000000021" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="Tweak 2 Slider" id="63c918fd331adc1c" memberName="Tweak2Sld"
          virtualName="" explicitFocusOrder="0" pos="304 168 32 24" tooltip="Morphs the wave shape applied to the signal"
          min="0.0" max="1.0" int="0.01000000000000000021" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <COMBOBOX name="Mode 2 Combo Box" id="13e9b245e523351d" memberName="Mode2Cmb"
            virtualName="" explicitFocusOrder="0" pos="200 72 150 24" tooltip="Wave shape applied to the signal"
            editable="0" layout="33" items="Off&#10;Sine&#10;Parabolic Soft&#10;Parabolic Hard&#10;Asymmetric Sine&#10;Exponent&#10;Clipper"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="Routing Slider" id="f14b87e6d580ecee" memberName="RoutingSld"
          virtualName="" explicitFocusOrder="0" pos="104 232 96 24" tooltip="Routing of the signal between the two distortion units"
          min="0.0" max="1.0" int="0.01000000000000000021" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="PreGain 1 Label" id="23c42a895f3ddaf2" memberName="PreGain1Lbl"
         virtualName="" explicitFocusOrder="0" pos="32 104 88 24" textCol="ffc6cd66"
         outlineCol="d83535" edTextCol="ff000000" edBkgCol="0" labelText="Pre Gain"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Courier New" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <LABEL name="PostGain 1 Label" id="d4ad48771666454" memberName="PostGain1Lbl"
         virtualName="" explicitFocusOrder="0" pos="32 136 88 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Post Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Courier New"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="Tweak 1 Label" id="33e8e0f78b54327f" memberName="Tweak1Lbl"
         virtualName="" explicitFocusOrder="0" pos="32 168 64 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Tweak" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Courier New"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="Serial Label" id="c969ac5b46238aca" memberName="SerialLbl"
         virtualName="" explicitFocusOrder="0" pos="24 232 80 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Serial" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Courier New"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="Parallel Label" id="a189167740b46f3f" memberName="ParallelLbl"
         virtualName="" explicitFocusOrder="0" pos="200 232 64 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Parallel" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Courier New"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="Master Vol Slider" id="98dbad60d21a006b" memberName="MasterVolSld"
          virtualName="" explicitFocusOrder="0" pos="104 295 240 24" tooltip="Master volume"
          min="0.0" max="1.0" int="0.01000000000000000021" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="Master Vol Label" id="7ced186274c6d879" memberName="MasterVolLbl"
         virtualName="" explicitFocusOrder="0" pos="24 295 80 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Master Vol" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Courier New"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="PreGain 2 Label" id="1b1fcd244dbb837c" memberName="PreGain2Lbl"
         virtualName="" explicitFocusOrder="0" pos="208 104 88 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Pre Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Courier New"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="PostGain 2 Label" id="10dbd505cd27ccc1" memberName="PostGain2Lbl"
         virtualName="" explicitFocusOrder="0" pos="208 136 88 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Post Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Courier New"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="Tweak 2 Label" id="1ff0730a1fb3a90b" memberName="Tweak2Lbl"
         virtualName="" explicitFocusOrder="0" pos="208 168 64 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Tweak" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Courier New"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="Dry Level Slider" id="7d8198da2503bb12" memberName="DryLevelSld"
          virtualName="" explicitFocusOrder="0" pos="104 264 240 24" tooltip="Adds the unprocessed signal into the output"
          min="0.0" max="1.0" int="0.01000000000000000021" style="LinearHorizontal"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <LABEL name="Dry Level Label" id="877aa0a163a23de7" memberName="DryLevelLbl"
         virtualName="" explicitFocusOrder="0" pos="24 264 80 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Dry Level" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Courier New"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="Stereo Button" id="e450c34398554a3f" memberName="StereoBtn"
              virtualName="" explicitFocusOrder="0" pos="272 232 70 24" tooltip="Allows unit 1 and unit 2 to process the left and right channels independently"
              bgColOff="ffb8b8c4" buttonText="Stereo" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
