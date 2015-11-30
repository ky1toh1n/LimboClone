#include "PhysicsObject.h"

using namespace GAME;

PhysicsObject::PhysicsObject(const float32 x, const float32 y) : GameObject(x,y){
}

PhysicsObject::~PhysicsObject() {
}

void PhysicsObject::SetBody(b2Body& bodyRef) {
	body = &bodyRef;
	//Initializes position
	SetPosition(body->GetPosition().x, body->GetPosition().y);
}

const b2Body* PhysicsObject::GetBody() const{
	return body;
}

GameObject::TYPE PhysicsObject::GetType() const {
	return NO_CLASS;
}

void PhysicsObject::HandleCollision(const PhysicsObject& physObjRef) {
	return;
}

void PhysicsObject::Update(const float deltaTime) {
	GameObject::Update(deltaTime);
	SetPosition(body->GetPosition().x * WorldManager::PTM, body->GetPosition().y * WorldManager::PTM);
}

void PhysicsObject::Draw(const int xOffset, const int yOffset) const {
	GameObject::Draw(xOffset, yOffset);
}

