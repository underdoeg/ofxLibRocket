#include "ofxLibRocketDocument.h"

using namespace Rocket::Core;

ofxLibRocketDocument::ofxLibRocketDocument(Rocket::Core::ElementDocument* doc)
{
	rocketDocument = doc;
}

ofxLibRocketDocument::~ofxLibRocketDocument()
{
}

ofxLibRocketElement* ofxLibRocketDocument::getElement(string id)
{
	
}

ofxLibRocketSlider* ofxLibRocketDocument::createSlider(string name, float min, float max, float step)
{
	
}

ofxLibRocketSlider* ofxLibRocketDocument::getSlider(string id)
{
	Rocket::Core::Element* el = rocketDocument->GetElementById(id.c_str());
	if(el){
		if(el->GetAttribute<String>("type", "none") ==  "range")
			return new ofxLibRocketSlider(el);
	}
	return NULL;
}

ofxLibRocketButton* ofxLibRocketDocument::getButton(string id)
{
	Rocket::Core::Element* el = rocketDocument->GetElementById(id.c_str());
	cout << el->GetTagName().CString() << endl;
	if(el){
		if(strcmp(el->GetTagName().CString(), "button") == 0)
			return new ofxLibRocketButton(el);
	}
	return NULL;
}

ofxLibRocketTextField* ofxLibRocketDocument::getTextField(string id)
{
	Rocket::Core::Element* el = rocketDocument->GetElementById(id.c_str());
	if(el){
		if(strcmp(el->GetAttribute<String>("type", "none").CString(), "text") == 0)
			return new ofxLibRocketTextField(el);
	}
	return NULL;
}

void ofxLibRocketDocument::hide()
{
	rocketDocument->Hide();
}

void ofxLibRocketDocument::show()
{
	rocketDocument->Show();
}

void ofxLibRocketDocument::toggleVisibility()
{
	if(rocketDocument->IsVisible())
		rocketDocument->Hide();
	else
		rocketDocument->Show();
}