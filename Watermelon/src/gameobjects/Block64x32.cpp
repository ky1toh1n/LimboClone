#include "Block64x32.h"

using namespace GAME;

Block64x32::Block64x32(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0) {
	scenePtr->CreateBoxGameObject(this, "res/textures/crate.png", x, y, b2_dynamicBody);
}

Block64x32::~Block64x32() {
}

GameObject::TYPE Block64x32::GetType() const {
	return TYPE::BLOCK_64x32;
}