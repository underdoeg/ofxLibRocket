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
	
	ofxLibRocketElement* getElement(string id);
	
	void hide();
	void show();
	void toggleVisibility();
	
private:
	Rocket::Core::ElementDocument* rocketDocument;
	map<string, ofxLibRocketElement*> elements;
};

#endif // OFXLIBROCKETDOCUMENT_H
