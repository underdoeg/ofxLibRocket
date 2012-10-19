#ifndef OFXLIBROCKETCUSTOMELEMENT_H
#define OFXLIBROCKETCUSTOMELEMENT_H

#include "ofxLibRocketElement.h" // Base class: ofxLibRocketElement

class ofxLibRocketCustomElement;

/*template <class T>
T* ofxLibRocketCreateCustomElement(string tagName){
	return new T(tagName.c_str());
}*/

class ofxLibRocketCustomElementInstancer
{
public:
	virtual ofxLibRocketCustomElement* createInstance() = 0;
	string tagName;
};

template <class T>
class ofxLibRocketCustomElementInstancerTemplated: public ofxLibRocketCustomElementInstancer
{
public:
	ofxLibRocketCustomElement* createInstance() {
		return new T();
	}
};

class ofxLibRocketCustomElementHandler: public Rocket::Core::ElementInstancer
{
public:
	~ofxLibRocketCustomElementHandler();

	Rocket::Core::Element* InstanceElement(Rocket::Core::Element* parent, const Rocket::Core::String& tag, const Rocket::Core::XMLAttributes& attributes);
	void Release();
	void ReleaseElement(Rocket::Core::Element* element);

	static ofxLibRocketCustomElementHandler* get();

	template <class T>
	static void addCustomElement(string tagName) {
		ofxLibRocketCustomElementInstancer* instancer = new ofxLibRocketCustomElementInstancerTemplated<T>();
		instancer->tagName = tagName;
		instancers[tagName] = instancer;
		Rocket::Core::Factory::RegisterElementInstancer(tagName.c_str(), get());
	}
private:
	ofxLibRocketCustomElementHandler();

	static ofxLibRocketCustomElementHandler* singleton;
	static map<string, ofxLibRocketCustomElementInstancer*> instancers;
};

class ofxLibRocketCustomElement;

class ofxLibRocketCustomElementWrapper: public Rocket::Core::Element{
public:
	ofxLibRocketCustomElementWrapper(string tagName);
	void OnRender();
	void OnUpdate();
	ofxLibRocketCustomElement* customElement;
};

/******************************************************************************************************************/
class ofxLibRocketCustomElement: public ofxLibRocketElement
{
public:
	ofxLibRocketCustomElement();
	~ofxLibRocketCustomElement();

	virtual void setup() {};
	virtual void update() {};
	virtual void draw() {};

protected:
	void ProcessEvent(Rocket::Core::Event& e);
	void OnUpdate();
	bool isSetup;

private:

	friend class ofxLibRocketCustomElementHandler;
};

#endif // OFXLIBROCKETCUSTOMELEMENT_H
