#ifndef PlatformerScene0_H
#define PlatformerScene0_H

#include "PlatformerScene.h"
#include "framework/Window.h"
#include "framework/Debug.h"

#include "gameobjects/GameObject.h"
#include "gameobjects/Background.h"
#include "gameobjects/Player.h"
#include "gameobjects/Ground1024x32.h"
#include "gameobjects/Crate32x32.h"
#include "gameobjects/Boulder64x64.h"
#include "gameobjects/Ramp64x32LR.h"
#include "gameobjects/SeeSaw.h"
#include "gameObjects/Pulley.h"
#include "gameobjects/Log.h"
#include "framework/KeyboardManager.h"


namespace GAME {
	class PlatformerScene0 : public PlatformerScene  {
	public:
		//Constructor, destructor, C11 deletes
		explicit PlatformerScene0(Window& windowRef, KeyboardManager& keymanRef);
		virtual ~PlatformerScene0();
		PlatformerScene0(const PlatformerScene0&) = delete;
		PlatformerScene0(PlatformerScene0 &&) = delete;
		PlatformerScene0& operator=(const PlatformerScene0 &) = delete;
		PlatformerScene0& operator=(PlatformerScene0 &&) = delete;

		virtual void HandleInput();
		virtual void Update(const float deltaTime);
	protected:
		virtual bool LoadActors();
		virtual bool LoadAssets();
	};
}
#endif