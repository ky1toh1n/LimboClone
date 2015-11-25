#ifndef PLAYER_H
#define PLAYER_H

#include "PhysicsObject.h"

namespace GAME {
	class Player : public PhysicsObject {
	public:
		explicit Player(b2Body& bodyRef, int x = 0, int y = 0);
		~Player();

		Player(const Player&) = delete;
		Player(Player &&) = delete;
		Player& operator=(const Player &) = delete;
		Player& operator=(Player &&) = delete;

	public:
		void Update(const float deltaTime);
		void Draw() const;
	};
}

#endif