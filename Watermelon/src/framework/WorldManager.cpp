#include "WorldManager.h"

using namespace GAME;

const float WorldManager::PTM = 10.0f;
const float32 WorldManager::DEF_FRICTION = 0.35f;
const float32 WorldManager::DEF_RESTITUTION = 0.2f;//0.2f
const float32 WorldManager::DEF_DENSITY = 1;

WorldManager::WorldManager(ContactListener & contactListener) {
	world = new b2World(*gravityVec);
	world->SetContactListener(&contactListener);
	world->SetAllowSleeping(false); // Set to false for debugging

	timeStep = 1.0f / 60.0f;
	// timeStepMillis = timeStep * 1000.0f;
	timeStepMillis = timeStep;
	velocityIterations = 12;
	positionIterations = 8;
	timeMultiplier = 5;
	timeAccumulator = 0;
}


WorldManager::~WorldManager() {
	delete world;
}

b2Body * WorldManager::CreateBody(const b2BodyType bodyType, const float32 positionX, const float32 positionY,
	const b2FixtureDef * fixtureDef){

	b2BodyDef * bodyDef = new b2BodyDef();
	bodyDef->type = bodyType;
	bodyDef->position.Set(positionX, positionY);
	// bodyDef->fixedRotation = true;

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

//Verices must be in CCW order
b2Shape * WorldManager::CreatePolygonShape(const b2Vec2 & vertices, const int32 verticeCount){
	b2PolygonShape * shape = new b2PolygonShape();
	shape->Set(&vertices, verticeCount);

	return shape;
}

b2Joint* WorldManager::CreateJoint(b2JointDef& jointDef) const {
	return world->CreateJoint(&jointDef);
}

void WorldManager::Update(const float deltaTime) {
	timeAccumulator += deltaTime * timeMultiplier;
	while (timeAccumulator > timeStepMillis) {
		world->Step(timeStep, velocityIterations, positionIterations);
		timeAccumulator -= timeStepMillis;
	}
}

b2Body * WorldManager::CreateBox(const float32 positionX, const float32 positionY,
	const float32 width, const float32 height, const b2BodyType bodyType,
	const float32 friction, const float32 restitution, const float32 density){
	//Convert from pixels to meters
	float32 halfWidth = ((width / 2) / PTM);
	float32 halfHeight = ((height / 2) / PTM);
	float32 ptmX = positionX / PTM;
	float32 ptmY = positionY / PTM;

	//Create b2Body
	b2Shape* tmpShape = CreateBoxShape(halfWidth, halfHeight);
	b2FixtureDef* tmpFixtureDef = CreateFixtureDef(friction, restitution, density, tmpShape);
	b2Body* tmpBody = CreateBody(bodyType
		, ptmX + halfWidth, ptmY + halfHeight, tmpFixtureDef);

	return tmpBody;
}

b2Body * WorldManager::CreateCircle(const float32 positionX, const float32 positionY,
	const float32 radius, const b2BodyType bodyType,
	const float32 friction, const float32 restitution, const float32 density){
	//Convert from pixels to meters
	float32 ptmRadius = radius / PTM;
	float32 ptmX = positionX / PTM;
	float32 ptmY = positionY / PTM;

	//Create b2Body
	b2Shape* tmpShape = CreateCircleShape(ptmRadius);
	b2FixtureDef* tmpFixtureDef = CreateFixtureDef(friction, restitution, density, tmpShape);
	b2Body* tmpBody = CreateBody(bodyType
		, ptmX, ptmY, tmpFixtureDef);

	//printf("Circle PTM Creation : %f, %f, %f\n", ptmX, ptmY, ptmRadius);
	
	return tmpBody;
}

b2Body * WorldManager::CreatePolygon(const float32 positionX, const float32 positionY,
	const b2Vec2 vertices[], const int verticeCount, const float32 width, const float32 height, 
	const b2BodyType bodyType, const float32 friction, const float32 restitution, const float32 density){
	//Convert from pixels to meters
	b2Vec2 ptmVertices[3];
	float32 ptmHalfWidth = width / 2 / PTM;
	float32 ptmHalfHeight = height/ 2 / PTM;
	float32 ptmX = positionX / PTM;
	float32 ptmY = positionY / PTM;
	for (int i = 0; i < verticeCount; i++){
		ptmVertices[i].Set(vertices[i].x / PTM - ptmHalfWidth, vertices[i].y / PTM - ptmHalfHeight);
	}

	//Create b2Body
	b2Shape* tmpShape = CreatePolygonShape(*ptmVertices, verticeCount);
	b2FixtureDef* tmpFixtureDef = CreateFixtureDef(friction, restitution, density, tmpShape);
	b2Body* tmpBody = CreateBody(bodyType
		,ptmX, ptmY, tmpFixtureDef);

	printf("Polygon PTM Creation : %f, %f\n", ptmX, ptmY);

	return tmpBody;
}