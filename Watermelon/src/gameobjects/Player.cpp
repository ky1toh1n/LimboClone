#include "Player.h"

using namespace GAME;

Player::Player(int x, int y) {
	GameObject::GameObject(x, y);
}

Player::~Player() {
}

void Player::SetSprite(Texture& spriteRef) {
	sprite = &spriteRef;
}

void Player::Update(const float deltaTime) {
	GameObject::Update(deltaTime);
	// Testing
	position.x += 1;
}

void Player::Draw() const {
	GameObject::Draw();
}