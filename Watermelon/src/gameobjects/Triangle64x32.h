#ifndef Triangle64x32_H
#define Triangle64x32_H

#include "PhysicsObject.h"
#include "PlatformerScene.h"

namespace GAME {
	class Triangle64x32 : PhysicsObject {
	public:
		Triangle64x32(PlatformerScene* scenePtr, const float32 x, const float32 y);
		~Triangle64x32();

		Triangle64x32(const Triangle64x32&) = delete;
		Triangle64x32(Triangle64x32 &&) = delete;
		Triangle64x32& operator=(const Triangle64x32 &) = delete;
		Triangle64x32& operator=(Triangle64x32 &&) = delete;

		GameObject::TYPE GetType() const;
	};
}


#endif