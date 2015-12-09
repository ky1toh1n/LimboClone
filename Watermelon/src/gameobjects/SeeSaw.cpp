#include "SeeSaw.h"

using namespace GAME;

SeeSaw::SeeSaw(PlatformerScene* scenePtr, const float32 x, const float32 y) : PhysicsObject(x, y) {
	b2Vec2 vertices[3];
	vertices[0].Set(0, 0);
	vertices[1].Set(0, 0);
	vertices[2].Set(0, 0);
	scenePtr->CreateTriangleGameObject(this, "res/textures/seesawrock.png", x, y, vertices, b2_staticBody);
	body->SetFixedRotation(true);

	GameObject* beam = new Log(scenePtr, x, y);
	// Store the joint so it can be destroyed.
	joint = scenePtr->CreateJoint(body, beam->GetBody(), false);
	
}

SeeSaw::~SeeSaw() { }