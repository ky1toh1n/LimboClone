#include "ContactListener.h"

#include "gameobjects/Player.h"

using namespace GAME;

ContactListener::ContactListener(std::vector<GameObject*>* sceneGameObjects) {
	gameObjects = sceneGameObjects;
}


ContactListener::~ContactListener() {
	delete gameObjects;
	gameObjects = nullptr;
}


GameObject* ContactListener::GetGameObjectWithBody(const b2Body& bodyRef) const {
	for (std::vector<GameObject*>::iterator it = gameObjects->begin(); it != gameObjects->end(); ++it) {
		GameObject* gameObject = *it;
		if (gameObject->GetBody() == &bodyRef) {
			return gameObject;
		}
	}
	return nullptr;
}


void ContactListener::BeginContact(b2Contact* contact) {
	/* Calls respective collision functions on colliding GameObjects (body/fixtures). */
	// Methods Implemented in Classes only include BeginContact() and is named HandleCollision()
	// we could implement all others if we need to later on.

	// PhysicsObject class must have a GameObject::TYPE defined to check for specific collisions,
	// by default, any GameObject with a body will return a TYPE of 'NO_CLASS'


	// TODO: Simplify
	void* bodyAUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	void* bodyBUserData = contact->GetFixtureB()->GetBody()->GetUserData();
	PhysicsObject* gameObjectA = static_cast<PhysicsObject*>(bodyAUserData);
	PhysicsObject* gameObjectB = static_cast<PhysicsObject*>(bodyBUserData);
	if (bodyAUserData && bodyBUserData) {
		gameObjectA->BeginContact(contact, *gameObjectB);
		gameObjectB->BeginContact(contact, *gameObjectA);
	}

}

void ContactListener::EndContact(b2Contact* contact){
	// TODO: Simplify
	void* bodyAUserData = contact->GetFixtureA()->GetBody()->GetUserData();
	void* bodyBUserData = contact->GetFixtureB()->GetBody()->GetUserData();
	PhysicsObject* gameObjectA = static_cast<PhysicsObject*>(bodyAUserData);
	PhysicsObject* gameObjectB = static_cast<PhysicsObject*>(bodyBUserData);
	if (bodyAUserData && bodyBUserData) {
		gameObjectA->EndContact(contact, *gameObjectB);
		gameObjectB->EndContact(contact, *gameObjectA);
	}

}
void ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold){}
void ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse){}