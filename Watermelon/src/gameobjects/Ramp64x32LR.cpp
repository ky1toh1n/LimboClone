#include "Ramp64x32LR.h"

using namespace GAME;

Ramp64x32LR::Ramp64x32LR(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0) {
	b2Vec2 vertices[3];
	vertices[0].Set(0, 32);
	vertices[1].Set(64, 32);
	vertices[2].Set(64, 0);
	scenePtr->CreateTriangleGameObject(this, "res/placeholders/Triangle64x32.png", x, y, vertices, b2_dynamicBody);
	body->SetFixedRotation(true);
}
 
Ramp64x32LR::~Ramp64x32LR() {
}

GameObject::TYPE Ramp64x32LR::GetType() const {
	return TYPE::RAMP;
}