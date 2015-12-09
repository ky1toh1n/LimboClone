#include "Crate32x32.h"

using namespace GAME;

Crate32x32::Crate32x32(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0, const b2BodyType type) {
	scenePtr->CreateBoxGameObject(this, "res/textures/crate.png", x, y, type);
	body->SetFixedRotation(true);

}

Crate32x32::~Crate32x32() {
}

GameObject::TYPE Crate32x32::GetType() const {
	return TYPE::CRATE_32x32;
}