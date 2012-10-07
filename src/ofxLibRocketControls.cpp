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
	//rocketElement->SetAttribute<float>("step",.3);
	floatPtr = NULL;
}

float ofxLibRocketSlider::getValue()
{
	return ofToFloat(rocketControl->GetValue().CString());
}

void ofxLibRocketSlider::ProcessRocketEvent(Rocket::Core::Event& e)
{
	if(e.GetType() == "change"){
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

float ofxLibRocketSlider::setFloatPointer(float* ptr)
{
	floatPtr = ptr;
	*floatPtr = getValue();
}
