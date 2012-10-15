#ifndef OFXLIBROCKETSLIDER2D_H
#define OFXLIBROCKETSLIDER2D_H

#include "ofxLibRocketCustomElement.h" // Base class: ofxLibRocketCustomElement

class ofxLibRocketSlider2d : public ofxLibRocketCustomElement
{
public:
	ofxLibRocketSlider2d();
	~ofxLibRocketSlider2d();
	void setup();
public:
	ofxLibRocketElement* handle;
};

#endif // OFXLIBROCKETSLIDER2D_H
