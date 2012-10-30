#ifndef OFXLIBROCKETCONTROLS_H
#define OFXLIBROCKETCONTROLS_H

#include "Rocket/Controls/ElementFormControlInput.h"
#include "ofxLibRocketElement.h"

class ofxLibRocketControl: public ofxLibRocketElement{
public:
	ofxLibRocketControl(Rocket::Core::Element* e);
protected:
	Rocket::Controls::ElementFormControlInput* rocketControl;	
};

/************************************************************************************/

class ofxLibRocketSlider:public ofxLibRocketControl{
public:
	enum ORIENTATION{HORIZONTAL, VERTICAL};

	ofxLibRocketSlider(Rocket::Core::Element* e);
	void setStep(float step);
	void setMin(float min);
	void setMax(float max);
	void setOrientation(ORIENTATION orientation);
	float getValue();
	void setValue(float value);
	void setFloatPointer(float* ptr);
	
	ofEvent<ofxLibRocketFloatEventArgs> eventChange;
	
private:
	virtual void ProcessRocketEvent(Rocket::Core::Event&);	
	float* floatPtr;
};

/************************************************************************************/

class ofxLibRocketButton;
class ofxLibRocketButtonEventArgs: public ofxLibRocketBoolEventArgs{
public:
	ofxLibRocketButton* button;
};

class ofxLibRocketButton:public ofxLibRocketControl{
public:
	enum TYPE{BANG, TOGGLE};

	ofxLibRocketButton(Rocket::Core::Element* e);
	bool getValue();
	void setValue(bool);
	void setType(TYPE type);
	TYPE getType();
	void setBoolPointer(bool* ptr);
	ofEvent<ofxLibRocketBoolEventArgs> eventChange;
	
private:
	void fireEvent(bool value);
	virtual void ProcessRocketEvent(Rocket::Core::Event&);	
	bool* boolPtr;
};

/************************************************************************************/

class ofxLibRocketTextField:public ofxLibRocketControl{
public:
	ofxLibRocketTextField(Rocket::Core::Element* e);
	void setValue(string);
	string getValue();
	void setStringPointer(string* ptr);
	ofEvent<ofxLibRocketStringEventArgs> eventChange;
	
private:
	virtual void ProcessRocketEvent(Rocket::Core::Event&);	
	string* stringPtr;
};

#endif // OFXLIBROCKETCONTROLS_H