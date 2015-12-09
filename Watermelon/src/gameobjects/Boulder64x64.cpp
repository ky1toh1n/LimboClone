#include "Boulder64x64.h"

using namespace MATH;

using namespace GAME;

Boulder64x64::Boulder64x64(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0) {
	scenePtr->CreateCircleGameObject(this, "res/textures/roundRock.png", x, y, b2_dynamicBody);
}

Boulder64x64::~Boulder64x64() {
}

GameObject::TYPE Boulder64x64::GetType() const {
	return TYPE::BOULDER_64x64;
}

void Boulder64x64::Update(const float deltaTime) {
	PhysicsObject::Update(deltaTime);
	angleInDegrees = GameObject::RadiansToDegrees(body->GetAngle());
}

void Boulder64x64::Draw(const int xOffset, const int yOffset, const float scale, SDL_Rect* clip,
	const double angle, SDL_Point* center, const SDL_RendererFlip flip) const {
	
	PhysicsObject::Draw(xOffset, yOffset, scale, clip, angleInDegrees, center, flip);
}
