#ifndef OFXLIBROCKETUTILS_H
#define OFXLIBROCKETUTILS_H

#include "ofMain.h"
#include "Rocket/Core.h"
#include <set>

class ofxLibRocketStringList
{
public:
	void add(std::string key);
	bool contains(std::string key);
	std::set<std::string> list;
};

Rocket::Core::Vector2f toRocket(ofVec2f);

#endif // OFXLIBROCKETUTILS_H
