#include "Circle64x64.h"

using namespace GAME;

Circle64x64::Circle64x64(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0) {
	scenePtr->CreateCircleGameObject(this, "res/placeholders/Circle64x64.png", x, y, b2_dynamicBody);
}

Circle64x64::~Circle64x64() {
}

GameObject::TYPE Circle64x64::GetType() const {
	return TYPE::CIRCLE_64x64;
}