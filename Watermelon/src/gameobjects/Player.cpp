#include "Player.h"
#include "WorldManager.h"

using namespace GAME;

Player::Player(b2Body& bodyRef, int x, int y) {
	// JUST PICK ONE
	// TODO: 1.) Either create the body with position then assign the object's position to the body's position
	//								OR
	// 2.) Create object with position and assign the body position to the body's position

	// for now, I'm assigning the body position to object's position
	body = &bodyRef;
	b2Vec2 tmpPosition = body->GetPosition();
	PhysicsObject::PhysicsObject(tmpPosition.x, tmpPosition.y);

}

Player::~Player() {
	PhysicsObject::~PhysicsObject();
}

void Player::Update(const float deltaTime) {
	PhysicsObject::Update(deltaTime);
	// Testing

	b2Vec2 tmpPosition = body->GetPosition();
	//std::cout << tmpPosition.x << ", "<< tmpPosition.y << std::endl;
	//std::cout << WorldManager::PTM << std::endl;
	
	PhysicsObject::SetPosition(tmpPosition.x * WorldManager::PTM, tmpPosition.y * WorldManager::PTM);
	//position.x += 1;
}

void Player::Draw() const {
	PhysicsObject::Draw();
}