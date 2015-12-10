#ifndef LOG_H
#define LOG_H

#include "PhysicsObject.h"
#include "PlatformerScene.h"

namespace GAME{
	class Log : public PhysicsObject {
	public:
		Log(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0);
		~Log();

		Log(const Log&) = delete;
		Log(Log &&) = delete;
		Log& operator=(const Log &) = delete;
		Log& operator=(Log &&) = delete;

		void Update(const float deltaTime);
		void Draw(const int xOffset = 0, const int yOffset = 0, const float scale = 1, SDL_Rect* clip = nullptr,
			const double angle = 0, SDL_Point* center = nullptr,
			const SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE) const;


	private:
		float32 angleInDegrees;
	};
}


#endif