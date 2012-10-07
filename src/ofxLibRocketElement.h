#ifndef OFXLIBROCKETELEMENT_H
#define OFXLIBROCKETELEMENT_H

#include "ofxLibRocketEvents.h"
#include "ofMain.h"
#include "Rocket/Core.h"

class ofxLibRocketElement: protected Rocket::Core::EventListener
{
public:
	ofxLibRocketElement(Rocket::Core::Element* e);
	~ofxLibRocketElement();
	Rocket::Core::Element* getRocketElement();
	
	ofEvent<ofxLibRocketEventArgs> eventShow;
	ofEvent<ofxLibRocketEventArgs> eventHide;
	ofEvent<ofxLibRocketEventArgs> eventResize;
	ofEvent<ofxLibRocketEventArgs> eventScroll;
	ofEvent<ofxLibRocketEventArgs> eventFocus;
	ofEvent<ofxLibRocketEventArgs> eventBlur;
	
protected:
	virtual void ProcessRocketEvent(Rocket::Core::Event& e){}
	void ProcessEvent(Rocket::Core::Event&);

	Rocket::Core::Element* rocketElement;
};

#endif // OFXLIBROCKETELEMENT_H
