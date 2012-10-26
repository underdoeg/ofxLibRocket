#ifndef VIEW_H
#define VIEW_H

#include "ofxLibRocketCustomElement.h" // Base class: ofxLibRocketCustomElement

class View : public ofxLibRocketCustomElement
{
public:
	
	void setup();
	void draw();
	void update();

	void onMouseClick(int x, int y, int button);
	void onMouseMove(int x, int y);
	void onMouseDrag(int x, int y, int button);

	float rotX;
	float rotY;
	float rotXSpeed;
	float rotYSpeed;
	float scale;
	float scaleSpeed;
};

#endif // VIEW_H
