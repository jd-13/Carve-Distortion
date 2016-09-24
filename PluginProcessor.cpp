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
    mCarve.DSPUnit1.setMode(MODE.defaultValue);
    mCarve.DSPUnit1.setPreGain(PREGAIN.defaultValue);
    mCarve.DSPUnit1.setPostGain(POSTGAIN.defaultValue);
    mCarve.DSPUnit1.setTweak(TWEAK.defaultValue);
    
    mCarve.DSPUnit2.setMode(MODE.defaultValue);
    mCarve.DSPUnit2.setPreGain(PREGAIN.defaultValue);
    mCarve.DSPUnit2.setPostGain(POSTGAIN.defaultValue);
    mCarve.DSPUnit2.setTweak(TWEAK.defaultValue);
    
    mCarve.setRouting(ROUTING.defaultValue);
    mCarve.setStereo(STEREO_DEFAULT);
    mCarve.setDryLevel(DRYLEVEL.defaultValue);
    mCarve.setMasterVol(MASTERVOL.defaultValue);
    
    UIUpdateFlag = true;
}

CarveAudioProcessor::~CarveAudioProcessor()
{
}

//==============================================================================
const String CarveAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int CarveAudioProcessor::getNumParameters()
{
    return totalNumParams;
}

float CarveAudioProcessor::getParameter (int index)
{
    switch (index) {
        case mode1:
            return mCarve.DSPUnit1.getMode();
            
        case preGain1:
            return PREGAIN.InteralToNormalised(mCarve.DSPUnit1.getPreGain());
        
        case postGain1:
            return POSTGAIN.InteralToNormalised(mCarve.DSPUnit1.getPostGain());
            
        case tweak1:
            return POSTGAIN.InteralToNormalised(mCarve.DSPUnit1.getTweak());
            
        
            
            
        case mode2:
            return mCarve.DSPUnit2.getMode();
            
        case preGain2:
            return PREGAIN.InteralToNormalised(mCarve.DSPUnit2.getPreGain());
            
        case postGain2:
            return POSTGAIN.InteralToNormalised(mCarve.DSPUnit2.getPostGain());
            
        case tweak2:
            return TWEAK.InteralToNormalised(mCarve.DSPUnit2.getTweak());
            
            
            
            
        case routing:
            return ROUTING.InteralToNormalised(mCarve.getRouting());
            
        case stereo:
            return mCarve.getStereo();
            
        case dryLevel:
            return DRYLEVEL.InteralToNormalised(mCarve.getDryLevel());
            
        case masterVol:
            return MASTERVOL.InteralToNormalised(mCarve.getMasterVol());
            
            
            
        default:
            return 0.0f;
    }
}

void CarveAudioProcessor::setParameter (int index, float newValue)
{
    switch (index) {
        case mode1:
            mCarve.DSPUnit1.setMode(static_cast<int>(round(newValue)));
            break;
            
        case preGain1:
            mCarve.DSPUnit1.setPreGain(PREGAIN.NormalisedToInteral(newValue));
            break;
            
        case postGain1:
            mCarve.DSPUnit1.setPostGain(POSTGAIN.NormalisedToInteral(newValue));
            break;
            
        case tweak1:
            mCarve.DSPUnit1.setTweak(TWEAK.NormalisedToInteral(newValue));
            break;
            
            
            
            
        case mode2:
            mCarve.DSPUnit2.setMode(static_cast<int>(round(newValue)));
            break;
            
        case preGain2:
            mCarve.DSPUnit2.setPreGain(PREGAIN.NormalisedToInteral(newValue));
            break;
            
        case postGain2:
            mCarve.DSPUnit2.setPostGain(POSTGAIN.NormalisedToInteral(newValue));
            break;
            
        case tweak2:
            mCarve.DSPUnit2.setTweak(TWEAK.NormalisedToInteral(newValue));
            break;
            
            
            
            
        case routing:
            mCarve.setRouting(ROUTING.NormalisedToInteral(newValue));
            break;
            
        case stereo:
            mCarve.setStereo(newValue < 0.5);
            break;
            
        case dryLevel:
            mCarve.setDryLevel(DRYLEVEL.NormalisedToInteral(newValue));
            break;
            
        case masterVol:
            mCarve.setMasterVol(MASTERVOL.NormalisedToInteral(newValue));
            break;
            
            
            
            
        default:
            break;
    }
    
    UIUpdateFlag = true;
}

const String CarveAudioProcessor::getParameterName (int index)
{
    switch (index) {
        case mode1:
            return MODE1_STR;
            
        case preGain1:
            return PREGAIN1_STR;
            
        case postGain1:
            return POSTGAIN1_STR;
            
        case tweak1:
            return TWEAK1_STR;
            
            
            
            
        case mode2:
            return MODE2_STR;
            
        case preGain2:
            return PREGAIN2_STR;
            
        case postGain2:
            return POSTGAIN2_STR;
            
        case tweak2:
            return TWEAK2_STR;
            
            
            
            
        case routing:
            return ROUTING_STR;
            
        case stereo:
            return STEREO_STR;
            
        case dryLevel:
            return DRYLEVEL_STR;
            
        case masterVol:
            return MASTERVOL_STR;
            
            
            
            
        default:
            return String::empty;
    }
}

const String CarveAudioProcessor::getParameterText (int index)
{
    switch (index) {
        case mode1:
            return String(mCarve.DSPUnit1.getMode());
            
        case preGain1:
            return String(PREGAIN.InteralToNormalised(mCarve.DSPUnit1.getPreGain()));
            
        case postGain1:
            return String(POSTGAIN.InteralToNormalised(mCarve.DSPUnit1.getPostGain()));
            
        case tweak1:
            return String(TWEAK.InteralToNormalised(mCarve.DSPUnit1.getTweak()));
            
            
            
            
        case mode2:
            return String(mCarve.DSPUnit2.getMode());
            
        case preGain2:
            return String(PREGAIN.InteralToNormalised(mCarve.DSPUnit2.getPreGain()));
            
        case postGain2:
            return String(POSTGAIN.InteralToNormalised(mCarve.DSPUnit2.getPostGain()));
            
        case tweak2:
            return String(TWEAK.InteralToNormalised(mCarve.DSPUnit2.getTweak()));
            
        
            
            
        case routing:
            return String(ROUTING.InteralToNormalised(mCarve.getRouting()));
            
        case stereo:
            return String(mCarve.getStereo());
            
        case dryLevel:
            return String(DRYLEVEL.InteralToNormalised(mCarve.getDryLevel()));
            
        case masterVol:
            return String(MASTERVOL.InteralToNormalised(mCarve.getMasterVol()));
            
            
            
            
        default:
            return String::empty;
    }
}

bool CarveAudioProcessor::isParameterAutomatable(int parameterIndex) const {
    switch (parameterIndex) {
        case mode1:
            return false;
            
        case mode2:
            return false;
            
        default:
            return true;
    }
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
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i) {
        buffer.clear (i, 0, buffer.getNumSamples());
    }

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    if (getNumOutputChannels() == 1 && getNumOutputChannels() == 1) {
        
        float* inSample {buffer.getWritePointer(0)};
        mCarve.Process1in1out(inSample, buffer.getNumSamples());
        
    } else if (getNumInputChannels() == 1 && getNumOutputChannels() == 2) {
        
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
void CarveAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    std::vector<float> userParams;
    for (int iii {0}; iii < totalNumParams; iii++) {
        userParams.push_back(getParameter(iii));
    }
    
    XmlElement root("Root");
    XmlElement *el = root.createNewChildElement("AllUserParam");
    
    el->addTextElement(String(floatVectorToString(userParams)));
    copyXmlToBinary(root, destData);
}

void CarveAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    std::unique_ptr<XmlElement> pRoot(getXmlFromBinary(data, sizeInBytes));
    std::vector<float> tmpUserParam;
    
    if (pRoot != NULL) {
        forEachXmlChildElement((*pRoot), pChild) {
            if (pChild->hasTagName("AllUserParam")) {
                String sFloatCSV = pChild->getAllSubText();
                if (stringToFloatVector(sFloatCSV, tmpUserParam, totalNumParams) == totalNumParams) {
                    for (int iii {0}; iii < totalNumParams; iii++) {
                        setParameter(iii, tmpUserParam[iii]);
                    }
                }
            }
        }
        
        // Slightly hacky fix to prevent inverted button settings on startup
        setParameter(stereo, getParameter(stereo));
        
        UIUpdateFlag = true;
    }

}

String CarveAudioProcessor::floatVectorToString(const std::vector<float>& fData) const {
    String result {""};
    
    if (fData.size() < 1) {
        return result;
    }
    
    for (int iii {0}; iii < (fData.size() - 1); iii++) {
        result << String(fData[iii])<<",";
    }
    
    result << String(fData[fData.size() - 1]);
    
    return result;
}

int CarveAudioProcessor::stringToFloatVector(const String sFloatCSV, std::vector<float>& fData, int maxNumFloat) const {
    StringArray tokenizer;
    int tokenCount {tokenizer.addTokens(sFloatCSV, ",","")};
    int resultCount {(maxNumFloat <= tokenCount) ? maxNumFloat : tokenCount};
    
    for (int iii {0}; iii < resultCount; iii++) {
        fData.push_back(tokenizer[iii].getFloatValue());
    }
    
    return ((tokenCount <= maxNumFloat) ? resultCount : -1);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new CarveAudioProcessor();
}
