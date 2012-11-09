#ifndef OFXLIBROCKETVIDEO_H
#define OFXLIBROCKETVIDEO_H

#include "ofxLibRocketCustomElement.h"

class ofxLibRocketVideo: public ofxLibRocketCustomElement
{
public:
	ofxLibRocketVideo();
	~ofxLibRocketVideo();
	
	void setup();
	void update();
	void draw();
	
	void onAttributeChange(ofxLibRocketStringList attribute);
	
	ofVideoPlayer player;
};

#endif // OFXLIBROCKETVIDEO_H
