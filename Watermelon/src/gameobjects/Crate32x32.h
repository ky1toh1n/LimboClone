#ifndef Crate32x32_H
#define Crate32x32_H

#include "PhysicsObject.h"
#include "PlatformerScene.h"

namespace GAME {
	class Crate32x32 : PhysicsObject {
	public:
		Crate32x32(PlatformerScene* scenePtr, const float32 x, const float32 y);
		~Crate32x32();

		Crate32x32(const Crate32x32&) = delete;
		Crate32x32(Crate32x32 &&) = delete;
		Crate32x32& operator=(const Crate32x32 &) = delete;
		Crate32x32& operator=(Crate32x32 &&) = delete;

		GameObject::TYPE GetType() const;
	};
}


#endif