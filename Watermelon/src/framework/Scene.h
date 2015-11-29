#ifndef SCENE_H
#define SCENE_H

#include "SDL.h"

#include "Window.h"
#include "Texture.h"
#include "Music.h"
#include "Debug.h"

namespace GAME {
	
	/*
	An abstract class used as the basis of any Scene.
	*/
	class Scene {
	public:
		//Constructor, destructor, C11 deletes
		explicit Scene(class Window& windowRef, class KeyboardManager& keymanRef);
		virtual ~Scene();
		Scene(const Scene&) = delete;
		Scene(Scene&&) = delete;
		Scene& operator = (const Scene&) = delete;
		Scene& operator = (Scene&&) = delete;

		//Abstract functions
		virtual bool OnCreate() = 0;
		virtual void HandleInput() = 0;
		virtual void Update(const float deltaTime) = 0;
		virtual void Render() const = 0;

	protected:
		Music* backgroundMusic;
		KeyboardManager* keyboardManager;
		Window* windowPtr;
	};
}

#endif