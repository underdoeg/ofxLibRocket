#ifndef OFXLIBROCKETEVENTS_H
#define OFXLIBROCKETEVENTS_H

#include "Rocket/Core.h"
#include "ofMain.h"

class ofxLibRocketEvent: public ofEventArgs 
{
public:
	ofxLibRocketEvent();
	~ofxLibRocketEvent();
	
	Rocket::Core::Element* element;
	

};

class ofxLibRocketListener{
	virtual void onLibrocket
}

#endif // OFXLIBROCKETEVENTS_H
