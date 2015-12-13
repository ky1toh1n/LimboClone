#include "Pulley.h"

using namespace GAME;

Pulley::Pulley(PlatformerScene* scenePtr, const float32 x , const float32 y) {

	scenePtr->CreateBoxGameObject(this, "res/textures/loglong.png", x-112, y, b2_staticBody);
	
	ropes[0] = new Rope(scenePtr, x - xDist + 56, y + 50);
	ropes[1] = new Rope(scenePtr, x + xDist + 56, y + 50);

	anchors[0] = (PhysicsObject*)new Crate32x32(scenePtr, x - xDist + 40, y, b2_staticBody); // Anchor Body
	anchors[1] = (PhysicsObject*)new Crate32x32(scenePtr, x + xDist + 40, y, b2_staticBody); // Anchor Body

	platforms[0] = new Log(scenePtr, x - xDist, y + length);
	platforms[1] = new Log(scenePtr, x + xDist, y + length);

	b2Body* leftBody = platforms[0]->GetBody();
	b2Body* rightBody = platforms[1]->GetBody();

	leftBody->SetFixedRotation(true);
	rightBody->SetFixedRotation(true);



	b2PulleyJointDef jointDef;
	b2Vec2 anchor1(x - xDist, y+32);
	b2Vec2 anchor2(x + xDist, y+32);
	b2Vec2 groundAnchor1(x - xDist, y);
	b2Vec2 groundAnchor2(x + xDist, y);
	jointDef.Initialize(leftBody, rightBody, groundAnchor1, groundAnchor2, anchor1, anchor2, 1.05f);

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

	ropes[0]->SetStart(platforms[0]->GetBody()->GetPosition()); // platforms[0]->GetPosition() uses MATH::Vec2 so.. gotta change that
	ropes[1]->SetStart(platforms[1]->GetBody()->GetPosition());
	PhysicsObject::Update(deltaTime);
}