#ifndef OFXLIBROCKETELEMENT_H
#define OFXLIBROCKETELEMENT_H

#include "ofMain.h"
#include "Rocket/Core.h"

class ofxLibRocketElement: public Rocket::Core::EventListener
{
public:
	ofxLibRocketElement(Rocket::Core::Element* e);
	~ofxLibRocketElement();
	Rocket::Core::Element* getRocketElement();
protected:
	virtual void ProcessEvent(Rocket::Core::Event&){}

	Rocket::Core::Element* rocketElement;
};

#endif // OFXLIBROCKETELEMENT_H
