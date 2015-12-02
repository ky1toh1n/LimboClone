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
		//Magical Constructor Stuff
		explicit WorldManager(ContactListener & contactListener);
		virtual ~WorldManager();
		WorldManager(const WorldManager&) = delete;
		WorldManager(WorldManager &&) = delete;
		WorldManager& operator=(const WorldManager &) = delete;
		WorldManager& operator=(WorldManager &&) = delete;

		//b2Body creation public interface
		b2Body * CreateBox(const float32 positionX, const float32 positionY,
			const float32 halfWidth, const float32 halfHeight, const b2BodyType bodyType = b2_staticBody,
			const float32 friction = DEF_FRICTION, const float32 restitution = DEF_RESTITUTION, const float32 density = DEF_DENSITY);
		b2Body * CreateCircle(const float32 positionX, const float32 positionY,
			const float32 radius, const b2BodyType bodyType, const float32 friction = DEF_FRICTION,
			const float32 restitution = DEF_RESTITUTION, const float32 density = DEF_DENSITY);
		//b2Body * CreatePolygon();
		void Update(const float deltaTime);
	public:
		static const float32 PTM;
		static const float32 DEF_FRICTION;
		static const float32 DEF_RESTITUTION;
		static const float32 DEF_DENSITY;

	private:
		b2World * world;
		b2Vec2 * gravityVec = new b2Vec2(0, 2.0f); //2.0f;

		//World state
		float32 timeStep;
		float32 timeStepMillis;
		int32 velocityIterations;
		int32 positionIterations;
		float32 timeMultiplier;
		float32 timeAccumulator;

		/// b2Body creation 
		b2Body * CreateBody(const b2BodyType bodyType, const float32 positionX, const float32 positionY,
			const b2FixtureDef * fixtureDef);
		// fixtureDef creation 
		b2FixtureDef * CreateFixtureDef(const float32 friction, const float32 restitution, const float32 density,
			const b2Shape * shape);
		// b2Shape creation 
		b2Shape * CreateCircleShape(const float32 radius, const float32 positionX = 0, const float32 positionY = 0);
		b2Shape * CreateBoxShape(const float32 halfWidth, const float32 halfHeight);
		b2Shape * CreatePolygonShape(const b2Vec2 & vertices, const int32 verticeCount);
	};
}
#endif