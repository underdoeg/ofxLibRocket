#ifndef OFXLIBROCKETELEMENT_H
#define OFXLIBROCKETELEMENT_H

#include "ofMain.h"
#include "Rocket/Core.h"

class ofxLibRocketElement
{
public:
	ofxLibRocketElement(Rocket::Core::Element* e);
	~ofxLibRocketElement();
	Rocket::Core::Element* getRocketElement();
private:
	Rocket::Core::Element* rocketElement;
};

#endif // OFXLIBROCKETELEMENT_H
