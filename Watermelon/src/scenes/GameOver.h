#ifndef GameOver_H
#define GameOver_H

#include "SDL.h"

#include "Scene.h"

#include "Window.h"
#include "Texture.h"
#include "Music.h"
#include "Debug.h"
#include "KeyboardManager.h"

namespace GAME {
	class GameOver : public Scene {
	public:
		//Constructor, destructor, C11 deletes
		explicit GameOver(class Window& windowRef, class KeyboardManager& keymanRef);
		virtual ~GameOver();
		GameOver(const GameOver&) = delete;
		GameOver(GameOver&&) = delete;
		GameOver& operator = (const GameOver&) = delete;
		GameOver& operator = (GameOver&&) = delete;

		virtual void HandleInput();
		virtual bool OnCreate();
		virtual void Update(const float deltaTime);
		virtual void Render() const;

	protected:
		Texture* backgroundTexture;
	};
}

#endif