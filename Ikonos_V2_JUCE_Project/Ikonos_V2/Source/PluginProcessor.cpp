#include "PluginProcessor.h"
#include "PluginEditor.h"

IkonosV2AudioProcessor::IkonosV2AudioProcessor()
    : AudioProcessor(BusesProperties().withInput("Input",juce::AudioChannelSet::stereo()).withOutput("Output",juce::AudioChannelSet::stereo())),
      apvts(*this,nullptr,"Parameters",createParameterLayout())
{}

IkonosV2AudioProcessor::~IkonosV2AudioProcessor(){}

juce::AudioProcessorValueTreeState::ParameterLayout IkonosV2AudioProcessor::createParameterLayout()
{
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    layout.add(std::make_unique<juce::AudioParameterFloat>("REVERB_SIZE_WR0M","Reverb Size",juce::NormalisableRange<float>(0f,100f,0.01f),49f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("REVERB_DAMP_WR0M","Reverb Damping",juce::NormalisableRange<float>(0f,100f,0.01f),31f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("REVERB_MIX_WR0M","Reverb Mix",juce::NormalisableRange<float>(0f,100f,0.01f),40f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("DISTORTION_DRIVE_YFA3","Distortion Drive",juce::NormalisableRange<float>(0f,100f,0.01f),39f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("DISTORTION_MIX_YFA3","Distortion Mix",juce::NormalisableRange<float>(0f,100f,0.01f),33f));
    return layout;
}

void IkonosV2AudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    juce::dsp::ProcessSpec spec;
    spec.sampleRate=(uint32_t)sampleRate;
    spec.maximumBlockSize=(uint32_t)samplesPerBlock;
    spec.numChannels=(uint32_t)getTotalNumOutputChannels();
    { juce::dsp::Reverb::Parameters rp; rp.roomSize=0.49f; rp.damping=0.31f; rp.wetLevel=0.4f; rp.dryLevel=0.6f; reverb_WR0M.setParameters(rp); reverb_WR0M.prepare(spec); }
    dist_YFA3.functionToUse=[](float x){return std::tanh(x*4.9f);};
    dist_YFA3.prepare(spec);
    distMix_YFA3.prepare(spec);
    distMix_YFA3.setWetMixProportion(0.33f);
}

void IkonosV2AudioProcessor::releaseResources(){}

bool IkonosV2AudioProcessor::isBusesLayoutSupported(const BusesLayout& l) const
{
    return l.getMainOutputChannelSet()==juce::AudioChannelSet::stereo()
        && l.getMainInputChannelSet()==juce::AudioChannelSet::stereo();
}

void IkonosV2AudioProcessor::processBlock(juce::AudioBuffer<float>& buffer,juce::MidiBuffer&)
{
    juce::ScopedNoDenormals noDenormals;
    juce::dsp::AudioBlock<float> block(buffer);
    juce::dsp::ProcessContextReplacing<float> context(block);
    reverb_WR0M.process(context);
    { distMix_YFA3.pushDrySamples(block); dist_YFA3.process(context); distMix_YFA3.mixWetSamples(block); }
}

void IkonosV2AudioProcessor::getStateInformation(juce::MemoryBlock& d)
{
    auto s=apvts.copyState();
    std::unique_ptr<juce::XmlElement> xml(s.createXml());
    copyXmlToBinary(*xml,d);
}

void IkonosV2AudioProcessor::setStateInformation(const void* d,int sz)
{
    std::unique_ptr<juce::XmlElement> xml(getXmlFromBinary(d,sz));
    if(xml&&xml->hasTagName(apvts.state.getType())) apvts.replaceState(juce::ValueTree::fromXml(*xml));
}

juce::AudioProcessorEditor* IkonosV2AudioProcessor::createEditor()
{
    return new IkonosV2AudioProcessorEditor(*this);
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new IkonosV2AudioProcessor();
}
