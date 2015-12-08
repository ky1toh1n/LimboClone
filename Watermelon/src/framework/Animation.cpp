#include "Animation.h"

using namespace GAME;

Animation::Animation(const float duration_, const bool looping_) : currentFrame(0) { 
	animation = new std::vector < Texture* >();
	looping = looping_;
	duration = duration_; // duration is actually duration per frame at the moment, not the whole thing
							// but I was intending to do duration of animation
	timeTillNextFrame = duration_;
}

Animation::~Animation() { 
	Destroy();
}

void Animation::AddFrame(Texture* texPtr) {
	animation->push_back(texPtr);
}

void Animation::SetDuration(const float duration_) {
	duration = duration_;
	
}

Texture* Animation::Play(const float deltaTime) {
	if (timeTillNextFrame <= 0) {
		currentFrame++;
		if (currentFrame > animation->size() - 1) { 
			if (looping) { currentFrame = 0; }
			else { currentFrame--; }
		}
		timeTillNextFrame = duration;
	}
	timeTillNextFrame -= deltaTime;
	return animation->at(currentFrame);
}

void Animation::Reset() {
	currentFrame = 0;
}

void Animation::Destroy() {
	delete animation;
	animation = nullptr;
}
