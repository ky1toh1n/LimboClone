#include "Player.h"

using namespace GAME;

Player::Player(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0) {
	currentState = PlayerState::IDLE;

	animations = new std::vector<Animation*>();

	scenePtr->CreateBoxGameObject(this, b2_dynamicBody, x, y, "res/placeholders/player/idle/idle0.png");

	// There is no spritesheet class, so we are adding individual images to the animation
	Animation* anim = new Animation(0.08);
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/idle/idle0.png"));
	animations->push_back(anim);

	anim = new Animation(0.08);
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl1.png"));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl2.png"));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl3.png"));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl4.png"));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl5.png"));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl6.png"));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl7.png"));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl8.png"));
	animations->push_back(anim);

	// then we add the animation to a collection of animations
	anim = new Animation(0.08, false);
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/jump/jump0.png"));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/jump/jump1.png"));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/jump/jump2.png"));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/jump/jump3.png"));
	animations->push_back(anim);
}

Player::~Player() {
}

void Player::MoveLeft() {
	body->ApplyForceToCenter(b2Vec2(-200, 0), true);
}

void Player::MoveRight() {
	body->ApplyForceToCenter(b2Vec2(200, 0), true);
}

void Player::Jump() {
	body->ApplyLinearImpulse(b2Vec2(0, 20), b2Vec2(25, 30), true);
	currentState = PlayerState::JUMPING;
}

void Player::Stop() {
	currentState = PlayerState::IDLE;
}

void Player::HandleInput(const bool keyDownW, const bool keyDownA,
						 const bool keyDownS, const bool keyDownD,
						 const bool keyDownSPACE) {

	if (keyDownA || keyDownD) {
		currentState = PlayerState::RUNNING;
	}
	else {
		if (currentState != PlayerState::JUMPING)
			currentState = PlayerState::IDLE;
	}

	if (keyDownA) {
		MoveLeft();
	} else if (keyDownD) {
		MoveRight();
	}

	if (keyDownSPACE) {
		Jump();
	}


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

	// SetSprite(*running->Play(deltaTime));
	std::cout << currentState;

	SetSprite(*animations->at(static_cast<PlayerState>(currentState))->Play(deltaTime));

}

void Player::Draw() const {
	PhysicsObject::Draw();
}

