#ifndef OFXLIBROCKETCUSTOMELEMENT_H
#define OFXLIBROCKETCUSTOMELEMENT_H

#include "ofxLibRocketElement.h" // Base class: ofxLibRocketElement

class ofxLibRocketCustomElement;

class ofxLibRocketCustomElementInstancer: public Rocket::Core::ElementInstancer
{
public:
	ofxLibRocketCustomElementInstancer();
	~ofxLibRocketCustomElementInstancer();

	Rocket::Core::Element* InstanceElement(Rocket::Core::Element* parent, const Rocket::Core::String& tag, const Rocket::Core::XMLAttributes& attributes);
	void Release();
	void ReleaseElement(Rocket::Core::Element* element);
	
	static ofxLibRocketCustomElementInstancer* get();
	
	template <class T>
	static void addCustomElement(string tagName);
private:
	static ofxLibRocketCustomElementInstancer* singleton;
	static map<string, ofxLibRocketCustomElement*(*)(string)> instancers;
};

class ofxLibRocketCustomElement : public Rocket::Core::Element
{
public:
	ofxLibRocketCustomElement(string tagName);
	~ofxLibRocketCustomElement();

	virtual void setup() {};
	virtual void draw() {};
	virtual void onMouseMove(int x, int y) {};
	virtual void onMousePress(int x, int y, int button) {};
	virtual void onMouseUp(int x, int y, int button) {};
	virtual void onMouseDrag(int x, int y, int button) {};
	virtual void onMouseEnter(int x, int y) {};

public:
	void ProcessRocketEvent(Rocket::Core::Event& e);
};

#endif // OFXLIBROCKETCUSTOMELEMENT_H
