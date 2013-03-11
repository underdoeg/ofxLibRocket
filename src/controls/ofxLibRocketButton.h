#ifndef OFXLIBROCKETBUTTON_H
#define OFXLIBROCKETBUTTON_H

#include "ofxLibRocketControlBase.h" // Base class: ofxLibRocketControlsBase

class ofxLibRocketButton : public ofxLibRocketControlBase<bool>
{
public:
	ofxLibRocketButton();
	~ofxLibRocketButton();
	
	void setup();
	
	void valueChanged(bool val);
};

#endif // OFXLIBROCKETBUTTON_H
