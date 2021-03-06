#ifndef MainMenu_H
#define MainMenu_H

#include "SDL.h"

#include "framework/Scene.h"

#include "framework/Window.h"
#include "framework/Texture.h"
#include "framework/Music.h"
#include "framework/Debug.h"
#include "framework/KeyboardManager.h"

namespace GAME {
	class MainMenu : public Scene {
	public:
		//Constructor, destructor, C11 deletes
		explicit MainMenu(class Window& windowRef, class KeyboardManager& keymanRef);
		virtual ~MainMenu();
		MainMenu(const MainMenu&) = delete;
		MainMenu(MainMenu&&) = delete;
		MainMenu& operator = (const MainMenu&) = delete;
		MainMenu& operator = (MainMenu&&) = delete;

		virtual void HandleInput();
		virtual bool OnCreate();
		virtual void Update(const float deltaTime);
		virtual void Render() const;

	protected:
		Texture* backgroundTexture;
	};
}

#endif