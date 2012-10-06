#ifndef OFXLIBROCKETCONTROLS_H
#define OFXLIBROCKETCONTROLS_H

#include "ElementFormControlInput.h"
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
	
private:
	virtual void ProcessEvent(Rocket::Core::Event&);	
};

/************************************************************************************/


#endif // OFXLIBROCKETCONTROLS_H