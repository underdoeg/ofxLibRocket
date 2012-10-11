#ifndef OFXLIBROCKETSLIDER2D_H
#define OFXLIBROCKETSLIDER2D_H

#include "ofxLibRocketCustomElement.h" // Base class: ofxLibRocketCustomElement

class ofxLibRocketSlider2d : public ofxLibRocketCustomElement
{
public:
	ofxLibRocketSlider2d(string tagName);
	~ofxLibRocketSlider2d();
	void setup(){cout << "HOHOHOHO" << endl;}
public:
	
};

#endif // OFXLIBROCKETSLIDER2D_H
