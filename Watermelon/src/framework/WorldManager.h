#ifndef WorldManager_H
#define WorldManager_H

#include "Debug.h"
#include "ContactListener.h"
#include "Box2D/Box2D.h"

//Responsible for wrapping a b2World instance.
//It also acts as an interface for creating b2Body objects.
namespace GAME {
	class WorldManager {
	public:
		explicit WorldManager(ContactListener & contactListener);
		virtual ~WorldManager();

		/// Get rid of these
		WorldManager(const WorldManager&) = delete;
		WorldManager(WorldManager &&) = delete;
		WorldManager& operator=(const WorldManager &) = delete;
		WorldManager& operator=(WorldManager &&) = delete;

		/// b2Body creation interface
		b2Body * CreateBody(const b2BodyType bodyType, const float32 positionX, const float32 positionY,
			const b2FixtureDef * fixtureDef);
		// fixtureDef creation interface
		b2FixtureDef * CreateFixtureDef(const float32 friction, const float32 restitution, const float32 density,
			const b2Shape * shape);
		// b2Shape creation interface
		b2Shape * CreateCircleShape(const float32 radius, const float32 positionX = 0, const float32 positionY = 0);
		b2Shape * CreateBoxShape(const float32 halfWidth, const float32 halfHeight);
		b2Shape * CreatePolygonShape(const b2Vec2 & vertices, const int32 verticeCount);

		void Update(const float deltaTime);
	public:
		static const float32 PTM;

	private:
		b2World * world;
		b2Vec2 * gravityVec = new b2Vec2(0, 10.0f);

		float32 timeStep;
		float32 timeStepMillis;
		int32 velocityIterations;
		int32 positionIterations;
		float32 timeMultiplier;
		float32 timeAccumulator;
	};
}
#endif