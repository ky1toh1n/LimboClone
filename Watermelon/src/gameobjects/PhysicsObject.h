#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include "GameObject.h"
#include "ContactListener.h"
#include "Box2D/Box2D.h"
#include "WorldManager.h"


namespace GAME {
	class PhysicsObject : public GameObject {
	public:
		PhysicsObject(const float32 x = 0, const float32 y = 0);
		virtual ~PhysicsObject();

		PhysicsObject(const PhysicsObject&) = delete;
		PhysicsObject(PhysicsObject &&) = delete;
		PhysicsObject& operator=(const PhysicsObject &) = delete;
		PhysicsObject& operator=(PhysicsObject &&) = delete;

		virtual void SetBody(b2Body& bodyRef);
		virtual const b2Body* GetBody();
		virtual void Update(const float deltaTime);
		virtual void Draw(const int xOffset=0, const int yOffset=0) const;

	public:
		b2Body* body;
	};
}


#endif