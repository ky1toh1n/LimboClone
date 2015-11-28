#include "PhysicsObject.h"

using namespace GAME;

PhysicsObject::PhysicsObject(const float32 x, const float32 y){
	GameObject::GameObject(x, y);
}

PhysicsObject::~PhysicsObject() {
	GameObject::~GameObject();
}

void PhysicsObject::SetBody(b2Body& bodyRef) {
	body = &bodyRef;
}

const b2Body* PhysicsObject::GetBody() {
	return body;
}

void PhysicsObject::Update(const float deltaTime) {
	GameObject::Update(deltaTime);
	b2Vec2 tmpPosition = body->GetPosition();
	SetPosition(tmpPosition.x, tmpPosition.y);
}

void PhysicsObject::Draw(const int xOffset, const int yOffset) const {
	GameObject::Draw(xOffset, yOffset);
}