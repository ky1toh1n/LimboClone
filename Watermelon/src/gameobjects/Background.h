#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "PhysicsObject.h"
#include "PlatformerScene.h"

namespace GAME {
	class Background : public PhysicsObject {
	public:
		Background(PlatformerScene* scenePtr, const float32 x, const float32 y, const OrthographicCamera* cam);
		virtual ~Background();

		Background(const Background&) = delete;
		Background(Background &&) = delete;
		Background& operator=(const Background &) = delete;
		Background& operator=(Background &&) = delete;

		virtual void Update(const float deltaTime);
		virtual void Draw(const int xOffset = 0, const int yOffset = 0, const float scale = 1, SDL_Rect* clip = nullptr,
			const double angle = 0, SDL_Point* center = nullptr,
			const SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE) const;

	protected:
		const OrthographicCamera* camera;
	};
}

#endif