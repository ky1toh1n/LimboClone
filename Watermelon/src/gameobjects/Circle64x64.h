#ifndef Circle64x64_H
#define Circle64x64_H

#include "PhysicsObject.h"
#include "PlatformerScene.h"

namespace GAME {
	class Circle64x64 : PhysicsObject {
	public:
		Circle64x64(PlatformerScene* scenePtr, const float32 x, const float32 y);
		~Circle64x64();

		Circle64x64(const Circle64x64&) = delete;
		Circle64x64(Circle64x64 &&) = delete;
		Circle64x64& operator=(const Circle64x64 &) = delete;
		Circle64x64& operator=(Circle64x64 &&) = delete;

		GameObject::TYPE GetType() const;
	};
}


#endif