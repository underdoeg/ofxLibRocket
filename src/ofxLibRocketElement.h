#ifndef OFXLIBROCKETELEMENT_H
#define OFXLIBROCKETELEMENT_H

#include "ofxLibRocketEvents.h"
#include "ofMain.h"
#include "Rocket/Core.h"

class ofxLibRocketElement: public Rocket::Core::EventListener
{
public:
	ofxLibRocketElement(Rocket::Core::Element* e);
	~ofxLibRocketElement();
	Rocket::Core::Element* getRocketElement();
	
	ofxLibRocketEvents events;
	
protected:
	virtual void ProcessEvent(Rocket::Core::Event&){}

	Rocket::Core::Element* rocketElement;
};

#endif // OFXLIBROCKETELEMENT_H
