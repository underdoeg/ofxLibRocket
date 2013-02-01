#include "ofxLibRocketUtils.h"

void ofxLibRocketStringList::add(std::string key)
{
	list.insert(key);
}

bool ofxLibRocketStringList::contains(std::string key)
{
	return list.find(key) != list.end();
}

Rocket::Core::Vector2f toRocket(ofVec2f p)
{
	return Rocket::Core::Vector2f(p.x, p.y);
}
