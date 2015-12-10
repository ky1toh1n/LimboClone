#include "SeeSaw.h"

using namespace GAME;

SeeSaw::SeeSaw(PlatformerScene* scenePtr, const float32 x, const float32 y) : PhysicsObject(x, y) {
	b2Vec2 vertices[3];
	vertices[0].Set(16, 32);
	vertices[1].Set(0, 64);
	vertices[2].Set(64, 64);
	scenePtr->CreateTriangleGameObject(this, "res/textures/seesawrock.png", x, y, vertices, b2_staticBody);
	body->SetFixedRotation(true);

	GameObject* beam = new Log(scenePtr, x, y);
	// Store the joint so it can be destroyed.
	b2RevoluteJointDef jointDef;
	jointDef.bodyA = body;
	jointDef.bodyB = beam->GetBody();
	jointDef.collideConnected = false;
	joint = scenePtr->CreateRevoluteJoint(jointDef);
	
}

SeeSaw::~SeeSaw() { }