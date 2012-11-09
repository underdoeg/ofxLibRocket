#ifndef OFXLIBROCKETUTILS_H
#define OFXLIBROCKETUTILS_H

#include "ofMain.h"
#include <set>

class ofxLibRocketStringList
{
public:
	void add(std::string key);
	bool contains(std::string key);
	std::set<std::string> list;
};

#endif // OFXLIBROCKETUTILS_H
