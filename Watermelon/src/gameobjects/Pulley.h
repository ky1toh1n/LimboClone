#ifndef PULLEY_H
#define PULLEY_H

#include "scenes/PlatformerScene.h"
#include "Log.h"
#include "Crate32x32.h"

namespace GAME {
	class Pulley : public PhysicsObject {
	public:
		Pulley(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0);
		~Pulley();

		void Update(const float deltaTime);

	private:
		b2PulleyJoint* pulleyJoint;
		b2Body* leftBody;
		b2Body* rightBody;
		float32 xDist = 200; // the x distance btwn the 2 bodies
		float32 length = 300;
	};
}

#endif