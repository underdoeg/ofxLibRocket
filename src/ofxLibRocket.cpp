#include "ofxLibRocket.h"

using namespace Rocket::Core;

static const int KEYMAP_SIZE = 256;
static Rocket::Core::Input::KeyIdentifier key_identifier_map[KEYMAP_SIZE];

ofxLibRocket::ofxLibRocket()
{
}

ofxLibRocket::~ofxLibRocket()
{
}

void ofxLibRocket::setup()
{
	Rocket::Core::SetRenderInterface(&renderer);
	Rocket::Core::SetSystemInterface(&systemInterface);

	Rocket::Core::Initialise();

	context = Rocket::Core::CreateContext("main", Rocket::Core::Vector2i(ofGetWidth(), ofGetHeight()));
	if (context == NULL) {
		Rocket::Core::Shutdown();
		ofExit();
	}

	Rocket::Debugger::Initialise(context);

	Rocket::Core::ElementDocument* document = context->LoadDocument(ofToDataPath("demo.rml").c_str());
	if (document != NULL)
	{
		document->Show();
		document->RemoveReference();
	}

	registerOfEvents();
}

void ofxLibRocket::update()
{
	context->Update();
}

void ofxLibRocket::draw()
{
	context->Render();
}

void ofxLibRocket::mouseMoved(int x, int y)
{
	context->ProcessMouseMove(x, y, ofGetKeyPressed());
}

void ofxLibRocket::mousePressed(int x, int y, int button)
{
	if(button == 3)
		context->ProcessMouseWheel(-1, ofGetKeyPressed());
	else if(button == 4)
		context->ProcessMouseWheel(1, ofGetKeyPressed());
	else
		context->ProcessMouseButtonDown(button, ofGetKeyPressed());
}

void ofxLibRocket::mouseDragged(int x, int y, int button)
{
	context->ProcessMouseMove(x, y, ofGetKeyPressed());
}

void ofxLibRocket::mouseReleased(int x, int y, int button)
{
	context->ProcessMouseButtonUp(button, ofGetKeyPressed());
}

void ofxLibRocket::keyPressed(int key)
{
	Rocket::Core::Input::KeyIdentifier key_identifier = key_identifier_map[key];
	context->ProcessKeyDown(key_identifier, ofGetKeyPressed());
}

void ofxLibRocket::keyReleased(int key)
{
	Rocket::Core::Input::KeyIdentifier key_identifier = key_identifier_map[key];
	context->ProcessKeyUp(key_identifier, ofGetKeyPressed());
}

void ofxLibRocket::resize(int w, int h)
{
	context->SetDimensions(Vector2i(w, h));
}

void ofxLibRocket::registerOfEvents()
{
	ofAddListener(ofEvents().update, this, &ofxLibRocket::update);
	ofAddListener(ofEvents().draw, this, &ofxLibRocket::draw);
	ofAddListener(ofEvents().keyPressed, this, &ofxLibRocket::keyPressed);
	ofAddListener(ofEvents().keyReleased, this, &ofxLibRocket::keyReleased);
	ofAddListener(ofEvents().mouseMoved, this, &ofxLibRocket::mouseMoved);
	ofAddListener(ofEvents().mousePressed, this, &ofxLibRocket::mousePressed);
	ofAddListener(ofEvents().mouseDragged, this, &ofxLibRocket::mouseDragged);
	ofAddListener(ofEvents().mouseReleased, this, &ofxLibRocket::mouseReleased);
	ofAddListener(ofEvents().windowResized, this, &ofxLibRocket::resize);
}

void ofxLibRocket::unregisterOfEvents()
{
	ofRemoveListener(ofEvents().update, this, &ofxLibRocket::update);
	ofRemoveListener(ofEvents().draw, this, &ofxLibRocket::draw);
	ofRemoveListener(ofEvents().keyPressed, this, &ofxLibRocket::keyPressed);
	ofRemoveListener(ofEvents().keyReleased, this, &ofxLibRocket::keyReleased);
	ofRemoveListener(ofEvents().mouseMoved, this, &ofxLibRocket::mouseMoved);
	ofRemoveListener(ofEvents().mousePressed, this, &ofxLibRocket::mousePressed);
	ofRemoveListener(ofEvents().mouseDragged, this, &ofxLibRocket::mouseDragged);
	ofRemoveListener(ofEvents().mouseReleased, this, &ofxLibRocket::mouseReleased);
	ofAddListener(ofEvents().windowResized, this, &ofxLibRocket::resize);
}

void ofxLibRocket::draw(ofEventArgs& e)
{
	draw();
}

void ofxLibRocket::update(ofEventArgs& e)
{
	update();
}

void ofxLibRocket::keyPressed(ofKeyEventArgs& e)
{
	keyPressed(e.key);
}

void ofxLibRocket::keyReleased(ofKeyEventArgs& e)
{
	keyReleased(e.key);
}


void ofxLibRocket::mouseDragged(ofMouseEventArgs& e)
{
	mouseDragged(e.x, e.y, e.button);
}

void ofxLibRocket::mouseMoved(ofMouseEventArgs& e)
{
	mouseMoved(e.x, e.y);
}

void ofxLibRocket::mousePressed(ofMouseEventArgs& e)
{
	mousePressed(e.x, e.y, e.button);
}

void ofxLibRocket::mouseReleased(ofMouseEventArgs& e)
{
	mouseReleased(e.x, e.y, e.button);
}

void ofxLibRocket::resize(ofResizeEventArgs& e)
{
	resize(e.width, e.height);
}


void ofxLibRocket::initialiseKeyMap(){
	memset(key_identifier_map, sizeof(key_identifier_map), 0);

	key_identifier_map[0x00] = Rocket::Core::Input::KI_A;
	key_identifier_map[0x01] = Rocket::Core::Input::KI_S;
	key_identifier_map[0x02] = Rocket::Core::Input::KI_D;
	key_identifier_map[0x03] = Rocket::Core::Input::KI_F;
	key_identifier_map[0x04] = Rocket::Core::Input::KI_H;
	key_identifier_map[0x05] = Rocket::Core::Input::KI_G;
	key_identifier_map[0x06] = Rocket::Core::Input::KI_Z;
	key_identifier_map[0x07] = Rocket::Core::Input::KI_X;
	key_identifier_map[0x08] = Rocket::Core::Input::KI_C;
	key_identifier_map[0x09] = Rocket::Core::Input::KI_V;
	key_identifier_map[0x0B] = Rocket::Core::Input::KI_B;
	key_identifier_map[0x0C] = Rocket::Core::Input::KI_Q;
	key_identifier_map[0x0D] = Rocket::Core::Input::KI_W;
	key_identifier_map[0x0E] = Rocket::Core::Input::KI_E;
	key_identifier_map[0x0F] = Rocket::Core::Input::KI_R;
	key_identifier_map[0x10] = Rocket::Core::Input::KI_Y;
	key_identifier_map[0x11] = Rocket::Core::Input::KI_T;
	key_identifier_map[0x12] = Rocket::Core::Input::KI_1;
	key_identifier_map[0x13] = Rocket::Core::Input::KI_2;
	key_identifier_map[0x14] = Rocket::Core::Input::KI_3;
	key_identifier_map[0x15] = Rocket::Core::Input::KI_4;
	key_identifier_map[0x16] = Rocket::Core::Input::KI_6;
	key_identifier_map[0x17] = Rocket::Core::Input::KI_5;
	key_identifier_map[0x18] = Rocket::Core::Input::KI_OEM_PLUS;
	key_identifier_map[0x19] = Rocket::Core::Input::KI_9;
	key_identifier_map[0x1A] = Rocket::Core::Input::KI_7;
	key_identifier_map[0x1B] = Rocket::Core::Input::KI_OEM_MINUS;
	key_identifier_map[0x1C] = Rocket::Core::Input::KI_8;
	key_identifier_map[0x1D] = Rocket::Core::Input::KI_0;
	key_identifier_map[0x1E] = Rocket::Core::Input::KI_OEM_6;
	key_identifier_map[0x1F] = Rocket::Core::Input::KI_O;
	key_identifier_map[0x20] = Rocket::Core::Input::KI_U;
	key_identifier_map[0x21] = Rocket::Core::Input::KI_OEM_4;
	key_identifier_map[0x22] = Rocket::Core::Input::KI_I;
	key_identifier_map[0x23] = Rocket::Core::Input::KI_P;
	key_identifier_map[0x24] = Rocket::Core::Input::KI_RETURN;
	key_identifier_map[0x25] = Rocket::Core::Input::KI_L;
	key_identifier_map[0x26] = Rocket::Core::Input::KI_J;
	key_identifier_map[0x27] = Rocket::Core::Input::KI_OEM_7;
	key_identifier_map[0x28] = Rocket::Core::Input::KI_K;
	key_identifier_map[0x29] = Rocket::Core::Input::KI_OEM_1;
	key_identifier_map[0x2A] = Rocket::Core::Input::KI_OEM_5;
	key_identifier_map[0x2B] = Rocket::Core::Input::KI_OEM_COMMA;
	key_identifier_map[0x2C] = Rocket::Core::Input::KI_OEM_2;
	key_identifier_map[0x2D] = Rocket::Core::Input::KI_N;
	key_identifier_map[0x2E] = Rocket::Core::Input::KI_M;
	key_identifier_map[0x2F] = Rocket::Core::Input::KI_OEM_PERIOD;
	key_identifier_map[0x30] = Rocket::Core::Input::KI_TAB;
	key_identifier_map[0x31] = Rocket::Core::Input::KI_SPACE;
	key_identifier_map[0x32] = Rocket::Core::Input::KI_OEM_3;
	key_identifier_map[0x33] = Rocket::Core::Input::KI_BACK;
	key_identifier_map[0x35] = Rocket::Core::Input::KI_ESCAPE;
	key_identifier_map[0x37] = Rocket::Core::Input::KI_LMETA;
	key_identifier_map[0x38] = Rocket::Core::Input::KI_LSHIFT;
	key_identifier_map[0x39] = Rocket::Core::Input::KI_CAPITAL;
	key_identifier_map[0x3A] = Rocket::Core::Input::KI_LMENU;
	key_identifier_map[0x3B] = Rocket::Core::Input::KI_LCONTROL;
	key_identifier_map[0x41] = Rocket::Core::Input::KI_DECIMAL;
	key_identifier_map[0x43] = Rocket::Core::Input::KI_MULTIPLY;
	key_identifier_map[0x45] = Rocket::Core::Input::KI_ADD;
	key_identifier_map[0x4B] = Rocket::Core::Input::KI_DIVIDE;
	key_identifier_map[0x4C] = Rocket::Core::Input::KI_NUMPADENTER;
	key_identifier_map[0x4E] = Rocket::Core::Input::KI_SUBTRACT;
	key_identifier_map[0x51] = Rocket::Core::Input::KI_OEM_PLUS;
	key_identifier_map[0x52] = Rocket::Core::Input::KI_NUMPAD0;
	key_identifier_map[0x53] = Rocket::Core::Input::KI_NUMPAD1;
	key_identifier_map[0x54] = Rocket::Core::Input::KI_NUMPAD2;
	key_identifier_map[0x55] = Rocket::Core::Input::KI_NUMPAD3;
	key_identifier_map[0x56] = Rocket::Core::Input::KI_NUMPAD4;
	key_identifier_map[0x57] = Rocket::Core::Input::KI_NUMPAD5;
	key_identifier_map[0x58] = Rocket::Core::Input::KI_NUMPAD6;
	key_identifier_map[0x59] = Rocket::Core::Input::KI_NUMPAD7;
	key_identifier_map[0x5B] = Rocket::Core::Input::KI_NUMPAD8;
	key_identifier_map[0x5C] = Rocket::Core::Input::KI_NUMPAD9;
	key_identifier_map[0x60] = Rocket::Core::Input::KI_F5;
	key_identifier_map[0x61] = Rocket::Core::Input::KI_F6;
	key_identifier_map[0x62] = Rocket::Core::Input::KI_F7;
	key_identifier_map[0x63] = Rocket::Core::Input::KI_F3;
	key_identifier_map[0x64] = Rocket::Core::Input::KI_F8;
	key_identifier_map[0x65] = Rocket::Core::Input::KI_F9;
	key_identifier_map[0x67] = Rocket::Core::Input::KI_F11;
	key_identifier_map[0x69] = Rocket::Core::Input::KI_F13;
	key_identifier_map[0x6B] = Rocket::Core::Input::KI_F14;
	key_identifier_map[0x6D] = Rocket::Core::Input::KI_F10;
	key_identifier_map[0x6F] = Rocket::Core::Input::KI_F12;
	key_identifier_map[0x71] = Rocket::Core::Input::KI_F15;
	key_identifier_map[0x73] = Rocket::Core::Input::KI_HOME;
	key_identifier_map[0x74] = Rocket::Core::Input::KI_PRIOR;
	key_identifier_map[0x75] = Rocket::Core::Input::KI_DELETE;
	key_identifier_map[0x76] = Rocket::Core::Input::KI_F4;
	key_identifier_map[0x77] = Rocket::Core::Input::KI_END;
	key_identifier_map[0x78] = Rocket::Core::Input::KI_F2;
	key_identifier_map[0x79] = Rocket::Core::Input::KI_NEXT;
	key_identifier_map[0x7A] = Rocket::Core::Input::KI_F1;
	key_identifier_map[0x7B] = Rocket::Core::Input::KI_LEFT;
	key_identifier_map[0x7C] = Rocket::Core::Input::KI_RIGHT;
	key_identifier_map[0x7D] = Rocket::Core::Input::KI_DOWN;
	key_identifier_map[0x7E] = Rocket::Core::Input::KI_UP;
}
