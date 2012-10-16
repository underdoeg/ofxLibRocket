#ifndef OFXLIBROCKETELEMENT_H
#define OFXLIBROCKETELEMENT_H

#include "ofxLibRocketEvents.h"
#include "ofMain.h"
#include "Rocket/Core.h"

class ofxLibRocketElement: protected Rocket::Core::EventListener
{
public:
	ofxLibRocketElement(Rocket::Core::Element* e);
	~ofxLibRocketElement();
	Rocket::Core::Element* getRocketElement();
	
	ofEvent<ofxLibRocketEventArgs> eventUpdate;
	ofEvent<ofxLibRocketEventArgs> eventDraw;
	
	ofEvent<ofxLibRocketEventArgs> eventShow;
	ofEvent<ofxLibRocketEventArgs> eventHide;
	ofEvent<ofxLibRocketEventArgs> eventResize;
	ofEvent<ofxLibRocketEventArgs> eventScroll;
	ofEvent<ofxLibRocketEventArgs> eventFocus;
	ofEvent<ofxLibRocketEventArgs> eventBlur;

	ofEvent<ofxLibRocketMouseEventArgs> eventMouseClick;
	ofEvent<ofxLibRocketMouseEventArgs> eventMouseDoubleClick;	
	ofEvent<ofxLibRocketMouseEventArgs> eventMouseMove;
	ofEvent<ofxLibRocketMouseEventArgs> eventMouseDrag;
	ofEvent<ofxLibRocketMouseEventArgs> eventMouseDown;
	ofEvent<ofxLibRocketMouseEventArgs> eventMouseUp;
	ofEvent<ofxLibRocketMouseEventArgs> eventMouseOver;
	ofEvent<ofxLibRocketMouseEventArgs> eventMouseOut;
	ofEvent<ofxLibRocketMouseEventArgs> eventMouseScroll;
	
	int getWidth();
	int getHeight();
	int getX();
	int getY();
	
	ofxLibRocketElement* createElement(string tagName);
	ofxLibRocketElement* createElement(string tagName, std::map<string, string> attributes);
	
protected:
	virtual void ProcessRocketEvent(Rocket::Core::Event& e){}
	void ProcessEvent(Rocket::Core::Event&);

	Rocket::Core::Element* rocketElement;
};

#endif // OFXLIBROCKETELEMENT_H
