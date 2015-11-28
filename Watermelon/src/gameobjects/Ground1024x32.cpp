#include "Ground1024x32.h"

using namespace GAME;

Ground1024x32::Ground1024x32(Scene* scenePtr, const float32 x = 0, const float32 y = 0) {
	scenePtr->CreateBoxGameObject(this, b2_staticBody, x, y, "res/placeholders/ground1024x32.png");
}

Ground1024x32::~Ground1024x32() {
	PhysicsObject::~PhysicsObject();
}