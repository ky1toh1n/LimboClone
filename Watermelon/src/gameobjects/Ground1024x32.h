#ifndef GROUND1024x32_H
#define GROUND1024x32_H

#include "PhysicsObject.h"
#include "scenes/PlatformerScene.h"

namespace GAME {
	class Ground1024x32 : PhysicsObject {
	public:
		Ground1024x32(PlatformerScene* scenePtr, const float32 x, const float32 y);
		~Ground1024x32();

		Ground1024x32(const Ground1024x32&) = delete;
		Ground1024x32(Ground1024x32 &&) = delete;
		Ground1024x32& operator=(const Ground1024x32 &) = delete;
		Ground1024x32& operator=(Ground1024x32 &&) = delete;

		GameObject::TYPE GetType() const;
	};
}


#endif