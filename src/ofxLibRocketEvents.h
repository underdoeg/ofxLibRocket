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

class ofxLibRocketSliderEventArgs: public ofEventArgs 
{
public:
	ofxLibRocketElement* element;
	ofxLibRocketSlider* slider;
};

class ofxLibRocketListener{
	
};

class ofxLibRocketEvents{
public:
	/* general events */
	ofEvent<ofxLibRocketEventArgs> onShow;
	ofEvent<ofxLibRocketEventArgs> onHide;
	ofEvent<ofxLibRocketEventArgs> onResize;
	ofEvent<ofxLibRocketEventArgs> onScroll;
	ofEvent<ofxLibRocketEventArgs> onFocus;
	ofEvent<ofxLibRocketEventArgs> onBlur;
};

#endif // OFXLIBROCKETEVENTS_H
