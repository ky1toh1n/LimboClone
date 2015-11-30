#include "Block64x32.h"

using namespace GAME;

Block64x32::Block64x32(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0) {
	scenePtr->CreateBoxGameObject(this, b2_dynamicBody, x, y, "res/placeholders/block64x32.png");
}

Block64x32::~Block64x32() {
}

GameObject::TYPE Block64x32::GetType() const {
	return TYPE::BLOCK_64x32;
}