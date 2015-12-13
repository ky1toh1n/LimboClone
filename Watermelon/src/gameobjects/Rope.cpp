#include "Rope.h"
#include <math.h>

using namespace GAME;


Rope::Rope(PlatformerScene* scenePtr, const float32 x, const float32 y) : PhysicsObject(x, y) {
	
	Texture* tex = scenePtr->LoadTexture("res/textures/rope.png", SDL_BLENDMODE_BLEND);
	SetSprite(*tex);

	scenePtr->AddToScene(this);

	startPos = new b2Vec2(x, y);
	endPos = new b2Vec2(x, y);

}

Rope::~Rope() {

}

void Rope::SetStart(const b2Vec2& startPos_) {
	startPos = &startPos_;
	position.x = startPos_.x * WorldManager::PTM;
	position.y = startPos_.y * WorldManager::PTM;

}

void Rope::SetEnd(const b2Vec2& endPos_) {
	endPos = &endPos_;
}

void Rope::Update(const float deltaTime) {
	/*
	b2Vec2 newEnd = b2Vec2(endPos->x * WorldManager::PTM, endPos->y * WorldManager::PTM);

	b2Vec2 angle = newEnd - *startPos;
	angle.Normalize();
	angleInDegrees = atan2(angle.y, angle.x) * 180 / M_PI;
	*/
	b2Vec2 newStart = b2Vec2(startPos->x * WorldManager::PTM, startPos->y * WorldManager::PTM);

	b2Vec2 angle = newStart - *endPos;
	angle.Normalize();
	angleInDegrees = atan2(angle.y, angle.x) * 180 / M_PI;

	
}

void Rope::Draw(const int xOffset, const int yOffset, const float scale, SDL_Rect* clip,
	const double angle, SDL_Point* center, const SDL_RendererFlip flip) const {

	PhysicsObject::Draw(xOffset, yOffset, scale * 0.8f, clip, angleInDegrees, center, flip);
}
