#include "ofxLibRocketSlider.h"

ofxLibRocketSlider::ofxLibRocketSlider()
{
}

ofxLibRocketSlider::~ofxLibRocketSlider()
{
}

void ofxLibRocketSlider::setup()
{
	handler = createElement("handler");
	handler->setText("0");
}

void ofxLibRocketSlider::update()
{
	
}

void ofxLibRocketSlider::draw()
{
}

void ofxLibRocketSlider::onMousePress(int x, int y, int button)
{
}

void ofxLibRocketSlider::onMouseDrag(int x, int y, int button)
{
	handler->setPosition(20, 0);
}

void ofxLibRocketSlider::onMouseUp(int x, int y, int button)
{
}
