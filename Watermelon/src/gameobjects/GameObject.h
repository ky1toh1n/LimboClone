#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Vector.h"
#include "Texture.h"

using namespace MATH;

namespace GAME {
	class GameObject {
	public:
		GameObject(int x = 0, int y = 0);
		virtual ~GameObject();

		GameObject(const GameObject&) = delete;
		GameObject(GameObject &&) = delete;
		GameObject& operator=(const GameObject &) = delete;
		GameObject& operator=(GameObject &&) = delete;
	
	public:
		virtual void SetPosition(int x, int y); // no decimal values on screen pixels
		virtual Vec2 Position() const;
		virtual void SetSprite(Texture& spriteRef);
		virtual void Destroy();
		virtual void Update(const float deltaTime);
		virtual void Draw() const;

// Member Fields
	protected:
		Vec2 position;
		Texture * sprite;
	};
}

#endif