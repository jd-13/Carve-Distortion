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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
CarveAudioProcessorEditor::CarveAudioProcessorEditor (CarveAudioProcessor& ownerFilter)
    : CoreProcessorEditor(ownerFilter), _highlightColour(0.15f, 1.0f, 1.0f, 1.0f)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    RoutingGroup.reset (new juce::GroupComponent ("Routing Group",
                                                  TRANS("ROUTING")));
    addAndMakeVisible (RoutingGroup.get());
    RoutingGroup->setTextLabelPosition (juce::Justification::centred);

    RoutingGroup->setBounds (16, 288, 344, 120);

    Unit1Group.reset (new juce::GroupComponent ("Unit 1 Group",
                                                TRANS("UNIT 1")));
    addAndMakeVisible (Unit1Group.get());
    Unit1Group->setTextLabelPosition (juce::Justification::centred);

    Unit1Group->setBounds (16, 48, 168, 232);

    Unit2Group.reset (new juce::GroupComponent ("Unit 2 Group",
                                                TRANS("UNIT 2")));
    addAndMakeVisible (Unit2Group.get());
    Unit2Group->setTextLabelPosition (juce::Justification::centred);

    Unit2Group->setBounds (192, 48, 168, 232);

    PreGain1Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("PreGain 1 Slider"));
    addAndMakeVisible (PreGain1Sld.get());
    PreGain1Sld->setTooltip (TRANS("Gain applied to the signal before processing"));
    PreGain1Sld->setRange (0, 1, 0.01);
    PreGain1Sld->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    PreGain1Sld->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    PreGain1Sld->addListener (this);

    PreGain1Sld->setBounds (128, 176, 32, 24);

    PostGain1Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("PostGain 1 Slider"));
    addAndMakeVisible (PostGain1Sld.get());
    PostGain1Sld->setTooltip (TRANS("Gain applied to the signal after processing"));
    PostGain1Sld->setRange (0, 1, 0.01);
    PostGain1Sld->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    PostGain1Sld->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    PostGain1Sld->addListener (this);

    PostGain1Sld->setBounds (128, 208, 32, 24);

    Tweak1Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("Tweak 1 Slider"));
    addAndMakeVisible (Tweak1Sld.get());
    Tweak1Sld->setTooltip (TRANS("Morphs the wave shape applied to the signal"));
    Tweak1Sld->setRange (0, 1, 0.01);
    Tweak1Sld->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Tweak1Sld->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    Tweak1Sld->addListener (this);

    Tweak1Sld->setBounds (128, 240, 32, 24);

    Mode1Cmb.reset (new juce::ComboBox ("Mode 1 Combo Box"));
    addAndMakeVisible (Mode1Cmb.get());
    Mode1Cmb->setTooltip (TRANS("Wave shape applied to the signal"));
    Mode1Cmb->setEditableText (false);
    Mode1Cmb->setJustificationType (juce::Justification::centredLeft);
    Mode1Cmb->setTextWhenNothingSelected (juce::String());
    Mode1Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    Mode1Cmb->addItem (TRANS("Off"), 1);
    Mode1Cmb->addItem (TRANS("Sine"), 2);
    Mode1Cmb->addItem (TRANS("Parabolic Soft"), 3);
    Mode1Cmb->addItem (TRANS("Parabolic Hard"), 4);
    Mode1Cmb->addItem (TRANS("Asymmetric Sine"), 5);
    Mode1Cmb->addItem (TRANS("Exponent"), 6);
    Mode1Cmb->addItem (TRANS("Clipper"), 7);
    Mode1Cmb->addListener (this);

    Mode1Cmb->setBounds (24, 136, 150, 24);

    PreGain2Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("PreGain 2 Slider"));
    addAndMakeVisible (PreGain2Sld.get());
    PreGain2Sld->setTooltip (TRANS("Gain applied to the signal before processing"));
    PreGain2Sld->setRange (0, 1, 0.01);
    PreGain2Sld->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    PreGain2Sld->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    PreGain2Sld->addListener (this);

    PreGain2Sld->setBounds (304, 176, 32, 24);

    PostGain2Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("PostGain 2 Slider"));
    addAndMakeVisible (PostGain2Sld.get());
    PostGain2Sld->setTooltip (TRANS("Gain applied to the signal after processing"));
    PostGain2Sld->setRange (0, 1, 0.01);
    PostGain2Sld->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    PostGain2Sld->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    PostGain2Sld->addListener (this);

    PostGain2Sld->setBounds (304, 208, 32, 24);

    Tweak2Sld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<double> ("Tweak 2 Slider"));
    addAndMakeVisible (Tweak2Sld.get());
    Tweak2Sld->setTooltip (TRANS("Morphs the wave shape applied to the signal"));
    Tweak2Sld->setRange (0, 1, 0.01);
    Tweak2Sld->setSliderStyle (juce::Slider::RotaryVerticalDrag);
    Tweak2Sld->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    Tweak2Sld->addListener (this);

    Tweak2Sld->setBounds (304, 240, 32, 24);

    Mode2Cmb.reset (new juce::ComboBox ("Mode 2 Combo Box"));
    addAndMakeVisible (Mode2Cmb.get());
    Mode2Cmb->setTooltip (TRANS("Wave shape applied to the signal"));
    Mode2Cmb->setEditableText (false);
    Mode2Cmb->setJustificationType (juce::Justification::centredLeft);
    Mode2Cmb->setTextWhenNothingSelected (juce::String());
    Mode2Cmb->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    Mode2Cmb->addItem (TRANS("Off"), 1);
    Mode2Cmb->addItem (TRANS("Sine"), 2);
    Mode2Cmb->addItem (TRANS("Parabolic Soft"), 3);
    Mode2Cmb->addItem (TRANS("Parabolic Hard"), 4);
    Mode2Cmb->addItem (TRANS("Asymmetric Sine"), 5);
    Mode2Cmb->addItem (TRANS("Exponent"), 6);
    Mode2Cmb->addItem (TRANS("Clipper"), 7);
    Mode2Cmb->addListener (this);

    Mode2Cmb->setBounds (200, 136, 150, 24);

    RoutingSld.reset (new CarveDualLabelReadoutSlider ("Routing Slider"));
    addAndMakeVisible (RoutingSld.get());
    RoutingSld->setTooltip (TRANS("Routing of the signal between the two distortion units"));
    RoutingSld->setRange (0, 1, 0.01);
    RoutingSld->setSliderStyle (juce::Slider::LinearHorizontal);
    RoutingSld->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    RoutingSld->addListener (this);

    RoutingSld->setBounds (112, 312, 88, 24);

    PreGain1Lbl.reset (new juce::Label ("PreGain 1 Label",
                                        TRANS("Pre Gain")));
    addAndMakeVisible (PreGain1Lbl.get());
    PreGain1Lbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    PreGain1Lbl->setJustificationType (juce::Justification::centredLeft);
    PreGain1Lbl->setEditable (false, false, false);
    PreGain1Lbl->setColour (juce::Label::textColourId, juce::Colour (0xffc6cd66));
    PreGain1Lbl->setColour (juce::Label::outlineColourId, juce::Colour (0x00d83535));
    PreGain1Lbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    PreGain1Lbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    PreGain1Lbl->setBounds (32, 176, 88, 24);

    PostGain1Lbl.reset (new juce::Label ("PostGain 1 Label",
                                         TRANS("Post Gain")));
    addAndMakeVisible (PostGain1Lbl.get());
    PostGain1Lbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    PostGain1Lbl->setJustificationType (juce::Justification::centredLeft);
    PostGain1Lbl->setEditable (false, false, false);
    PostGain1Lbl->setColour (juce::Label::textColourId, juce::Colour (0xffc6cd66));
    PostGain1Lbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    PostGain1Lbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    PostGain1Lbl->setBounds (32, 208, 88, 24);

    Tweak1Lbl.reset (new juce::Label ("Tweak 1 Label",
                                      TRANS("Tweak")));
    addAndMakeVisible (Tweak1Lbl.get());
    Tweak1Lbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    Tweak1Lbl->setJustificationType (juce::Justification::centredLeft);
    Tweak1Lbl->setEditable (false, false, false);
    Tweak1Lbl->setColour (juce::Label::textColourId, juce::Colour (0xffc6cd66));
    Tweak1Lbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    Tweak1Lbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    Tweak1Lbl->setBounds (32, 240, 64, 24);

    SerialLbl.reset (new juce::Label ("Serial Label",
                                      TRANS("Serial")));
    addAndMakeVisible (SerialLbl.get());
    SerialLbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    SerialLbl->setJustificationType (juce::Justification::centred);
    SerialLbl->setEditable (false, false, false);
    SerialLbl->setColour (juce::Label::textColourId, juce::Colour (0xffc6cd66));
    SerialLbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    SerialLbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    SerialLbl->setBounds (24, 312, 88, 24);

    ParallelLbl.reset (new juce::Label ("Parallel Label",
                                        TRANS("Parallel")));
    addAndMakeVisible (ParallelLbl.get());
    ParallelLbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    ParallelLbl->setJustificationType (juce::Justification::centredLeft);
    ParallelLbl->setEditable (false, false, false);
    ParallelLbl->setColour (juce::Label::textColourId, juce::Colour (0xffc6cd66));
    ParallelLbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    ParallelLbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    ParallelLbl->setBounds (200, 312, 64, 24);

    OutputGainSld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<float> ("Output Gain Slider"));
    addAndMakeVisible (OutputGainSld.get());
    OutputGainSld->setTooltip (TRANS("Output gain"));
    OutputGainSld->setRange (0, 1, 0.01);
    OutputGainSld->setSliderStyle (juce::Slider::LinearHorizontal);
    OutputGainSld->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    OutputGainSld->addListener (this);

    OutputGainSld->setBounds (112, 375, 232, 24);

    OutputGainLbl.reset (new juce::Label ("Output Gain Label",
                                          TRANS("Output Gain")));
    addAndMakeVisible (OutputGainLbl.get());
    OutputGainLbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    OutputGainLbl->setJustificationType (juce::Justification::centred);
    OutputGainLbl->setEditable (false, false, false);
    OutputGainLbl->setColour (juce::Label::textColourId, juce::Colour (0xffc6cd66));
    OutputGainLbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    OutputGainLbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    OutputGainLbl->setBounds (24, 375, 88, 24);

    PreGain2Lbl.reset (new juce::Label ("PreGain 2 Label",
                                        TRANS("Pre Gain")));
    addAndMakeVisible (PreGain2Lbl.get());
    PreGain2Lbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    PreGain2Lbl->setJustificationType (juce::Justification::centredLeft);
    PreGain2Lbl->setEditable (false, false, false);
    PreGain2Lbl->setColour (juce::Label::textColourId, juce::Colour (0xffc6cd66));
    PreGain2Lbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    PreGain2Lbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    PreGain2Lbl->setBounds (208, 176, 88, 24);

    PostGain2Lbl.reset (new juce::Label ("PostGain 2 Label",
                                         TRANS("Post Gain")));
    addAndMakeVisible (PostGain2Lbl.get());
    PostGain2Lbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    PostGain2Lbl->setJustificationType (juce::Justification::centredLeft);
    PostGain2Lbl->setEditable (false, false, false);
    PostGain2Lbl->setColour (juce::Label::textColourId, juce::Colour (0xffc6cd66));
    PostGain2Lbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    PostGain2Lbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    PostGain2Lbl->setBounds (208, 208, 88, 24);

    Tweak2Lbl.reset (new juce::Label ("Tweak 2 Label",
                                      TRANS("Tweak")));
    addAndMakeVisible (Tweak2Lbl.get());
    Tweak2Lbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    Tweak2Lbl->setJustificationType (juce::Justification::centredLeft);
    Tweak2Lbl->setEditable (false, false, false);
    Tweak2Lbl->setColour (juce::Label::textColourId, juce::Colour (0xffc6cd66));
    Tweak2Lbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    Tweak2Lbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    Tweak2Lbl->setBounds (208, 240, 64, 24);

    DryLevelSld.reset (new WECore::JUCEPlugin::LabelReadoutSlider<float> ("Dry Level Slider"));
    addAndMakeVisible (DryLevelSld.get());
    DryLevelSld->setTooltip (TRANS("Adds the unprocessed signal into the output"));
    DryLevelSld->setRange (0, 1, 0.01);
    DryLevelSld->setSliderStyle (juce::Slider::LinearHorizontal);
    DryLevelSld->setTextBoxStyle (juce::Slider::NoTextBox, false, 80, 20);
    DryLevelSld->addListener (this);

    DryLevelSld->setBounds (112, 344, 232, 24);

    DryLevelLbl.reset (new juce::Label ("Dry Level Label",
                                        TRANS("Dry Level")));
    addAndMakeVisible (DryLevelLbl.get());
    DryLevelLbl->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    DryLevelLbl->setJustificationType (juce::Justification::centred);
    DryLevelLbl->setEditable (false, false, false);
    DryLevelLbl->setColour (juce::Label::textColourId, juce::Colour (0xffc6cd66));
    DryLevelLbl->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    DryLevelLbl->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    DryLevelLbl->setBounds (24, 344, 88, 24);

    StereoBtn.reset (new juce::TextButton ("Stereo Button"));
    addAndMakeVisible (StereoBtn.get());
    StereoBtn->setTooltip (TRANS("Allows unit 1 and unit 2 to process the left and right channels independently"));
    StereoBtn->setButtonText (TRANS("Stereo"));
    StereoBtn->addListener (this);
    StereoBtn->setColour (juce::TextButton::buttonColourId, juce::Colour (0xffb8b8c4));

    StereoBtn->setBounds (272, 312, 70, 24);

    Wave1View.reset (new CarveWaveViewer());
    addAndMakeVisible (Wave1View.get());
    Wave1View->setName ("Wave 1 Viewer");

    Wave1View->setBounds (48, 72, 104, 48);

    Wave2View.reset (new CarveWaveViewer());
    addAndMakeVisible (Wave2View.get());
    Wave2View->setName ("Wave 1 Viewer");

    Wave2View->setBounds (224, 72, 104, 48);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (375, 430);


    //[Constructor] You can add your own custom stuff here..
    // Set up look and feel
    _customLookAndFeel.setHighlightColour(_highlightColour);
    _assignLookAndFeelToAllChildren(_customLookAndFeel);

    // This is needed for the fonts to be applied
    CarveLookAndFeel::setDefaultLookAndFeel(&_customLookAndFeel);

    // Wave view colours
    _customLookAndFeel.setColour(CarveWaveViewer::ColourIds::highlightColourId,
                                 _highlightColour);

    // Combo box text colours
    const Colour lightYellow(0xffc6cd66);
    const Colour menuDark(0.0f, 0.0f, 0.17f, 1.0f);
    _customLookAndFeel.setColour(ComboBox::ColourIds::textColourId, lightYellow);
    _customLookAndFeel.setColour(PopupMenu::ColourIds::backgroundColourId,
                                 menuDark);
    _customLookAndFeel.setColour(PopupMenu::ColourIds::textColourId, lightYellow);
    _customLookAndFeel.setColour(PopupMenu::ColourIds::highlightedBackgroundColourId,
                                lightYellow);
    _customLookAndFeel.setColour(PopupMenu::ColourIds::highlightedTextColourId,
                                menuDark);

    Mode1Cmb->setScrollWheelEnabled(true);
    Mode1Cmb->setJustificationType(Justification::centred);
    Mode2Cmb->setScrollWheelEnabled(true);
    Mode2Cmb->setJustificationType(Justification::centred);

    // Disable stereo mode if only single output
    CarveAudioProcessor* ourProcessor {getProcessor()};
    StereoBtn->setEnabled(ourProcessor->getNumOutputChannels() == 2);

    _enableDoubleClickToDefault();

    _startSliderReadouts();

    // Call this manually once to make sure the UI reflects the parameters' states correctly
    _onParameterUpdate();
    //[/Constructor]
}

CarveAudioProcessorEditor::~CarveAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    _stopSliderReadouts();
    //[/Destructor_pre]

    RoutingGroup = nullptr;
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
    OutputGainSld = nullptr;
    OutputGainLbl = nullptr;
    PreGain2Lbl = nullptr;
    PostGain2Lbl = nullptr;
    Tweak2Lbl = nullptr;
    DryLevelSld = nullptr;
    DryLevelLbl = nullptr;
    StereoBtn = nullptr;
    Wave1View = nullptr;
    Wave2View = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    _removeLookAndFeelFromAllChildren();
    //[/Destructor]
}

//==============================================================================
void CarveAudioProcessorEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    Image bg = ImageCache::getFromMemory(BinaryData::background_jpeg, BinaryData::background_jpegSize);
    g.drawImage(bg, 0, 0, 375, 430, 0, 0, 5 * 375, 5 * 430);

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

void CarveAudioProcessorEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    CarveAudioProcessor* ourProcessor {getProcessor()};
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == PreGain1Sld.get())
    {
        //[UserSliderCode_PreGain1Sld] -- add your slider handling code here..
        ourProcessor->setPreGain1(PreGain1Sld->getValue());
        //[/UserSliderCode_PreGain1Sld]
    }
    else if (sliderThatWasMoved == PostGain1Sld.get())
    {
        //[UserSliderCode_PostGain1Sld] -- add your slider handling code here..
        ourProcessor->setPostGain1(PostGain1Sld->getValue());
        //[/UserSliderCode_PostGain1Sld]
    }
    else if (sliderThatWasMoved == Tweak1Sld.get())
    {
        //[UserSliderCode_Tweak1Sld] -- add your slider handling code here..
        ourProcessor->setTweak1(Tweak1Sld->getValue());
        //[/UserSliderCode_Tweak1Sld]
    }
    else if (sliderThatWasMoved == PreGain2Sld.get())
    {
        //[UserSliderCode_PreGain2Sld] -- add your slider handling code here..
        ourProcessor->setPreGain2(PreGain2Sld->getValue());
        //[/UserSliderCode_PreGain2Sld]
    }
    else if (sliderThatWasMoved == PostGain2Sld.get())
    {
        //[UserSliderCode_PostGain2Sld] -- add your slider handling code here..
        ourProcessor->setPostGain2(PostGain2Sld->getValue());
        //[/UserSliderCode_PostGain2Sld]
    }
    else if (sliderThatWasMoved == Tweak2Sld.get())
    {
        //[UserSliderCode_Tweak2Sld] -- add your slider handling code here..
        ourProcessor->setTweak2(Tweak2Sld->getValue());
        //[/UserSliderCode_Tweak2Sld]
    }
    else if (sliderThatWasMoved == RoutingSld.get())
    {
        //[UserSliderCode_RoutingSld] -- add your slider handling code here..
        ourProcessor->setRouting(RoutingSld->getValue());
        //[/UserSliderCode_RoutingSld]
    }
    else if (sliderThatWasMoved == OutputGainSld.get())
    {
        //[UserSliderCode_OutputGainSld] -- add your slider handling code here..
        ourProcessor->setOutputGain(OutputGainSld->getValue());
        //[/UserSliderCode_OutputGainSld]
    }
    else if (sliderThatWasMoved == DryLevelSld.get())
    {
        //[UserSliderCode_DryLevelSld] -- add your slider handling code here..
        ourProcessor->setDryLevel(DryLevelSld->getValue());
        //[/UserSliderCode_DryLevelSld]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void CarveAudioProcessorEditor::comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    CarveAudioProcessor* ourProcessor {getProcessor()};
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == Mode1Cmb.get())
    {
        //[UserComboBoxCode_Mode1Cmb] -- add your combo box handling code here..
        ourProcessor->setMode1(Mode1Cmb->getSelectedId());
        //[/UserComboBoxCode_Mode1Cmb]
    }
    else if (comboBoxThatHasChanged == Mode2Cmb.get())
    {
        //[UserComboBoxCode_Mode2Cmb] -- add your combo box handling code here..
        ourProcessor->setMode2(Mode2Cmb->getSelectedId());
        //[/UserComboBoxCode_Mode2Cmb]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void CarveAudioProcessorEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    CarveAudioProcessor* ourProcessor {getProcessor()};
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == StereoBtn.get())
    {
        //[UserButtonCode_StereoBtn] -- add your button handler code here..
        ourProcessor->setStereo(!StereoBtn->getToggleState());
        //[/UserButtonCode_StereoBtn]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void CarveAudioProcessorEditor::sliderDragStarted(Slider* slider) {
    CarveAudioProcessor* ourProcessor {getProcessor()};

    if (slider == PreGain1Sld.get()) {
        ourProcessor->preGain1->beginChangeGesture();
    } else if (slider == PostGain1Sld.get()) {
        ourProcessor->postGain1->beginChangeGesture();
    } else if (slider == Tweak1Sld.get()) {
        ourProcessor->tweak1->beginChangeGesture();
    } else if (slider == PreGain2Sld.get()) {
        ourProcessor->preGain2->beginChangeGesture();
    } else if (slider == PostGain2Sld.get()) {
        ourProcessor->postGain2->beginChangeGesture();
    } else if (slider == Tweak2Sld.get()) {
        ourProcessor->tweak2->beginChangeGesture();
    } else if (slider == RoutingSld.get()) {
        ourProcessor->routing->beginChangeGesture();
    } else if (slider == DryLevelSld.get()) {
        ourProcessor->dryLevel->beginChangeGesture();
    } else if (slider == OutputGainSld.get()) {
        ourProcessor->outputGain->beginChangeGesture();
    }
}

void CarveAudioProcessorEditor::sliderDragEnded(Slider* slider) {
    CarveAudioProcessor* ourProcessor {getProcessor()};

    if (slider == PreGain1Sld.get()) {
        ourProcessor->preGain1->endChangeGesture();
    } else if (slider == PostGain1Sld.get()) {
        ourProcessor->postGain1->endChangeGesture();
    } else if (slider == Tweak1Sld.get()) {
        ourProcessor->tweak1->endChangeGesture();
    } else if (slider == PreGain2Sld.get()) {
        ourProcessor->preGain2->endChangeGesture();
    } else if (slider == PostGain2Sld.get()) {
        ourProcessor->postGain2->endChangeGesture();
    } else if (slider == Tweak2Sld.get()) {
        ourProcessor->tweak2->endChangeGesture();
    } else if (slider == RoutingSld.get()) {
        ourProcessor->routing->endChangeGesture();
    } else if (slider == DryLevelSld.get()) {
        ourProcessor->dryLevel->endChangeGesture();
    } else if (slider == OutputGainSld.get()) {
        ourProcessor->outputGain->endChangeGesture();
    }
}

void CarveAudioProcessorEditor::_onParameterUpdate() {
    CarveAudioProcessor* ourProcessor {getProcessor()};

    // Change group titles if in stereo mode
    if (ourProcessor->stereo->get()) {
        Unit1Group->setText(GROUP_LEFT);
        Unit2Group->setText(GROUP_RIGHT);
    } else {
        Unit1Group->setText(GROUP_UNIT1);
        Unit2Group->setText(GROUP_UNIT2);
    }

    auto setControlsActive = [](int mode,
                                Slider& preGain,
                                Slider& postGain,
                                Slider& tweak) -> void {

        if (mode == WECore::Carve::Parameters::MODE.OFF) {
            preGain.setEnabled(false);
            postGain.setEnabled(false);
            tweak.setEnabled(false);
        } else if (mode == WECore::Carve::Parameters::MODE.EXPONENT) {
            preGain.setEnabled(true);
            postGain.setEnabled(true);
            tweak.setEnabled(false);
        } else {
            preGain.setEnabled(true);
            postGain.setEnabled(true);
            tweak.setEnabled(true);
        }
    };

    setControlsActive(ourProcessor->mode1->get(), *PreGain1Sld, *PostGain1Sld, *Tweak1Sld);
    setControlsActive(ourProcessor->mode2->get(), *PreGain2Sld, *PostGain2Sld, *Tweak2Sld);

    Wave1View->setMode(ourProcessor->mode1->get());
    Wave1View->setPreGain(ourProcessor->preGain1->get());
    Wave1View->setPostGain(ourProcessor->postGain1->get());
    Wave1View->setTweak(ourProcessor->tweak1->get());
    Wave1View->repaint();

    Wave2View->setMode(ourProcessor->mode2->get());
    Wave2View->setPreGain(ourProcessor->preGain2->get());
    Wave2View->setPostGain(ourProcessor->postGain2->get());
    Wave2View->setTweak(ourProcessor->tweak2->get());
    Wave2View->repaint();

    Mode1Cmb->setSelectedId(ourProcessor->mode1->get(), dontSendNotification);
    PreGain1Sld->setValue(ourProcessor->preGain1->get(), dontSendNotification);
    PostGain1Sld->setValue(ourProcessor->postGain1->get(), dontSendNotification);
    Tweak1Sld->setValue(ourProcessor->tweak1->get(), dontSendNotification);

    Mode2Cmb->setSelectedId(ourProcessor->mode2->get(), dontSendNotification);
    PreGain2Sld->setValue(ourProcessor->preGain2->get(), dontSendNotification);
    PostGain2Sld->setValue(ourProcessor->postGain2->get(), dontSendNotification);
    Tweak2Sld->setValue(ourProcessor->tweak2->get(), dontSendNotification);

    RoutingSld->setValue(ourProcessor->routing->get(), dontSendNotification);
    RoutingSld->setEnabled(!ourProcessor->stereo->get());   // disable routing if in stereo mode
    StereoBtn->setToggleState(ourProcessor->stereo->get(), dontSendNotification);
    DryLevelSld->setValue(ourProcessor->dryLevel->get(), dontSendNotification);
    OutputGainSld->setValue(ourProcessor->outputGain->get(), dontSendNotification);
}

void CarveAudioProcessorEditor::_drawDividers(Graphics &g) const {

    auto drawDivider = [&g](Line<float> line, const Colour& lineColour) -> void {
        // Set the gradient
        const float lineXLength {std::abs(line.getStartX() - line.getEndX())};
        const float lineYLength {std::abs(line.getStartY() - line.getEndY())};


        g.setGradientFill(ColourGradient(lineColour,
                                         line.getStartX() + lineXLength / 2,
                                         line.getStartY() + lineYLength /2,
                                         lineColour.withAlpha(0.1f),
                                         line.getStartX(),
                                         line.getStartY(),
                                         true));

        // Calculate and draw the dashes
        constexpr float dashLength {4};
        const int numDashes {static_cast<int>(line.getLength() / (dashLength * 2))};

        const std::vector<float> dashLengths(numDashes * 2, dashLength);

        g.drawDashedLine(line, &dashLengths[0], 4);
    };

    // Vertical divider
    constexpr float VERT_X {187};
    constexpr float VERT_Y {51};
    constexpr float VERT_LEN {220};
    drawDivider(Line<float>(VERT_X, VERT_Y, VERT_X, VERT_Y + VERT_LEN),
                _highlightColour);

    // Horizontal divider
    constexpr float HOR_X {52};
    constexpr float HOR_Y {280};
    constexpr float HOR_LEN {270};
    drawDivider(Line<float>(HOR_X, HOR_Y, HOR_X + HOR_LEN, HOR_Y),
                _highlightColour);
}

void CarveAudioProcessorEditor::_enableDoubleClickToDefault() {
    PreGain1Sld->setDoubleClickReturnValue(true,
                                           WECore::Carve::Parameters::PREGAIN.InternalToNormalised(WECore::Carve::Parameters::PREGAIN.defaultValue));
    PostGain1Sld->setDoubleClickReturnValue(true,
                                            WECore::Carve::Parameters::POSTGAIN.InternalToNormalised(WECore::Carve::Parameters::POSTGAIN.defaultValue));
    Tweak1Sld->setDoubleClickReturnValue(true,
                                         WECore::Carve::Parameters::TWEAK.InternalToNormalised(WECore::Carve::Parameters::TWEAK.defaultValue));

    PreGain2Sld->setDoubleClickReturnValue(true,
                                           WECore::Carve::Parameters::PREGAIN.InternalToNormalised(WECore::Carve::Parameters::PREGAIN.defaultValue));
    PostGain2Sld->setDoubleClickReturnValue(true,
                                            WECore::Carve::Parameters::POSTGAIN.InternalToNormalised(WECore::Carve::Parameters::POSTGAIN.defaultValue));
    Tweak2Sld->setDoubleClickReturnValue(true,
                                         WECore::Carve::Parameters::TWEAK.InternalToNormalised(WECore::Carve::Parameters::TWEAK.defaultValue));

    RoutingSld->setDoubleClickReturnValue(true, ROUTING.InternalToNormalised(ROUTING.defaultValue));
    DryLevelSld->setDoubleClickReturnValue(true, DRYLEVEL.InternalToNormalised(DRYLEVEL.defaultValue));
    OutputGainSld->setDoubleClickReturnValue(true, OUTPUTGAIN.InternalToNormalised(OUTPUTGAIN.defaultValue));
}

void CarveAudioProcessorEditor::_startSliderReadouts() {
    PreGain1Sld->start(PreGain1Lbl.get(), PreGain1Lbl->getText(), &WECore::Carve::Parameters::PREGAIN);
    PostGain1Sld->start(PostGain1Lbl.get(), PostGain1Lbl->getText(), &WECore::Carve::Parameters::POSTGAIN);
    Tweak1Sld->start(Tweak1Lbl.get(), Tweak1Lbl->getText(), &WECore::Carve::Parameters::TWEAK);

    PreGain2Sld->start(PreGain2Lbl.get(), PreGain2Lbl->getText(), &WECore::Carve::Parameters::PREGAIN);
    PostGain2Sld->start(PostGain2Lbl.get(), PostGain2Lbl->getText(), &WECore::Carve::Parameters::POSTGAIN);
    Tweak2Sld->start(Tweak2Lbl.get(), Tweak2Lbl->getText(), &WECore::Carve::Parameters::TWEAK);

    RoutingSld->start(std::make_pair(SerialLbl.get(), SerialLbl->getText()),
                      std::make_pair(ParallelLbl.get(), ParallelLbl->getText()),
                      &ROUTING);
    OutputGainSld->start(OutputGainLbl.get(), OutputGainLbl->getText(), &OUTPUTGAIN);
    DryLevelSld->start(DryLevelLbl.get(), DryLevelLbl->getText(), &DRYLEVEL);

}

void CarveAudioProcessorEditor::_stopSliderReadouts() {
    PreGain1Sld->stop();
    PostGain1Sld->stop();
    Tweak1Sld->stop();

    PreGain2Sld->stop();
    PostGain2Sld->stop();
    Tweak2Sld->stop();

    RoutingSld->stop();
    OutputGainSld->stop();
    DryLevelSld->stop();
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
                 constructorParams="CarveAudioProcessor&amp; ownerFilter" variableInitialisers="CoreProcessorEditor(ownerFilter), _highlightColour(0.15f, 1.0f, 1.0f, 1.0f)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="375" initialHeight="430">
  <BACKGROUND backgroundColour="ff323e44"/>
  <GROUPCOMPONENT name="Routing Group" id="a0ae877bd426411a" memberName="RoutingGroup"
                  virtualName="" explicitFocusOrder="0" pos="16 288 344 120" title="ROUTING"
                  textpos="36"/>
  <GROUPCOMPONENT name="Unit 1 Group" id="540af1b8b630cc1f" memberName="Unit1Group"
                  virtualName="" explicitFocusOrder="0" pos="16 48 168 232" title="UNIT 1"
                  textpos="36"/>
  <GROUPCOMPONENT name="Unit 2 Group" id="ab152c6e7348165e" memberName="Unit2Group"
                  virtualName="" explicitFocusOrder="0" pos="192 48 168 232" title="UNIT 2"
                  textpos="36"/>
  <SLIDER name="PreGain 1 Slider" id="f32c9f6afaac55bd" memberName="PreGain1Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="128 176 32 24" tooltip="Gain applied to the signal before processing"
          min="0.0" max="1.0" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="PostGain 1 Slider" id="6c5a77936be07efe" memberName="PostGain1Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="128 208 32 24" tooltip="Gain applied to the signal after processing"
          min="0.0" max="1.0" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Tweak 1 Slider" id="94990f0dcf6af35d" memberName="Tweak1Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="128 240 32 24" tooltip="Morphs the wave shape applied to the signal"
          min="0.0" max="1.0" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <COMBOBOX name="Mode 1 Combo Box" id="823a631a257df62e" memberName="Mode1Cmb"
            virtualName="" explicitFocusOrder="0" pos="24 136 150 24" tooltip="Wave shape applied to the signal"
            editable="0" layout="33" items="Off&#10;Sine&#10;Parabolic Soft&#10;Parabolic Hard&#10;Asymmetric Sine&#10;Exponent&#10;Clipper"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="PreGain 2 Slider" id="11f2eb8d84599245" memberName="PreGain2Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="304 176 32 24" tooltip="Gain applied to the signal before processing"
          min="0.0" max="1.0" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="PostGain 2 Slider" id="aa9e67169e105a0" memberName="PostGain2Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="304 208 32 24" tooltip="Gain applied to the signal after processing"
          min="0.0" max="1.0" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="Tweak 2 Slider" id="63c918fd331adc1c" memberName="Tweak2Sld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;double&gt;"
          explicitFocusOrder="0" pos="304 240 32 24" tooltip="Morphs the wave shape applied to the signal"
          min="0.0" max="1.0" int="0.01" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <COMBOBOX name="Mode 2 Combo Box" id="13e9b245e523351d" memberName="Mode2Cmb"
            virtualName="" explicitFocusOrder="0" pos="200 136 150 24" tooltip="Wave shape applied to the signal"
            editable="0" layout="33" items="Off&#10;Sine&#10;Parabolic Soft&#10;Parabolic Hard&#10;Asymmetric Sine&#10;Exponent&#10;Clipper"
            textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <SLIDER name="Routing Slider" id="f14b87e6d580ecee" memberName="RoutingSld"
          virtualName="CarveDualLabelReadoutSlider" explicitFocusOrder="0"
          pos="112 312 88 24" tooltip="Routing of the signal between the two distortion units"
          min="0.0" max="1.0" int="0.01" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="PreGain 1 Label" id="23c42a895f3ddaf2" memberName="PreGain1Lbl"
         virtualName="" explicitFocusOrder="0" pos="32 176 88 24" textCol="ffc6cd66"
         outlineCol="d83535" edTextCol="ff000000" edBkgCol="0" labelText="Pre Gain"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="0" justification="33"/>
  <LABEL name="PostGain 1 Label" id="d4ad48771666454" memberName="PostGain1Lbl"
         virtualName="" explicitFocusOrder="0" pos="32 208 88 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Post Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="Tweak 1 Label" id="33e8e0f78b54327f" memberName="Tweak1Lbl"
         virtualName="" explicitFocusOrder="0" pos="32 240 64 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Tweak" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="Serial Label" id="c969ac5b46238aca" memberName="SerialLbl"
         virtualName="" explicitFocusOrder="0" pos="24 312 88 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Serial" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="Parallel Label" id="a189167740b46f3f" memberName="ParallelLbl"
         virtualName="" explicitFocusOrder="0" pos="200 312 64 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Parallel" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="Output Gain Slider" id="98dbad60d21a006b" memberName="OutputGainSld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;float&gt;"
          explicitFocusOrder="0" pos="112 375 232 24" tooltip="Output gain"
          min="0.0" max="1.0" int="0.01" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="Output Gain Label" id="7ced186274c6d879" memberName="OutputGainLbl"
         virtualName="" explicitFocusOrder="0" pos="24 375 88 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Output Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="PreGain 2 Label" id="1b1fcd244dbb837c" memberName="PreGain2Lbl"
         virtualName="" explicitFocusOrder="0" pos="208 176 88 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Pre Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="PostGain 2 Label" id="10dbd505cd27ccc1" memberName="PostGain2Lbl"
         virtualName="" explicitFocusOrder="0" pos="208 208 88 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Post Gain" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="Tweak 2 Label" id="1ff0730a1fb3a90b" memberName="Tweak2Lbl"
         virtualName="" explicitFocusOrder="0" pos="208 240 64 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Tweak" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="33"/>
  <SLIDER name="Dry Level Slider" id="7d8198da2503bb12" memberName="DryLevelSld"
          virtualName="WECore::JUCEPlugin::LabelReadoutSlider&lt;float&gt;"
          explicitFocusOrder="0" pos="112 344 232 24" tooltip="Adds the unprocessed signal into the output"
          min="0.0" max="1.0" int="0.01" style="LinearHorizontal" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <LABEL name="Dry Level Label" id="877aa0a163a23de7" memberName="DryLevelLbl"
         virtualName="" explicitFocusOrder="0" pos="24 344 88 24" textCol="ffc6cd66"
         edTextCol="ff000000" edBkgCol="0" labelText="Dry Level" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <TEXTBUTTON name="Stereo Button" id="e450c34398554a3f" memberName="StereoBtn"
              virtualName="" explicitFocusOrder="0" pos="272 312 70 24" tooltip="Allows unit 1 and unit 2 to process the left and right channels independently"
              bgColOff="ffb8b8c4" buttonText="Stereo" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <GENERICCOMPONENT name="Wave 1 Viewer" id="bc75cac19f439bbe" memberName="Wave1View"
                    virtualName="" explicitFocusOrder="0" pos="48 72 104 48" class="CarveWaveViewer"
                    params=""/>
  <GENERICCOMPONENT name="Wave 1 Viewer" id="464c704dad75c271" memberName="Wave2View"
                    virtualName="" explicitFocusOrder="0" pos="224 72 104 48" class="CarveWaveViewer"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

