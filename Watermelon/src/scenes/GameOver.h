#ifndef GameOver_H
#define GameOver_H

#include "SDL.h"

#include "framework/Scene.h"

#include "framework/Window.h"
#include "framework/Texture.h"
#include "framework/Music.h"
#include "framework/Debug.h"
#include "framework/KeyboardManager.h"

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