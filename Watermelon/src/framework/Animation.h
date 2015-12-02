#ifndef ANIMATION_H
#define ANIMATION_H

#include "Texture.h"
#include <vector>
#include <iostream>

namespace GAME {
	class Animation {
	public:
		Animation(const float duration, const bool looping = true);
		virtual ~Animation();

		Animation(const Animation&) = delete;
		Animation(Animation &&) = delete;
		Animation& operator=(const Animation &) = delete;
		Animation& operator=(Animation &&) = delete;

		virtual void Destroy();
		virtual void Reset();
		virtual void AddFrame(Texture* texPtr);
		virtual Texture* Play(const float deltaTime);

	private:
		bool looping;
		float duration;
		float timeTillNextFrame;
		unsigned char currentFrame;
		std::vector<Texture*>* animation;


	};
}


#endif