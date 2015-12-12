#ifndef PULLEY_H
#define PULLEY_H

#include "scenes/PlatformerScene.h"
#include "Log.h"
#include "Crate32x32.h"
#include "Rope.h"

namespace GAME {
	class Pulley : public PhysicsObject {
	public:
		Pulley(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0);
		~Pulley();

		Pulley(const Pulley&) = delete;
		Pulley(Pulley &&) = delete;
		Pulley& operator=(const Pulley &) = delete;
		Pulley& operator=(Pulley &&) = delete;

		void Update(const float deltaTime);

	private:
		b2PulleyJoint* pulleyJoint;

		/* Revolute Joint Pairs
				0 - leftBody to rope
				1 - leftAnchor to rope
				2 - rightBody to rope
				3 - rightAnchor to rope
		*/
		// b2RevoluteJoint *revoluteJoint[4];

		// GameObject *leftRopeSegments[5];  // for b2Body ropejoints
		// GameObject *rightRopeSegments[5];

		Rope *ropes[2];
		GameObject *anchors[2];
		GameObject *platforms[2];
		float32 xDist = 200; // the x distance btwn the 2 bodies
		float32 length = 300;
	};
}

#endif