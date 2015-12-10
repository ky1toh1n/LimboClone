#include "Pulley.h"

using namespace GAME;

Pulley::Pulley(PlatformerScene* scenePtr, const float32 x , const float32 y) {

	scenePtr->CreateBoxGameObject(this, "res/textures/loglong.png", x-xDist, y, b2_staticBody);
	
	GameObject* leftObject = new Log(scenePtr, x - xDist, y + length);
	GameObject* rightObject = new Log(scenePtr, x + xDist, y + length);

	leftBody = leftObject->GetBody();
	rightBody = rightObject->GetBody();

	leftBody->SetFixedRotation(true);
	rightBody->SetFixedRotation(true);

	//new Crate32x32(scenePtr, x - xDist, y - length, b2_staticBody); // Anchor Body
	//new Crate32x32(scenePtr, x + xDist, y - length, b2_staticBody); // Anchor Body

	b2PulleyJointDef jointDef;
	b2Vec2 anchor1(x - xDist, y + length);
	b2Vec2 anchor2(x + xDist, y + length);
	b2Vec2 groundAnchor1(x - xDist, y - length);
	b2Vec2 groundAnchor2(x + xDist, y - length);
	jointDef.Initialize(leftBody, rightBody, groundAnchor1, groundAnchor2, anchor1, anchor2, 1.5f);

	pulleyJoint = (b2PulleyJoint*)scenePtr->CreatePulleyJoint(jointDef);
}

Pulley::~Pulley(){

}

void Pulley::Update(const float deltaTime) {
	/*
	float32 xAnchorA = pulleyJoint->GetGroundAnchorA().x;
	float32 xAnchorB = pulleyJoint->GetGroundAnchorB().x;
	leftBody->SetTransform(b2Vec2(body->GetPosition().x - xDist , leftBody->GetPosition().y), leftBody->GetAngle());
	rightBody->SetTransform(b2Vec2(rightBody->GetPosition().x + xDist, rightBody->GetPosition().y), rightBody->GetAngle());
	*/

	// leftBody->SetTransform(leftBody->GetPosition(), leftBody->GetAngle());
	PhysicsObject::Update(deltaTime);
}