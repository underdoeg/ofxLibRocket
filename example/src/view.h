#ifndef VIEW_H
#define VIEW_H

#include "ofxLibRocketCustomElement.h" // Base class: ofxLibRocketCustomElement

class View : public ofxLibRocketCustomElement
{
public:
	View();
	~View();
	
	void setup();
	void draw();
	void update();

	float rotX;
	float rotY;
	float rotXSpeed;
	float rotYSpeed;
	float scale;
	float scaleSpeed;
};

#endif // VIEW_H
