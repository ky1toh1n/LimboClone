#include "Keyboard.h"

using namespace GAME;

Keyboard::Keyboard(){
	// Being called twice?
	// std::cout << "Keyboard Initialized" << std::endl;
}

Keyboard::~Keyboard(){
	Delete();
}

void Keyboard::Initialize() {
	for (int i = 0; i < KEYBOARD_KEYS; i++)
		key[i] = false;
}

void Keyboard::Delete() {
	delete[] key;
}