#include "ofxLibRocketVideo.h"

ofxLibRocketVideo::ofxLibRocketVideo()
{

}
ofxLibRocketVideo::~ofxLibRocketVideo()
{
}

void ofxLibRocketVideo::setup()
{
}

void ofxLibRocketVideo::update()
{
	player.update();
}

void ofxLibRocketVideo::draw()
{
	if(player.isLoaded()) {
		if(getAttributeAsBool("fit")) {
			if(getAttributeAsBool("aspect")) {
				player.draw(0,0);
			} else {
				player.draw(0,0, getWidth(), getHeight());
			}
		} else
			player.draw(0, 0);
	}
}

void ofxLibRocketVideo::onAttributeChange(ofxLibRocketStringList attributes)
{
	if(attributes.contains("src")) {
		player.loadMovie(getAttributeAsString("src"));
	}
	if(attributes.contains("loop")) {
		if(getAttributeAsBool("loop"))
			player.setLoopState(OF_LOOP_NORMAL);
		else
			player.setLoopState(OF_LOOP_NONE);
	}
	if(attributes.contains("play")) {
		if(getAttributeAsBool("play"))
			player.play();
		else
			player.setPaused(true);
	}
}
