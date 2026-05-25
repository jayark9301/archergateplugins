#include "PluginEditor.h"

IkonosV2AudioProcessorEditor::IkonosV2AudioProcessorEditor(IkonosV2AudioProcessor& p)
    : AudioProcessorEditor(&p), processorRef(p),
      att_REVERB_SIZE_WR0M(*processorRef.apvts.getParameter("REVERB_SIZE_WR0M"),knob_REVERB_SIZE_WR0M),
      att_REVERB_DAMP_WR0M(*processorRef.apvts.getParameter("REVERB_DAMP_WR0M"),knob_REVERB_DAMP_WR0M),
      att_REVERB_MIX_WR0M(*processorRef.apvts.getParameter("REVERB_MIX_WR0M"),knob_REVERB_MIX_WR0M),
      att_DISTORTION_DRIVE_YFA3(*processorRef.apvts.getParameter("DISTORTION_DRIVE_YFA3"),knob_DISTORTION_DRIVE_YFA3),
      att_DISTORTION_MIX_YFA3(*processorRef.apvts.getParameter("DISTORTION_MIX_YFA3"),knob_DISTORTION_MIX_YFA3)
{
    setLookAndFeel(&lnf);
    setSize(480,270);
    knob_REVERB_SIZE_WR0M.setSliderStyle(juce::Slider::Rotary);
    knob_REVERB_SIZE_WR0M.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16);
    knob_REVERB_SIZE_WR0M.setLookAndFeel(&lnf);
    addAndMakeVisible(knob_REVERB_SIZE_WR0M);
    lbl_REVERB_SIZE_WR0M.setText("Reverb Size",juce::dontSendNotification);
    lbl_REVERB_SIZE_WR0M.setJustificationType(juce::Justification::centred);
    lbl_REVERB_SIZE_WR0M.setFont(juce::Font(9.5f,juce::Font::bold));
    addAndMakeVisible(lbl_REVERB_SIZE_WR0M);

    knob_REVERB_DAMP_WR0M.setSliderStyle(juce::Slider::Rotary);
    knob_REVERB_DAMP_WR0M.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16);
    knob_REVERB_DAMP_WR0M.setLookAndFeel(&lnf);
    addAndMakeVisible(knob_REVERB_DAMP_WR0M);
    lbl_REVERB_DAMP_WR0M.setText("Reverb Damping",juce::dontSendNotification);
    lbl_REVERB_DAMP_WR0M.setJustificationType(juce::Justification::centred);
    lbl_REVERB_DAMP_WR0M.setFont(juce::Font(9.5f,juce::Font::bold));
    addAndMakeVisible(lbl_REVERB_DAMP_WR0M);

    knob_REVERB_MIX_WR0M.setSliderStyle(juce::Slider::Rotary);
    knob_REVERB_MIX_WR0M.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16);
    knob_REVERB_MIX_WR0M.setLookAndFeel(&lnf);
    addAndMakeVisible(knob_REVERB_MIX_WR0M);
    lbl_REVERB_MIX_WR0M.setText("Reverb Mix",juce::dontSendNotification);
    lbl_REVERB_MIX_WR0M.setJustificationType(juce::Justification::centred);
    lbl_REVERB_MIX_WR0M.setFont(juce::Font(9.5f,juce::Font::bold));
    addAndMakeVisible(lbl_REVERB_MIX_WR0M);

    knob_DISTORTION_DRIVE_YFA3.setSliderStyle(juce::Slider::Rotary);
    knob_DISTORTION_DRIVE_YFA3.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16);
    knob_DISTORTION_DRIVE_YFA3.setLookAndFeel(&lnf);
    addAndMakeVisible(knob_DISTORTION_DRIVE_YFA3);
    lbl_DISTORTION_DRIVE_YFA3.setText("Distortion Drive",juce::dontSendNotification);
    lbl_DISTORTION_DRIVE_YFA3.setJustificationType(juce::Justification::centred);
    lbl_DISTORTION_DRIVE_YFA3.setFont(juce::Font(9.5f,juce::Font::bold));
    addAndMakeVisible(lbl_DISTORTION_DRIVE_YFA3);

    knob_DISTORTION_MIX_YFA3.setSliderStyle(juce::Slider::Rotary);
    knob_DISTORTION_MIX_YFA3.setTextBoxStyle(juce::Slider::TextBoxBelow,false,70,16);
    knob_DISTORTION_MIX_YFA3.setLookAndFeel(&lnf);
    addAndMakeVisible(knob_DISTORTION_MIX_YFA3);
    lbl_DISTORTION_MIX_YFA3.setText("Distortion Mix",juce::dontSendNotification);
    lbl_DISTORTION_MIX_YFA3.setJustificationType(juce::Justification::centred);
    lbl_DISTORTION_MIX_YFA3.setFont(juce::Font(9.5f,juce::Font::bold));
    addAndMakeVisible(lbl_DISTORTION_MIX_YFA3);
}

IkonosV2AudioProcessorEditor::~IkonosV2AudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

void IkonosV2AudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colour(0xff59677d));
    g.setColour(juce::Colour(0xff4df3ff).withAlpha(0.1f));
    g.fillRect(0,0,getWidth(),50);
    g.setColour(juce::Colour(0xffe8eaf0).withAlpha(0.5f));
    g.setFont(juce::Font("Space Grotesk",10.f,juce::Font::bold));
    g.drawText("ARCHERGATE",16,6,getWidth()-32,14,juce::Justification::left);
    g.setColour(juce::Colour(0xff4df3ff));
    g.setFont(juce::Font("Space Grotesk",15.f,juce::Font::bold));
    g.drawText("IKONOS V2",16,20,getWidth()-32,18,juce::Justification::centred);
}

void IkonosV2AudioProcessorEditor::resized()
{
    knob_REVERB_SIZE_WR0M.setBounds(20+0*110,60+0*90,85,70);
    lbl_REVERB_SIZE_WR0M.setBounds(20+0*110,127+0*90,85,13);
    knob_REVERB_DAMP_WR0M.setBounds(20+1*110,60+0*90,85,70);
    lbl_REVERB_DAMP_WR0M.setBounds(20+1*110,127+0*90,85,13);
    knob_REVERB_MIX_WR0M.setBounds(20+2*110,60+0*90,85,70);
    lbl_REVERB_MIX_WR0M.setBounds(20+2*110,127+0*90,85,13);
    knob_DISTORTION_DRIVE_YFA3.setBounds(20+3*110,60+0*90,85,70);
    lbl_DISTORTION_DRIVE_YFA3.setBounds(20+3*110,127+0*90,85,13);
    knob_DISTORTION_MIX_YFA3.setBounds(20+0*110,60+1*90,85,70);
    lbl_DISTORTION_MIX_YFA3.setBounds(20+0*110,127+1*90,85,13);
}
