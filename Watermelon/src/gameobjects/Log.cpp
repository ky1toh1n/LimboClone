#include "Log.h"

using namespace GAME;

Log::Log(PlatformerScene* scenePtr, const float32 x, const float32 y) : PhysicsObject(x, y) {
	scenePtr->CreateBoxGameObject(this, "res/textures/log2.png", x, y, b2_dynamicBody);
}

Log::~Log() { }

void Log::Update(const float deltaTime) {
	PhysicsObject::Update(deltaTime);
	angleInDegrees = GameObject::RadiansToDegrees(body->GetAngle());
}

void Log::Draw(const int xOffset, const int yOffset, const float scale, SDL_Rect* clip,
	const double angle, SDL_Point* center, const SDL_RendererFlip flip) const {

	PhysicsObject::Draw(xOffset, yOffset, scale, clip, angleInDegrees, center, flip);
}