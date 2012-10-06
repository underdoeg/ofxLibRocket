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
	
	ofxLibRocketSlider* getSlider(string name);
	ofxLibRocketSlider* createSlider(string id, float min=0, float max=1, float step=.01);
private:
	Rocket::Core::ElementDocument* rocketDocument;
};

#endif // OFXLIBROCKETDOCUMENT_H
