#ifndef SEESAW_H
#define SEESAW_H

#include "PhysicsObject.h"
#include "scenes/PlatformerScene.h"
#include "Log.h"

namespace GAME{
	class SeeSaw : public PhysicsObject {
	public:
		SeeSaw(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0);
		virtual ~SeeSaw();

		SeeSaw(const SeeSaw&) = delete;
		SeeSaw(SeeSaw &&) = delete;
		SeeSaw& operator=(const SeeSaw &) = delete;
		SeeSaw& operator=(SeeSaw &&) = delete;


	private:
		b2Joint* joint;

	};
}


#endif