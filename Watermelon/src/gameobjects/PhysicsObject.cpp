#include "PhysicsObject.h"

using namespace GAME;

PhysicsObject::PhysicsObject(const float32 x, const float32 y) : GameObject(x,y){
}

PhysicsObject::~PhysicsObject() {

	// TODO: Deallocate Body
	// deallocating this is trickier, because I believe you can only delete a body when b2World isn't locked? <Thanks Adam>
	// so create a list of objects to be destroyed that the scene calls every <insert condition here>, and when the object
	// is destroyed or goes out of scope, add it to the list.

	// + How do I call the destructor of GameObject::~GameObject ?
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

void PhysicsObject::BeginContact(const b2Contact* contact, const PhysicsObject& physObjRef) {
	return;
}

void PhysicsObject::EndContact(const b2Contact* contact, const PhysicsObject& physObjRef) {
	return;
}

void PhysicsObject::Update(const float deltaTime) {
	GameObject::Update(deltaTime);
	SetPosition(body->GetPosition().x * WorldManager::PTM, body->GetPosition().y * WorldManager::PTM);
}

void PhysicsObject::Draw(const int xOffset, const int yOffset, const float scale, SDL_Rect* clip,
	const double angle, SDL_Point* center,
	const SDL_RendererFlip flip) const {
	GameObject::Draw(xOffset, yOffset, scale, clip, angle, center, flip);

}

