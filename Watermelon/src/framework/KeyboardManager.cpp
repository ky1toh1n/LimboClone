#include "KeyboardManager.h"

using namespace GAME;

KeyboardManager::KeyboardManager():keyboard(new Keyboard()) {

}

KeyboardManager::~KeyboardManager(){
	Delete();
}

void KeyboardManager::Initialize() {
	// initialize all keys to false
	keyboard->Initialize();
}

void KeyboardManager::Delete() {
	// delete the array of keys in the keyboard;
	keyboard->Delete();
	keyboard = nullptr;
}

void  KeyboardManager::OnPress(const unsigned int& keyCode) {
	keyboard->key[keyCode] = true;
}

void  KeyboardManager::OnRelease(const unsigned int& keyCode) {
	keyboard->key[keyCode] = false;
}

bool  KeyboardManager::IsPressed(const unsigned int& keyCode) {
	bool keyIsPressed = keyboard->key[keyCode];
	if (keyIsPressed) {
		// return the key is pressed
		// std::cout << keyCode << std::endl;
		return keyIsPressed;
	}else{
		return false;
	}
}