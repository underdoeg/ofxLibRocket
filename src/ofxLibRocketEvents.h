#ifndef OFXLIBROCKETEVENTS_H
#define OFXLIBROCKETEVENTS_H

#include "Rocket/Core.h"
#include "ofMain.h"

class ofxLibRocketElement;
class ofxLibRocketSlider;

class ofxLibRocketEvent: public ofEventArgs 
{
public:
	ofxLibRocketElement* element;
};

class ofxLibRocketSliderEvent: public ofEventArgs 
{
public:
	ofxLibRocketElement* element;
	ofxLibRocketSlider* slider;
};

class ofxLibRocketListener{
	
};

#endif // OFXLIBROCKETEVENTS_H
