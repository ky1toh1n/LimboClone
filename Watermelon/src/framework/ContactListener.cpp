#include "ContactListener.h"

using namespace GAME;

ContactListener::ContactListener(std::vector<GameObject*>* sceneGameObjects) {
	gameObjects = sceneGameObjects;
}


ContactListener::~ContactListener() {

}


GameObject* ContactListener::GetGameObjectWithBody(const b2Body& bodyRef) const {
	for (std::vector<GameObject*>::iterator it = gameObjects->begin(); it != gameObjects->end(); ++it) {
		GameObject* gameObject = *it;
		if (gameObject->GetBody() == &bodyRef) {
			return gameObject;
		}
	}
}

void ContactListener::BeginContact(b2Contact* contact){}
void ContactListener::EndContact(b2Contact* contact){}
void ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold){}
void ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse){}