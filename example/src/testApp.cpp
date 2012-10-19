#include "view.h"
#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	ofSetFrameRate(60);
	
	//you have to load the fonts before calling setup
	libRocket.loadFont("pf_tempesta_seven_condensed.ttf");
	libRocket.setup();
	
	//custom elements must be added before loading a document
	libRocket.addCustomElement<View>("view");
	
	//load the demo document
	doc = libRocket.loadDocument("demo.rml");
	
	//attach events to elements
	ofAddListener(doc->getButton("toggleDebugger")->eventChange, this, &testApp::toggleDebugger);
	
	
}

//--------------------------------------------------------------
void testApp::update() {
}

//--------------------------------------------------------------
void testApp::draw() {
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo) {

}

void testApp::toggleDebugger(ofxLibRocketBoolEventArgs& args)
{
	if(args.value)
		libRocket.showDebugger();
	else
		libRocket.hideDebugger();
}
