#ifndef OFXLIBROCKETCUSTOMELEMENT_H
#define OFXLIBROCKETCUSTOMELEMENT_H

#include "ofxLibRocketElement.h" // Base class: ofxLibRocketElement

class ofxLibRocketCustomElement;

/*template <class T>
T* ofxLibRocketCreateCustomElement(string tagName){
	return new T(tagName.c_str());
}*/

class ofxLibRocketCustomElementInstancer{
public:
	virtual ofxLibRocketCustomElement* createInstance() = 0;
	string tagName;
};

template <class T>
class ofxLibRocketCustomElementInstancerTemplated: public ofxLibRocketCustomElementInstancer
{
public:
	ofxLibRocketCustomElement* createInstance(){
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

/******************************************************************************************************************/
class ofxLibRocketCustomElement
{
public:
	ofxLibRocketCustomElement();
	~ofxLibRocketCustomElement();

	virtual void setup() {};
	virtual void draw() {};
	virtual void onMouseMove(int x, int y) {};
	virtual void onMousePress(int x, int y, int button) {};
	virtual void onMouseUp(int x, int y, int button) {};
	virtual void onMouseDrag(int x, int y, int button) {};
	virtual void onMouseEnter(int x, int y) {};
	
	
	virtual Rocket::Core::Element* createRocketElement(string tagName);
	void setRootElement(ofxLibRocketElement* el);
protected:
	void ProcessEvent(Rocket::Core::Event& e);
	void OnUpdate();
	bool isSetup;
	ofxLibRocketElement* rootElement;
};

#endif // OFXLIBROCKETCUSTOMELEMENT_H
