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
	if(e.GetType() == "show"){
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(events.show, args);
	}else if(e.GetType() == "hide"){
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(events.hide, args);
	}else if(e.GetType() == "resize"){
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(events.resize, args);
	}else if(e.GetType() == "scroll"){
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(events.scroll, args);
	}else if(e.GetType() == "focus"){
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(events.focus, args);
	}else if(e.GetType() == "blur"){
		static ofxLibRocketEventArgs args;
		args.element = this;
		ofNotifyEvent(events.blur, args);
	}
}
