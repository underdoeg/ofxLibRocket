#include "ofxLibRocketUtils.h"

void ofxLibRocketStringList::add(std::string key)
{
	list.insert(key);
}

bool ofxLibRocketStringList::contains(std::string key)
{
	return list.find(key) != list.end();
}
