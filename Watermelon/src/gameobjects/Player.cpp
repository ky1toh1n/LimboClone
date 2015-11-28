#include "Player.h"

using namespace GAME;

Player::Player(Scene* scenePtr, const float32 x = 0, const float32 y = 0) {
	scenePtr->CreateBoxGameObject(this, b2_dynamicBody, x, y, "res/placeholders/ph_player1.png");
}

Player::~Player() {
	PhysicsObject::~PhysicsObject();
}

void Player::MoveLeft() {
	body->ApplyForceToCenter(b2Vec2(-10011, 0), true);
}

void Player::MoveRight() {
	body->ApplyForceToCenter(b2Vec2(10011, 0), true);
}


void Player::Update(const float deltaTime) {
	PhysicsObject::Update(deltaTime);
	b2Vec2 tmpPosition = body->GetPosition();
	SetPosition(tmpPosition.x, tmpPosition.y);
}

/*
void Player::Draw() const {
	PhysicsObject::Draw();
}
*/
