#include "Rope.h"
#include <math.h>

using namespace GAME;


Rope::Rope(PlatformerScene* scenePtr, const float32 x, const float32 y) : PhysicsObject(x, y) {
	
	Texture* tex = scenePtr->LoadTexture("res/textures/greenArrow.png", SDL_BLENDMODE_BLEND);
	SetSprite(*tex);

	scenePtr->AddToScene(this);

	startPos = new b2Vec2(x, y);
	endPos = new b2Vec2(0, 0);

}

Rope::~Rope() {

}

void Rope::SetEnd(const b2Vec2& endPos_) {
	endPos = &endPos_;
}

void Rope::Update(const float deltaTime) {
	b2Vec2 newEnd = b2Vec2(endPos->x * WorldManager::PTM, endPos->y * WorldManager::PTM);

	b2Vec2 angle = newEnd - *startPos;
	angle.Normalize();
	angleInDegrees = atan2(angle.y, angle.x) * 180 / M_PI;
	
}

void Rope::Draw(const int xOffset, const int yOffset, const float scale, SDL_Rect* clip,
	const double angle, SDL_Point* center, const SDL_RendererFlip flip) const {

	PhysicsObject::Draw(xOffset, yOffset, scale*0.09, clip, angleInDegrees, center, flip);
}
