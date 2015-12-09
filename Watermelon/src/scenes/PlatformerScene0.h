#ifndef PlatformerScene0_H
#define PlatformerScene0_H

#include "PlatformerScene.h"
#include "Window.h"
#include "Debug.h"

#include "GameObject.h"
#include "Background.h"
#include "Player.h"
#include "Ground1024x32.h"
#include "Crate32x32.h"
#include "Boulder64x64.h"
#include "Ramp64x32LR.h"
#include "KeyboardManager.h"

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
	protected:
		virtual bool LoadActors();
		virtual bool LoadAssets();
	};
}
#endif