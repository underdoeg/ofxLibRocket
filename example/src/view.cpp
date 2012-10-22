#include "view.h"

void View::setup()
{
	rotX = ofRandom(2000);
	rotY = ofRandom(2000);
	rotXSpeed = ofRandom(0.001, 0.007);
	rotYSpeed = ofRandom(0.001, 0.007);
	scale = ofRandom(2000);
	scaleSpeed = ofRandom(0.001, 0.007);
}

void View::update()
{
	rotX += rotXSpeed;
	rotY += rotYSpeed;
	scale += scaleSpeed;
}

void View::draw()
{
	ofPushView();
	ofViewport(getX(), getY(), getWidth(), getHeight());
	ofSetupScreenPerspective(getWidth(), getHeight());
	ofNoFill();
	ofSetColor(getColor());
	ofPushMatrix();
	ofTranslate(getWidth()*.5, getHeight()*.5, 0);
	ofRotateX(ofNoise(rotX)*360);
	ofRotateY(ofNoise(rotY)*360);
	float s = (ofNoise(scale)-.5)*30;
	ofScale(s, s, s);
	ofBox(200);
	ofPopMatrix();
	ofPopView();
}
