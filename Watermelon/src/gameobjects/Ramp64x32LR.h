#ifndef Ramp64x32LR_H
#define Ramp64x32LR_H

#include "PhysicsObject.h"
#include "PlatformerScene.h"

namespace GAME {
	class Ramp64x32LR : PhysicsObject {
	public:
		Ramp64x32LR(PlatformerScene* scenePtr, const float32 x, const float32 y);
		~Ramp64x32LR();

		Ramp64x32LR(const Ramp64x32LR&) = delete;
		Ramp64x32LR(Ramp64x32LR &&) = delete;
		Ramp64x32LR& operator=(const Ramp64x32LR &) = delete;
		Ramp64x32LR& operator=(Ramp64x32LR &&) = delete;

		GameObject::TYPE GetType() const;
	};
}


#endif