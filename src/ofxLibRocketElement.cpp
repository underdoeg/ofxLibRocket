#include "ofxLibRocketElement.h"

using namespace Rocket::Core;

ofxLibRocketElement::ofxLibRocketElement(Rocket::Core::Element* e)
{
	rocketElement = e;

	getRocketElement()->AddEventListener("show", this);
	getRocketElement()->AddEventListener("hide", this);
	getRocketElement()->AddEventListener("resize", this);
	getRocketElement()->AddEventListener("scroll", this);
	getRocketElement()->AddEventListener("focus", this);
	getRocketElement()->AddEventListener("blur", this);

	/*mouse events*/
	getRocketElement()->AddEventListener("click", this);
	getRocketElement()->AddEventListener("dblclick", this);
	getRocketElement()->AddEventListener("mouseover", this);
	getRocketElement()->AddEventListener("mouseout", this);
	getRocketElement()->AddEventListener("mousemove", this);
	getRocketElement()->AddEventListener("mouseup", this);
	getRocketElement()->AddEventListener("mousedown", this);
	getRocketElement()->AddEventListener("mousescroll", this);
	
}

ofxLibRocketElement::~ofxLibRocketElement()
{
}

Rocket::Core::Element* ofxLibRocketElement::getRocketElement()
{
	return rocketElement;
}

void ofxLibRocketElement::ProcessEvent(Rocket::Core::Event& e)
{
	/* basic events */
	if(e.GetType() == "show") {
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(eventShow, args);
	} else if(e.GetType() == "hide") {
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(eventHide, args);
	} else if(e.GetType() == "resize") {
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(eventResize, args);
	} else if(e.GetType() == "scroll") {
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(eventScroll, args);
	} else if(e.GetType() == "focus") {
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(eventFocus, args);
	} else if(e.GetType() == "blur") {
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(eventBlur, args);
	}

	/* mouse events */
	else if(e.GetType() == "") {

	}

	ProcessRocketEvent(e);
}

ofxLibRocketElement* ofxLibRocketElement::createElement(string tagName, std::map<string, string> attributes)
{
	XMLAttributes rocketAttributes();
	Element* el = Factory::InstanceElement(getRocketElement(), "*", tagName.c_str(), XMLAttributes());
	return new ofxLibRocketElement(el);
}

ofxLibRocketElement* ofxLibRocketElement::createElement(string tagName)
{
	createElement(tagName, std::map<string, string>());
}
