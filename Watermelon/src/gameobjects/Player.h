#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"

namespace GAME {
	class Player : public GameObject {
	public:
		Player(int x = 0, int y = 0);
		~Player();

		Player(const Player&) = delete;
		Player(Player &&) = delete;
		Player& operator=(const Player &) = delete;
		Player& operator=(GameObject &&) = delete;

	public:
		void SetSprite(Texture& spriteRef);
		void Update(const float deltaTime);
		void Draw() const;
	};
}

#endif