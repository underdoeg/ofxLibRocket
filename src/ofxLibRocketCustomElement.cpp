#include "ofxLibRocket.h"
#include "ofxLibRocketDocument.h"
#include "ofxLibRocketCustomElement.h"

using namespace Rocket::Core;

ofxLibRocketCustomElementWrapper::ofxLibRocketCustomElementWrapper(string tagName):Element(tagName.c_str())
{
	customElement = NULL;
}

void ofxLibRocketCustomElementWrapper::OnUpdate()
{
	if(customElement)
		customElement->update();
}

void ofxLibRocketCustomElementWrapper::OnRender()
{
	if(customElement)
		customElement->drawWrapper();
}

void ofxLibRocketCustomElementWrapper::OnAttributeChange(const Rocket::Core::AttributeNameList& changed_attributes)
{
	if(customElement)
		customElement->OnAttributeChange(changed_attributes);
}

/******************************************************************************************************************************************************************************/

map<string, ofxLibRocketCustomElementInstancer*> ofxLibRocketCustomElementHandler::instancers;
ofxLibRocketCustomElementHandler* ofxLibRocketCustomElementHandler::singleton = NULL;

ofxLibRocketCustomElementHandler::ofxLibRocketCustomElementHandler()
{
}

ofxLibRocketCustomElementHandler::~ofxLibRocketCustomElementHandler()
{
}

Rocket::Core::Element* ofxLibRocketCustomElementHandler::InstanceElement(Rocket::Core::Element* parent, const Rocket::Core::String& tag, const Rocket::Core::XMLAttributes& attributes)
{
	if(parent == NULL)
		return NULL;
	if(instancers.find(tag.CString()) != instancers.end()) {
		ofxLibRocketDocument* doc = ofxLibRocket::getDocumentFromRocket(parent->GetOwnerDocument());
		ofxLibRocketCustomElementWrapper* elRet = new ofxLibRocketCustomElementWrapper(tag.CString());
		ofxLibRocketCustomElement* el = instancers[tag.CString()]->createInstance();
		el->setRocketElement(elRet);

		if(doc)
			doc->addElement(el);

		elRet->customElement = el;
		el->setup();
		return elRet;
	}
	return NULL; //shouldn't happen
}

void ofxLibRocketCustomElementHandler::Release()
{
}

void ofxLibRocketCustomElementHandler::ReleaseElement(Rocket::Core::Element* element)
{

}

ofxLibRocketCustomElementHandler* ofxLibRocketCustomElementHandler::get()
{
	if(singleton == NULL)
		singleton = new ofxLibRocketCustomElementHandler();
	return singleton;
}

/**********************************************************************************************************************************************************/
/* OFX_LIB_ROCKET_CUSTOM_ELEMENT 																														  */
/**********************************************************************************************************************************************************/

ofxLibRocketCustomElement::ofxLibRocketCustomElement()
{
	isSetup = false;
	addListener(this);
}

ofxLibRocketCustomElement::~ofxLibRocketCustomElement()
{

}

void ofxLibRocketCustomElement::OnUpdate()
{
	if(!isSetup) {
		setup();
		isSetup = true;
	}
}

void ofxLibRocketCustomElement::OnAttributeChange(const Rocket::Core::AttributeNameList& changed_attributes)
{
	Rocket::Core::AttributeNameList::iterator it = changed_attributes.begin();
	static ofxLibRocketStringListEventArgs args;
	args.element = this;
	while(it != changed_attributes.end()) {
		args.value.add((*it).CString());
		it++;
	}
	ofNotifyEvent(eventAttributeChange, args);
}

void ofxLibRocketCustomElement::drawWrapper()
{
	ofPushMatrix();
	ofTranslate(getPosition());
	draw();
	ofPopMatrix();
}