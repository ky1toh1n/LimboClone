#include "KeyboardManager.h"

using namespace GAME;

KeyboardManager::KeyboardManager():keyboard(new Keyboard()) {

}

KeyboardManager::~KeyboardManager(){
	delete keyboard;
	keyboard = nullptr;
}

void KeyboardManager::Initialize() {
	// initialize all keys to false
	keyboard->Initialize();
}
void KeyboardManager::OnPress(const unsigned int& keyCode) {
	keyboard->key[keyCode] = true;
}

void KeyboardManager::OnRelease(const unsigned int& keyCode) {
	keyboard->key[keyCode] = false;
}

bool KeyboardManager::IsPressed(const unsigned int& keyCode) {
	bool keyIsPressed = keyboard->key[keyCode];
	if (keyIsPressed) {
		// return the key is pressed
		// std::cout << keyCode << std::endl;
		return keyIsPressed;
	}else{
		return false;
	}
}

bool KeyboardManager::IsPressed(const Action action) {
	switch (action){
		case MOVE_UP:
			return IsPressed(W) || IsPressed(UP);
			break;
		case MOVE_DOWN:
			return IsPressed(S) || IsPressed(DOWN);
			break;
		case MOVE_LEFT:
			return IsPressed(A) || IsPressed(LEFT);
			break;
		case MOVE_RIGHT:
			return IsPressed(D) || IsPressed(RIGHT);
			break;
		case JUMP:
			return IsPressed(SPACE);
			break;
		case EXIT_GAME:
			return IsPressed(NUM_1);
			break;
		case TO_NEXT_SCREEN:
			return IsPressed(ESCAPE);
			break;
		default:
			Debug::Log(EMessageType::FATAL_ERROR, "Action is unhandled! " + action, __FILENAME__, __LINE__);
			throw action;
			break;
	}
}