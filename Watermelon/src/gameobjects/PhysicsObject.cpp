#include "PhysicsObject.h"

using namespace GAME;

PhysicsObject::PhysicsObject(int x, int y) {
	GameObject::GameObject(x, y);
}

PhysicsObject::~PhysicsObject() {
	GameObject::~GameObject();
}

const b2Body* PhysicsObject::GetBody() {
	return body;
}

void PhysicsObject::Update(const float deltaTime) {
	GameObject::Update(deltaTime);
}

void PhysicsObject::Draw() const {
	GameObject::Draw();
}