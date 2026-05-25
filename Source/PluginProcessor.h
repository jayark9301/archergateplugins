#pragma once
#include <JuceHeader.h>

class IkonosV2AudioProcessor : public juce::AudioProcessor
{
public:
    IkonosV2AudioProcessor();
    ~IkonosV2AudioProcessor() override;

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    bool isBusesLayoutSupported(const BusesLayout&) const override;
    void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override { return true; }
    const juce::String getName() const override { return "Ikonos V2"; }
    bool acceptsMidi()    const override { return false; }
    bool producesMidi()   const override { return false; }
    double getTailLengthSeconds() const override { return 2.0; }
    int  getNumPrograms()    override { return 1; }
    int  getCurrentProgram() override { return 0; }
    void setCurrentProgram(int) override {}
    const juce::String getProgramName(int) override { return {}; }
    void changeProgramName(int, const juce::String&) override {}
    void getStateInformation(juce::MemoryBlock&) override;
    void setStateInformation(const void*, int) override;

    juce::AudioProcessorValueTreeState apvts;

private:
    static juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout();

    juce::dsp::Reverb reverb_WR0M;
    juce::dsp::DryWetMixer<float> reverbMix_WR0M;
    juce::dsp::WaveShaper<float> dist_YFA3;
    juce::dsp::DryWetMixer<float> distMix_YFA3;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IkonosV2AudioProcessor)
};
