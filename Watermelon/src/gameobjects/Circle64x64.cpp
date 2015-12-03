#include "Circle64x64.h"

using namespace MATH;

using namespace GAME;

Circle64x64::Circle64x64(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0) {
	scenePtr->CreateCircleGameObject(this, "res/placeholders/Circle64x64.png", x, y, b2_dynamicBody);
}

Circle64x64::~Circle64x64() {
}

GameObject::TYPE Circle64x64::GetType() const {
	return TYPE::CIRCLE_64x64;
}

void Circle64x64::Update(const float deltaTime) {
	PhysicsObject::Update(deltaTime);
	angleInDegrees = GameObject::RadiansToDegrees(body->GetAngle());
}

void Circle64x64::Draw(const int xOffset, const int yOffset, const float scale, SDL_Rect* clip,
	const double angle, SDL_Point* center, const SDL_RendererFlip flip) const {
	
	PhysicsObject::Draw(xOffset, yOffset, scale, clip, angleInDegrees, center, flip);
}
