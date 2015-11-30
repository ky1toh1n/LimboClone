#ifndef BLOCK64x32_H
#define BLOCK64x32_H

#include "PhysicsObject.h"
#include "PlatformerScene.h"

namespace GAME {
	class Block64x32 : PhysicsObject {
	public:
		Block64x32(PlatformerScene* scenePtr, const float32 x, const float32 y);
		~Block64x32();

		Block64x32(const Block64x32&) = delete;
		Block64x32(Block64x32 &&) = delete;
		Block64x32& operator=(const Block64x32 &) = delete;
		Block64x32& operator=(Block64x32 &&) = delete;

		GameObject::TYPE GetType() const;
	};
}


#endif