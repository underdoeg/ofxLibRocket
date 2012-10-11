#include "ofxLibRocketCustomElement.h"

using namespace Rocket::Core;

template <class T>
T ofxLibRocketCreateCustomElement(){
	return new T();
}

ofxLibRocketCustomElementInstancer::ofxLibRocketCustomElementInstancer()
{
}

ofxLibRocketCustomElementInstancer::~ofxLibRocketCustomElementInstancer()
{
}

Rocket::Core::Element* ofxLibRocketCustomElementInstancer::InstanceElement(Rocket::Core::Element* parent, const Rocket::Core::String& tag, const Rocket::Core::XMLAttributes& attributes)
{
	
}

void ofxLibRocketCustomElementInstancer::Release()
{
}

void ofxLibRocketCustomElementInstancer::ReleaseElement(Rocket::Core::Element* element)
{
}

template <class T>
void ofxLibRocketCustomElementInstancer::addCustomElement(string tagName)
{
	
}

/*********************************************************************************/

ofxLibRocketCustomElement::ofxLibRocketCustomElement(string tagName):Element(tagName.c_str())
{
}

ofxLibRocketCustomElement::~ofxLibRocketCustomElement()
{

}

void ofxLibRocketCustomElement::ProcessRocketEvent(Rocket::Core::Event& e)
{

}

