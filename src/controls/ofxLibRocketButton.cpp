#include "ofxLibRocketButton.h"

ofxLibRocketButton::ofxLibRocketButton()
{
	
}

ofxLibRocketButton::~ofxLibRocketButton()
{
}

void ofxLibRocketButton::setup()
{
	cout << "SETUP CALLED " << endl;
	setValue(0);
}

void ofxLibRocketButton::valueChanged(bool val)
{
	setClass("on", val);
}