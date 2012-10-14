#ifndef OFXLIBROCKETSYSTEMINTERFACE_H
#define OFXLIBROCKETSYSTEMINTERFACE_H

#include <Rocket/Core/SystemInterface.h>
#include <Rocket/Core/Log.h>
#include <Rocket/Core/Types.h>

class ofxLibRocketSystemInterface: public Rocket::Core::SystemInterface {

	void ActivateKeyboard();
	void DeactivateKeyboard();
	float GetElapsedTime();
	bool LogMessage(Rocket::Core::Log::Type type, const Rocket::Core::String& message);
	void Release();
	int TranslateString(Rocket::Core::String& translated, const Rocket::Core::String& input);

public:
	ofxLibRocketSystemInterface();
	~ofxLibRocketSystemInterface();
};

#endif // OFXLIBROCKETSYSTEMINTERFACE_H
