#include "ofxLibRocket.h"
#include "ofxLibRocketElement.h"

using namespace Rocket::Core;

ofxLibRocketElement::ofxLibRocketElement()
{
	
}

ofxLibRocketElement::ofxLibRocketElement(Rocket::Core::Element* el)
{
	setRocketElement(el);
}

ofxLibRocketElement::~ofxLibRocketElement()
{
}

void ofxLibRocketElement::setRocketElement(Rocket::Core::Element* el)
{
	rocketElement = el;

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

Rocket::Core::Element* ofxLibRocketElement::getRocketElement()
{
	return rocketElement;
}

//little helper function to convert the mouse position and button to the event args
ofxLibRocketMouseEventArgs rocketMouseEventToOfx(Rocket::Core::Event& e, ofxLibRocketElement* el)
{
	static ofxLibRocketMouseEventArgs args;
	args.element = el;
	Vector2f off = el->getRocketElement()->GetAbsoluteOffset();
	args.x = e.GetParameter<int>("mouse_x", 0)-off.x;
	args.y = e.GetParameter<int>("mouse_y", 0)-off.y;
	args.button = e.GetParameter<int>("button", 0);
	return args;
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
	else if(e.GetType() == "click") {
		static ofxLibRocketMouseEventArgs args = rocketMouseEventToOfx(e, this);
		ofNotifyEvent(eventMouseClick, args);
	}else if(e.GetType() == "dblclick") {
		static ofxLibRocketMouseEventArgs args = rocketMouseEventToOfx(e, this);
		ofNotifyEvent(eventMouseDoubleClick, args);
	}else if(e.GetType() == "mouseover") {
		static ofxLibRocketMouseEventArgs args = rocketMouseEventToOfx(e, this);
		ofNotifyEvent(eventMouseOver, args);
	}else if(e.GetType() == "mouseout") {
		static ofxLibRocketMouseEventArgs args = rocketMouseEventToOfx(e, this);
		ofNotifyEvent(eventMouseOut, args);
	}else if(e.GetType() == "mousemove") {
		static ofxLibRocketMouseEventArgs args = rocketMouseEventToOfx(e, this);
		ofNotifyEvent(eventMouseMove, args);
	}else if(e.GetType() == "mouseup") {
		static ofxLibRocketMouseEventArgs args = rocketMouseEventToOfx(e, this);
		ofNotifyEvent(eventMouseUp, args);
	}else if(e.GetType() == "mousedown") {
		static ofxLibRocketMouseEventArgs args = rocketMouseEventToOfx(e, this);
		ofNotifyEvent(eventMouseDown, args);
	}else if(e.GetType() == "mousescroll") {
		//TODO
	}

	ProcessRocketEvent(e);
}

ofxLibRocketElement* ofxLibRocketElement::createElement(string tagName, std::map<string, string> attributes)
{
	XMLAttributes rocketAttributes();
	Element* el = Factory::InstanceElement(getRocketElement(), "*", tagName.c_str(), XMLAttributes());
	getRocketElement()->AppendChild(el);
	return new ofxLibRocketElement();
}

ofxLibRocketElement* ofxLibRocketElement::createElement(string tagName)
{
	return createElement(tagName, std::map<string, string>());
}

int ofxLibRocketElement::getX(){
	return rocketElement->GetAbsoluteLeft();
}

int ofxLibRocketElement::getY(){
	return rocketElement->GetAbsoluteTop();
}

int ofxLibRocketElement::getHeight()
{
	return rocketElement->GetClientHeight();
}

int ofxLibRocketElement::getWidth()
{
	return rocketElement->GetClientWidth();
}

string ofxLibRocketElement::getId()
{
	return rocketElement->GetId().CString();
}

ofxLibRocketDocument* ofxLibRocketElement::getDocument()
{
	return ofxLibRocket::getDocumentFromRocket(rocketElement->GetOwnerDocument());
}

void ofxLibRocketElement::addListener(ofxLibRocketElementListener* listener)
{
	//ofAddListener(event)
}

void ofxLibRocketElement::removeListener(ofxLibRocketElementListener* listener)
{
}

