#include "Player.h"

using namespace GAME;

Player::Player(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0) {
	scenePtr->CreateBoxGameObject(this, b2_dynamicBody, x, y, "res/placeholders/ph_player1.png");
}

Player::~Player() {
}

void Player::MoveLeft() {
	body->ApplyForceToCenter(b2Vec2(-100, 0), true);
}

void Player::MoveRight() {
	body->ApplyForceToCenter(b2Vec2(100, 0), true);
}


void Player::Update(const float deltaTime) {
	PhysicsObject::Update(deltaTime);
}

/*
void Player::Draw() const {
	PhysicsObject::Draw();
}
*/
