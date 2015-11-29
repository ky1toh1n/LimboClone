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
		virtual void Destroy();
		virtual const b2Body* GetBody();
		virtual void Update(const float deltaTime);
		virtual void Draw(const int xOffset=0, const int yOffset=0) const;

// Member Fields
	protected:
		Vec2 position;
		Texture * sprite;
	};
}

#endif