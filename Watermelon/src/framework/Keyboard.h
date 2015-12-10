#ifndef Keyboard_H
#define Keyboard_H
#include <SDL.h>
#include <SDL_scancode.h>
#include "Debug.h"

namespace GAME {

	class Keyboard {
	public:
		// enum of keyboard states that are equal to SDL keyboard states
		enum State : unsigned int {
			KEYDOWN = SDL_KEYDOWN,
			KEYUP = SDL_KEYUP
		};
		// an enum of keys that are equal to SDL scancodes i chose
		enum Key : unsigned int {
			A = SDL_SCANCODE_A,
			D = SDL_SCANCODE_D,
			S = SDL_SCANCODE_S,
			W = SDL_SCANCODE_W,
			SPACE = SDL_SCANCODE_SPACE,
			ESCAPE = SDL_SCANCODE_ESCAPE,
			NUM_1 = SDL_SCANCODE_1,
			LEFT = SDL_SCANCODE_LEFT,
			RIGHT = SDL_SCANCODE_RIGHT,
			UP = SDL_SCANCODE_UP,
			DOWN = SDL_SCANCODE_DOWN,
		};
		//An enum used for assigning specifics to Keyboard::Keys.
		enum Action : unsigned int {
			MOVE_UP,
			MOVE_DOWN,
			MOVE_LEFT,
			MOVE_RIGHT,
			JUMP,
			TO_NEXT_SCREEN, //Used to go from Main Menu -> Level, and Game Over -> Main Menu.
			EXIT_GAME
		};
		// get the number of scan codes from SDL but them into a static const int , going to need it for an array of boolean keys
		static const int KEYBOARD_KEYS = SDL_NUM_SCANCODES;
		
		Keyboard();
		~Keyboard();
		
		Keyboard(Keyboard&) = delete;
		Keyboard(Keyboard&&) = delete;
		Keyboard operator = (Keyboard&) = delete;
		Keyboard operator = (Keyboard&&) = delete;
		
		void Initialize();
		void Delete() ;

		
		friend class KeyboardManager; // with class Keyboard manager as a friend , the manager can touch the keys array.

	private:
		// our private set of keys for the keyboard to check
		bool key[KEYBOARD_KEYS];
	};
}
#endif