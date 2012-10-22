#include "ofxLibRocketDocument.h"

using namespace Rocket::Core;

ofxLibRocketDocument::ofxLibRocketDocument(Rocket::Core::ElementDocument* doc)
{
	rocketDocument = doc;
}

ofxLibRocketDocument::~ofxLibRocketDocument()
{
}

ofxLibRocketElement* ofxLibRocketDocument::getElementById(string id)
{
	Element* rocketElement = rocketDocument->GetElementById(id.c_str());
	if(rocketElement == NULL)
		return NULL;
	return getElementByRocket(rocketElement);
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

void ofxLibRocketDocument::addElement(ofxLibRocketElement* el)
{
	elementList.push_back(el);
	elementMap[el->getRocketElement()] = el;
}

ofxLibRocketElementList ofxLibRocketDocument::getElementsByTagName(string tagName)
{
	ofxLibRocketElementList ret;
	ElementList list;
	rocketDocument->GetElementsByTagName(list, tagName.c_str());
	ElementList::iterator it = list.begin();
	while(it != list.end()){
		ret.push_back(getElementByRocket(*it));
		it++;
	}
	return ret;
}

ofxLibRocketElement* ofxLibRocketDocument::getElementByRocket(Rocket::Core::Element* rocketElement)
{
	return elementMap[rocketElement];
}
