#include "ContactListener.h"

using namespace GAME;

ContactListener::ContactListener() {

}


ContactListener::~ContactListener() {

}

/*
GameObject* ContactListener::GetGameObjectWithBody(const Scene& sceneRef, const b2Body& bodyRef) const {
	return sceneRef.GetGameObjectWithBody(bodyRef);
}
*/


void ContactListener::BeginContact(b2Contact* contact){}
void ContactListener::EndContact(b2Contact* contact){}
void ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold){}
void ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse){}