#ifndef KeyboardManager_H
#define KeyboardManager_H
#include "Keyboard.h"

namespace GAME {
	class KeyboardManager : public Keyboard {
	public:
		
		KeyboardManager();
		~KeyboardManager();
		
		KeyboardManager(KeyboardManager&) = delete;
		KeyboardManager(KeyboardManager&&) = delete;
		KeyboardManager operator = (KeyboardManager&) = delete;
		KeyboardManager operator = (KeyboardManager&&) = delete;

		// initialize all boolean values of keyboard to false *CALL THIS IN OnCreate*
		void Initialize();

		// deletes the boolean array inside keyboard and set the pointer to the keyboard to nullptr *Call this in OnDestroy*
		void Delete();

		// Set the key index inside keyboard and set it to true *Call this after your case of ON_CLICK while polling the event inside update function of Scene*
			// example
				/*	case Keyboard::State::KEYDOWN:
						keyboard.OnPress(SDLEvent.type);*/
		void OnPress(const unsigned int& keyCode);

		//Set the key index inside keyboard and set it to false *Call this after your case of OFF_CLICK while polling the event inside update function of scene*
			// example
				/*	case Keyboard::State::KEYUP:
						keyboard.OnRelease(SDLEvent.type);*/
		void OnRelease(const unsigned int& keyCode);

		//return a boolean if the key was pressed or not *Call this when making any scancode call * after OnPress call
			//example
				/*if (keyboard.IsPressed(Keyboard::Key::A))*/
		bool IsPressed(const unsigned int& keyCode);

	private:
		// our Keyboard class , contains our keyboard booleans.
		Keyboard* keyboard;
	};
}
#endif