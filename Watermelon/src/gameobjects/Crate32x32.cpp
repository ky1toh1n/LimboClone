#include "Crate32x32.h"

using namespace GAME;

Crate32x32::Crate32x32(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0) {
	scenePtr->CreateBoxGameObject(this, "res/textures/crate.png", x, y, b2_dynamicBody);
	body->SetFixedRotation(true);
}

Crate32x32::~Crate32x32() {
}

GameObject::TYPE Crate32x32::GetType() const {
	return TYPE::CRATE_32x32;
}