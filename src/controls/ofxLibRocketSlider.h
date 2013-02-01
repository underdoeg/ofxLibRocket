#ifndef OFXLIBROCKETSLIDER_H
#define OFXLIBROCKETSLIDER_H

#include "ofxLibRocketCustomElement.h" // Base class: ofxLibRocketCustomElement

class ofxLibRocketSliderEventArgs: public ofxLibRocketEventArgs{
	
};

class ofxLibRocketSlider : public ofxLibRocketCustomElement
{
public:
	ofxLibRocketSlider();
	~ofxLibRocketSlider();

	virtual void setup();
	virtual void update();
	virtual void draw();
	
	void onMousePress(int x, int y, int button);
	void onMouseDrag(int x, int y, int button);
	void onMouseUp(int x, int y, int button);

private:
	ofxLibRocketElement* handler;
};

#endif // OFXLIBROCKETSLIDER_H
