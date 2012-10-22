#ifndef OFXLIBROCKETDOCUMENT_H
#define OFXLIBROCKETDOCUMENT_H

#include "ofxLibRocketEvents.h"
#include "ofMain.h"
#include "Rocket/Core.h"
#include "ofxLibRocketControls.h"

class ofxLibRocketDocument
{
public:
	ofxLibRocketDocument(Rocket::Core::ElementDocument* doc);
	~ofxLibRocketDocument();
	
	ofxLibRocketSlider* getSlider(string id);
	ofxLibRocketSlider* createSlider(string id, float min=0, float max=1, float step=.01);
	
	ofxLibRocketButton* getButton(string id);
	
	ofxLibRocketTextField* getTextField(string id);
	
	ofxLibRocketElement* getElementById(string id);
	
	template <class T>
	T* getElementById(string id){
		ofxLibRocketElement* el = getElementById(id);
		
		if(el ==  NULL)
			return NULL;
		return static_cast<T*>(el);
	}
	
	ofxLibRocketElementList getElementsByTagName(string tagName);
	ofxLibRocketElement* getElementByRocket(Rocket::Core::Element* rocketElement);
	
	void hide();
	void show();
	void toggleVisibility();
	
	void addElement(ofxLibRocketElement* el);
	
private:
	Rocket::Core::ElementDocument* rocketDocument;
	ofxLibRocketElementList elementList;
	std::map<Rocket::Core::Element*, ofxLibRocketElement*> elementMap;
};

#endif // OFXLIBROCKETDOCUMENT_H
