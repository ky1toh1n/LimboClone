#ifndef PLAYER_H
#define PLAYER_H

#include "PlatformerScene.h"
#include "PhysicsObject.h"
#include "Animation.h"



namespace GAME {
	class Player : public PhysicsObject {
	public:

		enum PlayerState {
			IDLE = 0,
			RUNNING = 1,
			JUMPING = 2,
			NUM_ANIMATIONS = 3
		};


		Player(PlatformerScene* scenePtr, const float32 x, const float32 y);
		~Player();

		Player(const Player&) = delete;
		Player(Player &&) = delete;
		Player& operator=(const Player &) = delete;
		Player& operator=(Player &&) = delete;

		void MoveLeft();
		void MoveRight();
		void Jump();
		void Stop();

		void HandleInput(const bool keyDownW, const bool keyDownA,
			const bool keyDownS, const bool keyDownD,
			const bool keyDownSPACE);

		void HandleCollision(const PhysicsObject& physObjRef);
		void Update(const float deltaTime);
		void Draw() const;

	private:
		std::vector<Animation*>* animations;
		PlayerState currentState;
	};
}

#endif