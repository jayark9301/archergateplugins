#pragma once
#include <JuceHeader.h>

class IkonosV2LookAndFeel : public juce::LookAndFeel_V4
{
public:
    IkonosV2LookAndFeel()
    {
        setColour(juce::Slider::thumbColourId,            juce::Colour(0xff4df3ff));
        setColour(juce::Slider::rotarySliderFillColourId, juce::Colour(0xff4df3ff));
        setColour(juce::Slider::rotarySliderOutlineColourId, juce::Colour(0x334df3ff));
        setColour(juce::Label::textColourId,              juce::Colour(0xffe8eaf0));
        setColour(juce::ResizableWindow::backgroundColourId, juce::Colour(0xff59677d));
    }

    void drawRotarySlider(juce::Graphics& g,int x,int y,int w,int h,float pos,
        float startAngle,float endAngle,juce::Slider& slider) override
    {
        float r=juce::jmin(w*.5f,h*.5f)-4.f,cx=x+w*.5f,cy=y+h*.5f;
        float angle=startAngle+pos*(endAngle-startAngle);
        juce::Path bg,fill;
        bg.addArc(cx-r,cy-r,r*2,r*2,startAngle,endAngle,true);
        g.setColour(slider.findColour(juce::Slider::rotarySliderOutlineColourId));
        g.strokePath(bg,juce::PathStrokeType(3.5f,juce::PathStrokeType::curved,juce::PathStrokeType::rounded));
        fill.addArc(cx-r,cy-r,r*2,r*2,startAngle,angle,true);
        g.setColour(slider.findColour(juce::Slider::rotarySliderFillColourId));
        g.strokePath(fill,juce::PathStrokeType(3.5f,juce::PathStrokeType::curved,juce::PathStrokeType::rounded));
        float tx=cx+(r-6)*std::cos(angle-juce::MathConstants<float>::halfPi);
        float ty=cy+(r-6)*std::sin(angle-juce::MathConstants<float>::halfPi);
        g.setColour(slider.findColour(juce::Slider::thumbColourId));
        g.fillEllipse(tx-3,ty-3,6,6);
    }
};
