#include "ofxLibRocketElement.h"

ofxLibRocketElement::ofxLibRocketElement(Rocket::Core::Element* e)
{
	rocketElement = e;
	rocketElement->AddEventListener("show", this);
	rocketElement->AddEventListener("hide", this);
	rocketElement->AddEventListener("resize", this);
	rocketElement->AddEventListener("scroll", this);
	rocketElement->AddEventListener("focus", this);
	rocketElement->AddEventListener("blur", this);
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
	if(e.GetType() == "show"){
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(eventShow, args);
	}else if(e.GetType() == "hide"){
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(eventHide, args);
	}else if(e.GetType() == "resize"){
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(eventResize, args);
	}else if(e.GetType() == "scroll"){
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(eventScroll, args);
	}else if(e.GetType() == "focus"){
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(eventFocus, args);
	}else if(e.GetType() == "blur"){
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(eventBlur, args);
	}
	
	/* mouse events */
	else if(e.GetType() == ""){
		
	}
	
	ProcessRocketEvent(e);
}
