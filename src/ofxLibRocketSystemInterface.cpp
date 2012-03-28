#include "ofxLibRocketSystemInterface.h"
#include "ofMain.h"


using namespace Rocket::Core;

ofxLibRocketSystemInterface::ofxLibRocketSystemInterface() {
}

ofxLibRocketSystemInterface::~ofxLibRocketSystemInterface() {
}

void ofxLibRocketSystemInterface::ActivateKeyboard() {
}

void ofxLibRocketSystemInterface::DeactivateKeyboard() {
}

float ofxLibRocketSystemInterface::GetElapsedTime() {
	return ofGetElapsedTimef();
}

bool ofxLibRocketSystemInterface::LogMessage(Log::Type type, const String& message) {
	ofLogLevel level = OF_LOG_SILENT;
	switch(type) {
	case Log::LT_ERROR:
		level = OF_LOG_ERROR;
		break;
	case Log::LT_ALWAYS:
		level = OF_LOG_NOTICE;
		break;
	case Log::LT_ASSERT:
		level = OF_LOG_FATAL_ERROR;
		break;
	case Log::LT_WARNING:
		level = OF_LOG_WARNING;
		break;
	case Log::LT_INFO:
		level = OF_LOG_NOTICE;
		break;
	case Log::LT_DEBUG:
		level = OF_LOG_NOTICE;
		break;
	case Log::LT_MAX:
		level = OF_LOG_FATAL_ERROR;
		break;
	}
	ofLog(level, message.CString());
	return true;
}

int ofxLibRocketSystemInterface::TranslateString(String& translated, const String& input) {
	translated = input;
	return 0;
}

void ofxLibRocketSystemInterface::Release()
{
}
