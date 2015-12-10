#include "Keyboard.h"

using namespace GAME;

Keyboard::Keyboard(){
	// Being called twice?
	// std::cout << "Keyboard Initialized" << std::endl;
}

Keyboard::~Keyboard(){
}

void Keyboard::Initialize() {
	for (int i = 0; i < KEYBOARD_KEYS; i++)
		key[i] = false;
}