#ifndef OFXLIBROCKET_H
#define OFXLIBROCKET_H

#include "ofxLibRocketSystemInterface.h"
#include "ofxLibRocketRenderInterface.h"
#include "Rocket/Core.h"
#include "Rocket/Debugger.h"

class ofxLibRocket {

public:
	ofxLibRocket();
	~ofxLibRocket();

	void setup();
	void update(ofEventArgs& e);
	void update();
	void draw(ofEventArgs& e);
	void draw();

	void keyPressed  (ofKeyEventArgs& e);
	void keyReleased(ofKeyEventArgs& e);
	void mouseMoved(ofMouseEventArgs& e);
	void mouseDragged(ofMouseEventArgs& e);
	void mousePressed(ofMouseEventArgs& e);
	void mouseReleased(ofMouseEventArgs& e);
	void resize(ofResizeEventArgs& e);

	void keyPressed  (int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y );
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);

	void resize(int w, int h);

	void registerOfEvents();
	void unregisterOfEvents();

	void initialiseKeyMap();

	Rocket::Core::Context* context;

private:
	ofxLibRocketRenderInterface renderer;
	ofxLibRocketSystemInterface systemInterface;
};

#endif // OFXLIBROCKET_H
