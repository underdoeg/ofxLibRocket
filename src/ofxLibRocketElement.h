#ifndef OFXLIBROCKETELEMENT_H
#define OFXLIBROCKETELEMENT_H

#include "ofxLibRocketEvents.h"
#include "ofMain.h"
#include "Rocket/Core.h"

class ofxLibRocketDocument;

class ofxLibRocketElementListener{
public:
	virtual void onMouseMove(int x, int y) {};
	virtual void onMousePress(int x, int y, int button) {};
	virtual void onMouseUp(int x, int y, int button) {};
	virtual void onMouseDrag(int x, int y, int button) {};
	virtual void onMouseEnter(int x, int y) {};
	virtual void onMouseOut(int x, int y){};
	
	virtual void onMouseMove(ofxLibRocketMouseEventArgs &e) {};
	virtual void onMousePress(ofxLibRocketMouseEventArgs &e) {};
	virtual void onMouseUp(ofxLibRocketMouseEventArgs &e) {};
	virtual void onMouseDrag(ofxLibRocketMouseEventArgs &e) {};
	virtual void onMouseEnter(ofxLibRocketMouseEventArgs &e) {};
	virtual void onMouseOut(ofxLibRocketMouseEventArgs &e){};
private:
	void _mouseMove(ofxLibRocketMouseEventArgs &e) {onMouseMove(e);onMouseMove(e.x, e.y);};
	void _mousePress(ofxLibRocketMouseEventArgs &e) {onMousePress(e);onMousePress(e.x, e.y, e.button);};
	void _mouseUp(ofxLibRocketMouseEventArgs &e) {onMousePress(e);onMousePress(e.x, e.y, e.button);};
	void _mouseDrag(ofxLibRocketMouseEventArgs &e) {onMouseDrag(e);onMouseDrag(e.x, e.y, e.button);};
	void _mouseEnter(ofxLibRocketMouseEventArgs &e) {onMouseEnter(e);onMouseEnter(e.x, e.y);};
	void _mouseOut(ofxLibRocketMouseEventArgs &e){onMouseOut(e);onMouseOut(e.x, e.y);};
};

class ofxLibRocketElement: protected Rocket::Core::EventListener
{
public:
	ofxLibRocketElement();
	ofxLibRocketElement(Rocket::Core::Element* el);
	~ofxLibRocketElement();
	
	void setRocketElement(Rocket::Core::Element* el);
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
	string getId();
	
	ofxLibRocketElement* createElement(string tagName);
	ofxLibRocketElement* createElement(string tagName, std::map<string, string> attributes);
	
	ofxLibRocketDocument* getDocument();
	
	void addListener(ofxLibRocketElementListener* listener);
	void removeListener(ofxLibRocketElementListener* listener);
	
protected:
	virtual void ProcessRocketEvent(Rocket::Core::Event& e){}
	void ProcessEvent(Rocket::Core::Event&);

	Rocket::Core::Element* rocketElement;
};

class ofxLibRocketElementList: public std::vector<ofxLibRocketElement*>{
	
};

#endif // OFXLIBROCKETELEMENT_H
