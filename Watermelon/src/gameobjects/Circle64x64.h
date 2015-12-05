#ifndef Circle64x64_H
#define Circle64x64_H

#include "PhysicsObject.h"
#include "PlatformerScene.h"

namespace GAME {
	class Circle64x64 : public PhysicsObject {
	public:
		Circle64x64(PlatformerScene* scenePtr, const float32 x, const float32 y);
		~Circle64x64();

		Circle64x64(const Circle64x64&) = delete;
		Circle64x64(Circle64x64 &&) = delete;
		Circle64x64& operator=(const Circle64x64 &) = delete;
		Circle64x64& operator=(Circle64x64 &&) = delete;

		GameObject::TYPE GetType() const;

		void Update(const float deltaTime);
		void Draw(const int xOffset = 0, const int yOffset = 0, const float scale = 1, SDL_Rect* clip = nullptr,
			const double angle = 0, SDL_Point* center = nullptr,
			const SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE) const;

	private:
		float32 angleInDegrees;
	};
}


#endif