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

class ofxLibRocketElementEvents{
public:
	/* general events */
	ofEvent<ofxLibRocketEventArgs> show;
	ofEvent<ofxLibRocketEventArgs> hide;
	ofEvent<ofxLibRocketEventArgs> resize;
	ofEvent<ofxLibRocketEventArgs> scroll;
	ofEvent<ofxLibRocketEventArgs> focus;
	ofEvent<ofxLibRocketEventArgs> blur;
	
	/*mouse events*/
	
};

#endif // OFXLIBROCKETEVENTS_H
