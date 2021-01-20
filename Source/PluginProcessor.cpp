/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <string>


//==============================================================================
CarveAudioProcessor::CarveAudioProcessor()
{
    namespace CP = WECore::Carve::Parameters;

    constexpr float PRECISION {0.01f};

    registerParameter(mode1, MODE1_STR, &CP::MODE, CP::MODE.defaultValue, [&](int val) { setMode1(val); });
    registerParameter(preGain1, PREGAIN1_STR, &CP::PREGAIN, CP::PREGAIN.defaultValue, PRECISION, [&](float val) { setPreGain1(val); });
    registerParameter(postGain1, POSTGAIN1_STR, &CP::POSTGAIN, CP::POSTGAIN.defaultValue, PRECISION, [&](float val) { setPostGain1(val); });
    registerParameter(tweak1, TWEAK1_STR, &CP::TWEAK, CP::TWEAK.defaultValue, PRECISION, [&](float val) { setTweak1(val); });

    registerParameter(mode2, MODE2_STR, &CP::MODE, CP::MODE.defaultValue, [&](int val) { setMode2(val); });
    registerParameter(preGain2, PREGAIN2_STR, &CP::PREGAIN, CP::PREGAIN.defaultValue, PRECISION, [&](float val) { setPreGain2(val); });
    registerParameter(postGain2, POSTGAIN2_STR, &CP::POSTGAIN, CP::POSTGAIN.defaultValue, PRECISION, [&](float val) { setPostGain2(val); });
    registerParameter(tweak2, TWEAK2_STR, &CP::TWEAK, CP::TWEAK.defaultValue, PRECISION, [&](float val) { setTweak2(val); });

    registerParameter(routing, ROUTING_STR, &ROUTING, ROUTING.defaultValue, PRECISION, [&](float val) { setRouting(val); });
    registerParameter(stereo, STEREO_STR, STEREO_DEFAULT, [&](bool val) { setStereo(val); });
    registerParameter(dryLevel, DRYLEVEL_STR, &DRYLEVEL, DRYLEVEL.defaultValue, PRECISION, [&](float val) { setDryLevel(val); });
    registerParameter(outputGain, OUTPUTGAIN_STR, &OUTPUTGAIN, OUTPUTGAIN.defaultValue, PRECISION, [&](float val) { setOutputGain(val); });
}

CarveAudioProcessor::~CarveAudioProcessor()
{
}

//==============================================================================
const String CarveAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

const String CarveAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String CarveAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool CarveAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool CarveAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool CarveAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool CarveAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool CarveAudioProcessor::silenceInProducesSilenceOut() const
{
    return true;
}

double CarveAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int CarveAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int CarveAudioProcessor::getCurrentProgram()
{
    return 0;
}

void CarveAudioProcessor::setCurrentProgram (int index)
{
}

const String CarveAudioProcessor::getProgramName (int index)
{
    return String();
}

void CarveAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void CarveAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    mCarve.reset();
    mCarve.setSampleRate(sampleRate);
}

void CarveAudioProcessor::releaseResources()
{
    mCarve.reset();
}

void CarveAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i) {
        buffer.clear (i, 0, buffer.getNumSamples());
    }

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    if (totalNumOutputChannels == 1 && totalNumOutputChannels == 1) {

        float* inSample {buffer.getWritePointer(0)};
        mCarve.Process1in1out(inSample, buffer.getNumSamples());

    } else if (totalNumInputChannels == 1 && totalNumOutputChannels == 2) {

        float* inLeftSample {buffer.getWritePointer(0)};
        float* inRightSample {buffer.getWritePointer(1)};

        mCarve.Process1in2out(inLeftSample, inRightSample, buffer.getNumSamples());

    } else {

        float* inLeftSample {buffer.getWritePointer(0)};
        float* inRightSample {buffer.getWritePointer(1)};

        mCarve.Process2in2out(inLeftSample, inRightSample, buffer.getNumSamples());
    }
}

//==============================================================================
bool CarveAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* CarveAudioProcessor::createEditor()
{
    return new CarveAudioProcessorEditor (*this);
}

//==============================================================================
void CarveAudioProcessor::setMode1(int val) {
    mCarve.DSPUnit1.setMode(val);
    mode1->setValueNotifyingHost(mode1->getNormalisableRange().convertTo0to1(val));
}

void CarveAudioProcessor::setPreGain1(float val) {
    mCarve.DSPUnit1.setPreGain(WECore::Carve::Parameters::PREGAIN.NormalisedToInternal(val));
    preGain1->setValueNotifyingHost(val);
}

void CarveAudioProcessor::setPostGain1(float val) {
    mCarve.DSPUnit1.setPostGain(WECore::Carve::Parameters::POSTGAIN.NormalisedToInternal(val));
    postGain1->setValueNotifyingHost(val);
}

void CarveAudioProcessor::setTweak1(float val) {
    mCarve.DSPUnit1.setTweak(WECore::Carve::Parameters::TWEAK.NormalisedToInternal(val));
    tweak1->setValueNotifyingHost(val);
}

void CarveAudioProcessor::setMode2(int val) {
    mCarve.DSPUnit2.setMode(val);
    mode2->setValueNotifyingHost(mode2->getNormalisableRange().convertTo0to1(val));
}

void CarveAudioProcessor::setPreGain2(float val) {
    mCarve.DSPUnit2.setPreGain(WECore::Carve::Parameters::PREGAIN.NormalisedToInternal(val));
    preGain2->setValueNotifyingHost(val);
}

void CarveAudioProcessor::setPostGain2(float val) {
    mCarve.DSPUnit2.setPostGain(WECore::Carve::Parameters::POSTGAIN.NormalisedToInternal(val));
    postGain2->setValueNotifyingHost(val);
}

void CarveAudioProcessor::setTweak2(float val) {
    mCarve.DSPUnit2.setTweak(WECore::Carve::Parameters::TWEAK.NormalisedToInternal(val));
    tweak2->setValueNotifyingHost(val);
}

void CarveAudioProcessor::setRouting(float val) {
    mCarve.setRouting(ROUTING.NormalisedToInternal(val));
    routing->setValueNotifyingHost(val);
}

void CarveAudioProcessor::setStereo(bool val) {
    if (getNumOutputChannels() == 1) {
        mCarve.setStereo(false);
        stereo->setValueNotifyingHost(false);
    } else {
        mCarve.setStereo(val);
        stereo->setValueNotifyingHost(val);
    }
}

void CarveAudioProcessor::setDryLevel(float val) {
    mCarve.setDryLevel(DRYLEVEL.NormalisedToInternal(val));
    dryLevel->setValueNotifyingHost(val);
}

void CarveAudioProcessor::setOutputGain(float val) {
    mCarve.setOutputGain(OUTPUTGAIN.NormalisedToInternal(val));
    outputGain->setValueNotifyingHost(val);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CarveAudioProcessor();
}
