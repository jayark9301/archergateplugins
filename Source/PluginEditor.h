#pragma once
#include "PluginProcessor.h"
#include "CustomLookAndFeel.h"

class IkonosV2AudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    IkonosV2AudioProcessorEditor(IkonosV2AudioProcessor&);
    ~IkonosV2AudioProcessorEditor() override;
    void paint(juce::Graphics&) override;
    void resized() override;
private:
    IkonosV2AudioProcessor& processorRef;
    IkonosV2LookAndFeel lnf;
    juce::Slider knob_REVERB_SIZE_WR0M;
    juce::Label  lbl_REVERB_SIZE_WR0M;
    juce::AudioProcessorValueTreeState::SliderAttachment att_REVERB_SIZE_WR0M;
    juce::Slider knob_REVERB_DAMP_WR0M;
    juce::Label  lbl_REVERB_DAMP_WR0M;
    juce::AudioProcessorValueTreeState::SliderAttachment att_REVERB_DAMP_WR0M;
    juce::Slider knob_REVERB_MIX_WR0M;
    juce::Label  lbl_REVERB_MIX_WR0M;
    juce::AudioProcessorValueTreeState::SliderAttachment att_REVERB_MIX_WR0M;
    juce::Slider knob_DISTORTION_DRIVE_YFA3;
    juce::Label  lbl_DISTORTION_DRIVE_YFA3;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DISTORTION_DRIVE_YFA3;
    juce::Slider knob_DISTORTION_MIX_YFA3;
    juce::Label  lbl_DISTORTION_MIX_YFA3;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DISTORTION_MIX_YFA3;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IkonosV2AudioProcessorEditor)
};
