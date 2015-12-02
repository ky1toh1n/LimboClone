#include "Triangle64x32.h"

using namespace GAME;

Triangle64x32::Triangle64x32(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0) {
	b2Vec2 vertices[3];
	vertices[0].Set(0, 32);
	vertices[1].Set(64, 32);
	vertices[2].Set(64, 0);
	scenePtr->CreateTriangleGameObject(this, "res/placeholders/Triangle64x32.png", x, y, vertices, b2_dynamicBody);
}

Triangle64x32::~Triangle64x32() {
}

GameObject::TYPE Triangle64x32::GetType() const {
	return TYPE::CIRCLE_64x64;
}