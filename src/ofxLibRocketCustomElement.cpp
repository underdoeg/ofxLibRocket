#include "ofxLibRocketCustomElement.h"

using namespace Rocket::Core;

template <class T>
T ofxLibRocketCreateCustomElement(string tagName){
	return new T(tagName.c_str());
}

map<string, ofxLibRocketCustomElement*(*)(string)> ofxLibRocketCustomElementInstancer::instancers;
ofxLibRocketCustomElementInstancer* ofxLibRocketCustomElementInstancer::singleton = NULL;

ofxLibRocketCustomElementInstancer::ofxLibRocketCustomElementInstancer()
{
}

ofxLibRocketCustomElementInstancer::~ofxLibRocketCustomElementInstancer()
{
}

Rocket::Core::Element* ofxLibRocketCustomElementInstancer::InstanceElement(Rocket::Core::Element* parent, const Rocket::Core::String& tag, const Rocket::Core::XMLAttributes& attributes)
{
	if(instancers.find(tag.CString()) != instancers.end())
		return instancers[tag.CString()](tag.CString());
	return NULL; //shouldn't happen
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
	instancers[tagName] = &ofxLibRocketCreateCustomElement<T>;
	Rocket::Core::Factory::RegisterElementInstancer(tagName.c_str(), get());
}


ofxLibRocketCustomElementInstancer* ofxLibRocketCustomElementInstancer::get()
{
	if(singleton == NULL)
		singleton = new ofxLibRocketCustomElementInstancer();
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
