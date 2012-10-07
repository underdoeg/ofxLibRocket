#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	libRocket.loadFont("pf_tempesta_seven_condensed.ttf");
	libRocket.setup();
	doc = libRocket.loadDocument("demo.rml");
	ofxLibRocketSlider* slider = doc->getSlider("slider");
	slider->setFloatPointer(&sliderValue);
}

//--------------------------------------------------------------
void testApp::update() {
	cout << sliderValue << endl;
}

//--------------------------------------------------------------
void testApp::draw() {
	ofEnableAlphaBlending();
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
