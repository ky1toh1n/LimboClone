#include "Player.h"

using namespace GAME;

Player::Player(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0) {
	scenePtr->CreateBoxGameObject(this, b2_dynamicBody, x, y, "res/placeholders/ph_player1.png");

	running = new Animation(0.08);
	running->AddFrame(scenePtr->LoadTexture("res/placeholders/player/pl1.png"));
	running->AddFrame(scenePtr->LoadTexture("res/placeholders/player/pl2.png"));
	running->AddFrame(scenePtr->LoadTexture("res/placeholders/player/pl3.png"));
	running->AddFrame(scenePtr->LoadTexture("res/placeholders/player/pl4.png"));
	running->AddFrame(scenePtr->LoadTexture("res/placeholders/player/pl5.png"));
	running->AddFrame(scenePtr->LoadTexture("res/placeholders/player/pl6.png"));
	running->AddFrame(scenePtr->LoadTexture("res/placeholders/player/pl7.png"));
	running->AddFrame(scenePtr->LoadTexture("res/placeholders/player/pl8.png"));

}

Player::~Player() {
}

void Player::MoveLeft() {
	body->ApplyForceToCenter(b2Vec2(-50, 0), true);
}

void Player::MoveRight() {
	body->ApplyForceToCenter(b2Vec2(50, 0), true);
}

void Player::HandleCollision(const PhysicsObject& physObjRef) {
	if (physObjRef.GetType() == TYPE::BLOCK_64x32) {
		std::cout << "Life -1;";
	}

	if (physObjRef.GetType() == TYPE::GROUND_1024x32) {
		std::cout << "Grounded";
	}
}

void Player::Update(const float deltaTime) {
	PhysicsObject::Update(deltaTime);
	SetSprite(*running->Play(deltaTime));
}

void Player::Draw() const {
	PhysicsObject::Draw();
}

