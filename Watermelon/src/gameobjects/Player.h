#ifndef PLAYER_H
#define PLAYER_H

#include "Scene.h"
#include "PhysicsObject.h"


namespace GAME {
	class Player : public PhysicsObject {
	public:
		Player(Scene* scenePtr,const float32 x, const float32 y);
		~Player();

		Player(const Player&) = delete;
		Player(Player &&) = delete;
		Player& operator=(const Player &) = delete;
		Player& operator=(Player &&) = delete;

		void MoveLeft();
		void MoveRight();

		void Update(const float deltaTime);
		// void Draw() const;
	};
}

#endif