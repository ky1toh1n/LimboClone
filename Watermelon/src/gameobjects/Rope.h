#ifndef ROPE_H
#define ROPE_H

#include "scenes/PlatformerScene.h"

namespace GAME {
	class Rope : PhysicsObject {
	public:
		Rope(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0);
		virtual ~Rope();

		Rope(const Rope&) = delete;
		Rope(Rope &&) = delete;
		Rope& operator=(const Rope &) = delete;
		Rope& operator=(Rope &&) = delete;

		void SetEnd(const b2Vec2& endPos);


		void Update(const float deltaTime);
		void Draw(const int xOffset = 0, const int yOffset = 0, const float scale = 1, SDL_Rect* clip = nullptr,
			const double angle = 0, SDL_Point* center = nullptr,
			const SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE) const;

	private:
		const b2Vec2* startPos;
		const b2Vec2* endPos;
		float32 angleInDegrees;
		
	};
}

#endif