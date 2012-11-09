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
	isMouseDown = false;

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
ofxLibRocketMouseEventArgs ofxLibRocketElement::rocketMouseEventToOfx(Rocket::Core::Event& e)
{
	static ofxLibRocketMouseEventArgs args;
	args.element = this;
	Vector2f off = this->getRocketElement()->GetAbsoluteOffset();
	args.x = e.GetParameter<int>("mouse_x", 0)-off.x;
	args.y = e.GetParameter<int>("mouse_y", 0)-off.y;
	pMouseX = mouseX;
	pMouseY = mouseY;
	mouseX = args.x;
	mouseY = args.y;
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
		static ofxLibRocketResizeEventArgs args;
		args.element = this;
		args.width = getWidth();
		args.height = getHeight();
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
		static ofxLibRocketMouseEventArgs args = rocketMouseEventToOfx(e);
		ofNotifyEvent(eventMouseClick, args);
	} else if(e.GetType() == "dblclick") {
		static ofxLibRocketMouseEventArgs args = rocketMouseEventToOfx(e);
		ofNotifyEvent(eventMouseDoubleClick, args);
	} else if(e.GetType() == "mouseover") {
		static ofxLibRocketMouseEventArgs args = rocketMouseEventToOfx(e);
		ofNotifyEvent(eventMouseEnter, args);
	} else if(e.GetType() == "mouseout") {
		static ofxLibRocketMouseEventArgs args = rocketMouseEventToOfx(e);
		ofNotifyEvent(eventMouseOut, args);
	} else if(e.GetType() == "mousemove") {
		static ofxLibRocketMouseEventArgs args = rocketMouseEventToOfx(e);
		if(isMouseDown)
			ofNotifyEvent(eventMouseDrag, args);
		else
			ofNotifyEvent(eventMouseMove, args);
	} else if(e.GetType() == "mouseup") {
		isMouseDown = false;
		static ofxLibRocketMouseEventArgs args = rocketMouseEventToOfx(e);
		ofNotifyEvent(eventMouseUp, args);
	} else if(e.GetType() == "mousedown") {
		isMouseDown = true;
		buttonDown = e.GetParameter<int>("button", 0);
		static ofxLibRocketMouseEventArgs args = rocketMouseEventToOfx(e);
		ofNotifyEvent(eventMousePress, args);
	} else if(e.GetType() == "mousescroll") {
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

int ofxLibRocketElement::getX()
{
	return rocketElement->GetAbsoluteLeft();
}

int ofxLibRocketElement::getY()
{
	return rocketElement->GetAbsoluteTop();
}

ofPoint ofxLibRocketElement::getPosition()
{
	return ofPoint(getX(), getY());
}

int ofxLibRocketElement::getHeight()
{
	return rocketElement->GetClientHeight();
}

int ofxLibRocketElement::getWidth()
{
	return rocketElement->GetClientWidth();
}

ofRectangle ofxLibRocketElement::getBounds()
{
	return ofRectangle(getX(), getY(), getWidth(), getHeight());
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
	ofAddListener(eventBlur, listener, &ofxLibRocketElementListener::_blur);
	ofAddListener(eventFocus, listener, &ofxLibRocketElementListener::_focus);
	ofAddListener(eventHide, listener, &ofxLibRocketElementListener::_hide);
	ofAddListener(eventResize, listener, &ofxLibRocketElementListener::_resize);
	ofAddListener(eventShow, listener, &ofxLibRocketElementListener::_show);

	ofAddListener(eventMouseClick, listener, &ofxLibRocketElementListener::_mouseClick);
	ofAddListener(eventMouseDoubleClick, listener, &ofxLibRocketElementListener::_mouseDoubleClick);
	ofAddListener(eventMouseEnter, listener, &ofxLibRocketElementListener::_mouseEnter);
	ofAddListener(eventMouseMove, listener, &ofxLibRocketElementListener::_mouseMove);
	ofAddListener(eventMouseDrag, listener, &ofxLibRocketElementListener::_mouseDrag);
	ofAddListener(eventMouseOut, listener, &ofxLibRocketElementListener::_mouseOut);
	//ofAddListener(eventMouseScroll, listener, &ofxLibRocketElementListener::_mouseScroll);
	ofAddListener(eventMousePress, listener, &ofxLibRocketElementListener::_mousePress);
	ofAddListener(eventMouseUp, listener, &ofxLibRocketElementListener::_mouseUp);
	ofAddListener(eventAttributeChange, listener, &ofxLibRocketElementListener::_attributeChange);
}

void ofxLibRocketElement::removeListener(ofxLibRocketElementListener* listener)
{

}

void ofxLibRocketElement::hide()
{
	rocketElement->SetProperty("display", "none");
}

void ofxLibRocketElement::show()
{
	rocketElement->SetProperty("display", "block");
}

ofColor ofxLibRocketElement::getBackgroundColor()
{
	//Colour<int, 255> color;
	return convertColorRocket(rocketElement->GetProperty< String >("background-color"));
}

ofColor ofxLibRocketElement::getColor()
{
	return convertColorRocket(rocketElement->GetProperty< String >("color"));
}

ofColor ofxLibRocketElement::convertColorRocket(Rocket::Core::String color)
{
	std::vector<string> colors = ofSplitString(color.CString(), ",", true, true);
	if(colors.size() < 4)
		return ofColor::white;
	return ofColor(ofToInt(colors[0]), ofToInt(colors[1]), ofToInt(colors[2]), ofToInt(colors[3]));
}

/*** ATTRIBUTES ****/

float ofxLibRocketElement::getAttributeAsFloat(string attribute)
{
	return rocketElement->GetAttribute<float>(attribute.c_str(), 0.);
}

int ofxLibRocketElement::getAttributeAsInt(string attribute)
{
	return rocketElement->GetAttribute<int>(attribute.c_str(), 0);
}

string ofxLibRocketElement::getAttributeAsString(string attribute)
{
	return rocketElement->GetAttribute<String>(attribute.c_str(), "").CString();
}

bool ofxLibRocketElement::getAttributeAsBool(string attribute)
{
	return rocketElement->GetAttribute<bool>(attribute.c_str(), false);
}

void ofxLibRocketElement::setAttributeAsFloat(string attribute, float value)
{
	rocketElement->SetAttribute<float>(attribute.c_str(), value);
}

void ofxLibRocketElement::setAttributeAsInt(string attribute, int value)
{
	rocketElement->SetAttribute<int>(attribute.c_str(), value);
}

void ofxLibRocketElement::setAttributeAsString(string attribute, string value)
{
	rocketElement->SetAttribute<String>(attribute.c_str(), value.c_str());
}

void ofxLibRocketElement::setAttributeAsBool(string attribute, bool value)
{
	rocketElement->SetAttribute<bool>(attribute.c_str(), value);
}

