#ifndef OFXLIBROCKETELEMENT_H
#define OFXLIBROCKETELEMENT_H

#include "ofxLibRocketEvents.h"
#include "ofMain.h"
#include "Rocket/Core.h"

class ofxLibRocketDocument;

class ofxLibRocketElementListener
{
public:
	/* ELEMENT EVENTS */
	virtual void onShow(){};
	virtual void onHide(){};
	virtual void onResize(float w, float h){};
	virtual void onFocus(){};
	virtual void onBlur(){};
	//virtual void onScroll(){};
	
	virtual void onShow(ofxLibRocketEventArgs &e){};
	virtual void onHide(ofxLibRocketEventArgs &e){};
	virtual void onResize(ofxLibRocketResizeEventArgs &e){};
	virtual void onFocus(ofxLibRocketEventArgs &e){};
	virtual void onBlur(ofxLibRocketEventArgs &e){};
	//virtual void on
	
	/* MOUSE EVENTS */
	virtual void onMouseClick(int x, int y, int button) {};
	virtual void onMouseDoubleClick(int x, int y, int button) {};
	virtual void onMouseMove(int x, int y) {};
	virtual void onMousePress(int x, int y, int button) {};
	virtual void onMouseUp(int x, int y, int button) {};
	virtual void onMouseDrag(int x, int y, int button) {};
	virtual void onMouseEnter(int x, int y) {};
	virtual void onMouseOut(int x, int y) {};
	virtual void onMouseOver(int x, int y) {};
	virtual void onAttributeChange(string attribute) {};

	virtual void onMouseClick(ofxLibRocketMouseEventArgs &e) {};
	virtual void onMouseDoubleClick(ofxLibRocketMouseEventArgs &e) {};
	virtual void onMouseMove(ofxLibRocketMouseEventArgs &e) {};
	virtual void onMousePress(ofxLibRocketMouseEventArgs &e) {};
	virtual void onMouseUp(ofxLibRocketMouseEventArgs &e) {};
	virtual void onMouseDrag(ofxLibRocketMouseEventArgs &e) {};
	virtual void onMouseEnter(ofxLibRocketMouseEventArgs &e) {};
	virtual void onMouseOut(ofxLibRocketMouseEventArgs &e) {};
	virtual void onMouseOver(ofxLibRocketMouseEventArgs &e) {};
	virtual void onAttributeChange(ofxLibRocketStringEventArgs &e) {};
private:
	void _show(ofxLibRocketEventArgs &e){
		onShow();
		onShow(e);
	};
	void _hide(ofxLibRocketEventArgs &e){
		onHide();
		onHide(e);
	};
	void _resize(ofxLibRocketResizeEventArgs &e){
		onResize(e.width, e.height);
		onResize(e);
	};
	void _focus(ofxLibRocketEventArgs &e){
		onFocus();
		onFocus(e);
	};
	void _blur(ofxLibRocketEventArgs &e){
		onBlur();
		onBlur(e);
	};

	void _mouseClick(ofxLibRocketMouseEventArgs &e) {
		onMouseClick(e);
		onMouseClick(e.x, e.y, e.button);
	};
	void _mouseDoubleClick(ofxLibRocketMouseEventArgs &e) {
		onMouseDoubleClick(e);
		onMouseDoubleClick(e.x, e.y, e.button);
	};
	void _mouseMove(ofxLibRocketMouseEventArgs &e) {
		onMouseMove(e);
		onMouseMove(e.x, e.y);
	};
	void _mousePress(ofxLibRocketMouseEventArgs &e) {
		onMousePress(e);
		onMousePress(e.x, e.y, e.button);
	};
	void _mouseUp(ofxLibRocketMouseEventArgs &e) {
		onMousePress(e);
		onMousePress(e.x, e.y, e.button);
	};
	void _mouseDrag(ofxLibRocketMouseEventArgs &e) {
		onMouseDrag(e);
		onMouseDrag(e.x, e.y, e.button);
	};
	void _mouseEnter(ofxLibRocketMouseEventArgs &e) {
		onMouseEnter(e);
		onMouseEnter(e.x, e.y);
	};
	void _mouseOut(ofxLibRocketMouseEventArgs &e) {
		onMouseOut(e);
		onMouseOut(e.x, e.y);
	};
	
	void _attributeChange(ofxLibRocketStringEventArgs &e){
		onAttributeChange(e.value);
		onAttributeChange(e);
	}
	
	friend class ofxLibRocketElement;	
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
	ofEvent<ofxLibRocketResizeEventArgs> eventResize;
	ofEvent<ofxLibRocketEventArgs> eventScroll;
	ofEvent<ofxLibRocketEventArgs> eventFocus;
	ofEvent<ofxLibRocketEventArgs> eventBlur;

	ofEvent<ofxLibRocketMouseEventArgs> eventMouseClick;
	ofEvent<ofxLibRocketMouseEventArgs> eventMouseDoubleClick;
	ofEvent<ofxLibRocketMouseEventArgs> eventMouseMove;
	ofEvent<ofxLibRocketMouseEventArgs> eventMouseDrag;
	ofEvent<ofxLibRocketMouseEventArgs> eventMousePress;
	ofEvent<ofxLibRocketMouseEventArgs> eventMouseUp;
	ofEvent<ofxLibRocketMouseEventArgs> eventMouseEnter;
	ofEvent<ofxLibRocketMouseEventArgs> eventMouseOut;
	ofEvent<ofxLibRocketMouseEventArgs> eventMouseScroll;
	
	ofEvent<ofxLibRocketStringEventArgs> eventAttributeChange;

	int getWidth();
	int getHeight();
	int getX();
	int getY();

	ofRectangle getBounds();
	
	ofColor getColor();
	ofColor getBackgroundColor();

	void hide();
	void show();

	string getId();

	ofxLibRocketElement* createElement(string tagName);
	ofxLibRocketElement* createElement(string tagName, std::map<string, string> attributes);

	ofxLibRocketDocument* getDocument();

	void addListener(ofxLibRocketElementListener* listener);
	void removeListener(ofxLibRocketElementListener* listener);
	
	string getAttributeAsString(string attribute);
	int getAttributeAsInt(string attribute);
	float getAttributeAsFloat(string attribute);
	
	void setAttributeAsString(string attribute, string value);
	void setAttributeAsInt(string attribute, int value);
	void setAttributeAsFloat(string attribute, float value);
	
protected:
	ofColor convertColorRocket(Rocket::Core::String color);

	virtual void ProcessRocketEvent(Rocket::Core::Event& e) {}
	void ProcessEvent(Rocket::Core::Event&);
	void OnAttributeChange(const Rocket::Core::AttributeNameList& changed_attributes);
	
	Rocket::Core::Element* rocketElement;
private:
	ofxLibRocketMouseEventArgs rocketMouseEventToOfx(Rocket::Core::Event& e);


	bool isMouseDown;
	int buttonDown;
	int mouseX;
	int mouseY;
	int pMouseX;
	int pMouseY;
};

template <class T>
class ofxLibRocketElementList_: public std::vector<T*>
{

};

class ofxLibRocketElementList: public ofxLibRocketElementList_<ofxLibRocketElement>
{

};

#endif // OFXLIBROCKETELEMENT_H
