#include "ofxLibRocketDocument.h"

ofxLibRocketDocument::ofxLibRocketDocument(Rocket::Core::ElementDocument* doc)
{
	rocketDocument = doc;
}

ofxLibRocketDocument::~ofxLibRocketDocument()
{
}

ofxLibRocketSlider* ofxLibRocketDocument::createSlider(string name, float min, float max, float step)
{
	
}

ofxLibRocketSlider* ofxLibRocketDocument::getSlider(string id)
{
	//rocketDocument->GetElementById(id);
}

