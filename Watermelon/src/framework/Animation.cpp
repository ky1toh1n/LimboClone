#include "Animation.h"

using namespace GAME;

Animation::Animation(float duration_) : currentFrame(0) { 
	animation = new std::vector < Texture* >();
	duration = duration_; // duration is actually duration per frame at the moment, not the whole thing
							// but I was intending to do duration of animation
	timeTillNextFrame = duration_;
}

Animation::~Animation() { }

void Animation::AddFrame(Texture* texPtr) {
	animation->push_back(texPtr);
}

Texture* Animation::Play(const float deltaTime) {
	if (timeTillNextFrame <= 0) {
		currentFrame++;
		if (currentFrame > animation->size() - 1) { currentFrame = 0; }
		timeTillNextFrame = duration;
	}
	timeTillNextFrame -= deltaTime;
	return animation->at(currentFrame);
}
