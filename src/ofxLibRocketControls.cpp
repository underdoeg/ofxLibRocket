#include "ofxLibRocketControls.h"

using namespace Rocket::Core;
using namespace Rocket::Controls;

ofxLibRocketControl::ofxLibRocketControl(Rocket::Core::Element* e):ofxLibRocketElement(e)
{
	rocketControl = static_cast<ElementFormControlInput*>(e);
}

/************************************************************************************/

ofxLibRocketSlider::ofxLibRocketSlider(Rocket::Core::Element* e):ofxLibRocketControl(e)
{
	rocketElement->AddEventListener("change", this);
	floatPtr = NULL;
}

float ofxLibRocketSlider::getValue()
{
	return ofToFloat(rocketControl->GetValue().CString());
}

void ofxLibRocketSlider::ProcessRocketEvent(Rocket::Core::Event& e)
{
	if(e.GetType() == "change") {
		float val = getValue();
		ofxLibRocketFloatEventArgs args;
		args.element = this;
		args.value = val;
		ofNotifyEvent(eventChange, args);

		//update float pointer
		if(floatPtr != NULL)
			*floatPtr = val;
	}
}

void ofxLibRocketSlider::setMax(float max)
{
	rocketElement->SetAttribute<float>("max", max);
}

void ofxLibRocketSlider::setMin(float min)
{
	rocketElement->SetAttribute<float>("min", min);
}

void ofxLibRocketSlider::setOrientation(ORIENTATION orientation)
{
	string orientationString = "horizontal";
	if(orientation == VERTICAL)
		orientationString = "vertical";
	rocketElement->SetAttribute<String>("orientation", orientationString.c_str());
}

void ofxLibRocketSlider::setStep(float step)
{
	rocketElement->SetAttribute<float>("step", step);
}

void ofxLibRocketSlider::setFloatPointer(float* ptr)
{
	floatPtr = ptr;
	*floatPtr = getValue();
}

void ofxLibRocketSlider::setValue(float value)
{
	rocketElement->SetAttribute<float>("value", value);
}

/********************************************************************************************************************/

ofxLibRocketButton::ofxLibRocketButton(Rocket::Core::Element* e):ofxLibRocketControl(e)
{
	boolPtr = NULL;
}

bool ofxLibRocketButton::getValue()
{
	return rocketElement->GetAttribute<bool>("value", false);
}

void ofxLibRocketButton::setBoolPointer(bool* ptr)
{
	boolPtr = ptr;
}

void ofxLibRocketButton::setValue(bool val)
{
	rocketElement->SetPseudoClass("on", val);
	rocketElement->SetAttribute<bool>("value", val);
}

void ofxLibRocketButton::ProcessRocketEvent(Rocket::Core::Event& e)
{
	if(e.GetType() == "mousedown") {
		bool val = getValue();
		val = !val;
		setValue(val);
		fireEvent(val);
	} else if(e.GetType() == "mouseup") {
		if(getType() == BANG) {
			bool val = getValue();
			val = !val;
			setValue(val);
			fireEvent(val);
		}
	}
}

ofxLibRocketButton::TYPE ofxLibRocketButton::getType()
{
	String type = rocketElement->GetAttribute<String>("type", "bang");
	if(type == "toggle")
		return TOGGLE;
	else
		return BANG;
}

void ofxLibRocketButton::setType(TYPE type)
{
	string strType = "bang";
	if(type == TOGGLE)
		strType = "toggle";
	rocketElement->SetAttribute<String>("type", strType.c_str());
}

void ofxLibRocketButton::fireEvent(bool val)
{
	ofxLibRocketBoolEventArgs args;
	args.element = this;
	args.value = val;
	ofNotifyEvent(eventChange, args);

	//update float pointer
	if(boolPtr != NULL)
		*boolPtr = val;
}

/********************************************************************************************************************/

ofxLibRocketTextField::ofxLibRocketTextField(Rocket::Core::Element* e):ofxLibRocketControl(e)
{
	stringPtr = NULL;
	rocketElement->AddEventListener("change", this);
}

string ofxLibRocketTextField::getValue()
{
	return rocketElement->GetAttribute<String>("value", "").CString();
}

void ofxLibRocketTextField::setStringPointer(string* ptr)
{
	stringPtr = ptr;
	*stringPtr = getValue();
}

void ofxLibRocketTextField::setValue(string val)
{
	rocketElement->SetAttribute<String>("value", val.c_str());
}

void ofxLibRocketTextField::ProcessRocketEvent(Rocket::Core::Event& e)
{
	if(e.GetType() == "change") {
		string val = getValue();
		ofxLibRocketStringEventArgs args;
		args.element = this;
		args.value = val;
		ofNotifyEvent(eventChange, args);

		//update float pointer
		if(stringPtr != NULL)
			*stringPtr = val;
	}
}
