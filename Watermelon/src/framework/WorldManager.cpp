#include "WorldManager.h"

using namespace GAME;

WorldManager::WorldManager(ContactListener & contactListener) {
	world = new b2World(*gravityVec);
	world->SetContactListener(&contactListener);
}


WorldManager::~WorldManager() {
	delete world;
}

b2Body * WorldManager::CreateBody(const b2BodyType bodyType, const float32 positionX, const float32 positionY,
	const b2FixtureDef * fixtureDef){
	b2BodyDef * bodyDef = new b2BodyDef();
	bodyDef->type = bodyType;
	bodyDef->position.Set(positionX, positionY);

	//Creates & adds body to world
	b2Body* dynamicBody = world->CreateBody(bodyDef);

	dynamicBody->CreateFixture(fixtureDef);

	return dynamicBody;
}

b2FixtureDef * WorldManager::CreateFixtureDef(const float32 friction, const float32 restitution, const float32 density,
	const b2Shape * shape){
	b2FixtureDef * fixtureDef = new b2FixtureDef;
	fixtureDef->shape = shape;
	fixtureDef->friction = friction;
	fixtureDef->restitution = restitution;
	fixtureDef->density = density;

	return fixtureDef;
}

b2Shape * WorldManager::CreateCircleShape(const float32 radius, const float32 positionX, const float32 positionY){
	b2CircleShape * shape = new b2CircleShape();
	//Sets position relative to the b2Body. Useful for rotating around a pivot.
	shape->m_p.Set(positionX, positionY);
	shape->m_radius = radius;

	return shape;
}


b2Shape * WorldManager::CreateBoxShape(const float32 halfWidth, const float32 halfHeight){
	//The box will be centered at the b2Body it is attached to.
	b2PolygonShape * shape = new b2PolygonShape();
	shape->SetAsBox(halfWidth, halfHeight);

	return shape;
}

b2Shape * WorldManager::CreatePolygonShape(const b2Vec2 & vertices, const int32 verticeCount){
	b2PolygonShape * shape = new b2PolygonShape();
	shape->Set(&vertices, verticeCount);

	return shape;
}