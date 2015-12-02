#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "GameObject.h"

namespace GAME {
	class Background : public GameObject {
	public:
		// Might not need this class.. 
		Background(PlatformerScene* scenePtr, const float32 x, const float32 y);
		~Background();

		Background(const Background&) = delete;
		Background(Background &&) = delete;
		Background& operator=(const Background &) = delete;
		Background& operator=(Background &&) = delete;
	};
}

#endif