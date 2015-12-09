#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Vector.h"
#include "Texture.h"
#include "Box2D/Box2D.h"
#include "Debug.h"


using namespace MATH;

namespace GAME {

	class GameObject {


	public:
		enum TYPE {
			NO_CLASS,
			PLAYER,
			GROUND_1024x32,
			CRATE_32x32,
			BOULDER_64x64,
			RAMP
		};


		GameObject(const float32 x = 0, const float32 y = 0);
		virtual ~GameObject();

		GameObject(const GameObject&) = delete;
		GameObject(GameObject &&) = delete;
		GameObject& operator=(const GameObject &) = delete;
		GameObject& operator=(GameObject &&) = delete;
	
	public:
		virtual void SetPosition(const float32 x, const float32 y); // no decimal values on screen pixels
		virtual Vec2 Position() const;
		virtual float32 Width() const;
		virtual float32 Height() const;
		virtual void SetSprite(Texture& spriteRef);
		virtual b2Body* GetBody() const;

		virtual void Update(const float deltaTime);
		virtual void Draw(const int xOffset = 0, const int yOffset = 0, const float scale = 1, SDL_Rect* clip = nullptr,
			const double angle = 0, SDL_Point* center = nullptr,
			const SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE) const;

		virtual void Print() const;

	protected:
		float32 RadiansToDegrees(float32 radians);

// Member Fields
	protected:
		Vec2 position;
		Texture * sprite;
	};
}

#endif