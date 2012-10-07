#ifndef OFXLIBROCKETEVENTS_H
#define OFXLIBROCKETEVENTS_H

#include "Rocket/Core.h"
#include "ofMain.h"

class ofxLibRocketElement;
class ofxLibRocketSlider;

class ofxLibRocketEventArgs: public ofEventArgs
{
public:
	ofxLibRocketElement* element;
};

class ofxLibRocketResizeEventArgs: public ofxLibRocketEventArgs, public ofResizeEventArgs
{

};

class ofxLibRocketSliderEventArgs: public ofEventArgs
{
public:
	ofxLibRocketElement* element;
	ofxLibRocketSlider* slider;
};

class ofxLibRocketFloatEventArgs: public ofxLibRocketEventArgs
{
public:
	float value;
};

class ofxLibRocketBoolEventArgs: public ofxLibRocketEventArgs
{
public:
	bool value;
};

class ofxLibRocketStringEventArgs: public ofxLibRocketEventArgs
{
public:
	string value;
};

#endif // OFXLIBROCKETEVENTS_H
