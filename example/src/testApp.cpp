#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup() {
	libRocket.loadFont("pf_tempesta_seven_condensed.ttf");
	libRocket.setup();
	doc = libRocket.loadDocument("demo.rml");
	ofxLibRocketSlider* slider = doc->getSlider("slider");
	slider->setValue(.7);	
	slider->setFloatPointer(&sliderValue);
	
	ofxLibRocketButton* button = doc->getButton("button");
	button->setBoolPointer(&buttonValue);
	
	ofxLibRocketTextField* text = doc->getTextField("text");
	text->setStringPointer(&textValue);
}

//--------------------------------------------------------------
void testApp::update() {
	cout << textValue << endl;
}

//--------------------------------------------------------------
void testApp::draw() {
	ofRect(10, 10, sliderValue*200, 100);
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
