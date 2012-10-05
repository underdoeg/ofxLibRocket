#include "ofxLibRocketElement.h"

ofxLibRocketElement::ofxLibRocketElement(Rocket::Core::Element* e)
{
	rocketElement = e;
}

ofxLibRocketElement::~ofxLibRocketElement()
{
}

Rocket::Core::Element* ofxLibRocketElement::getRocketElement()
{
	return rocketElement;
}
