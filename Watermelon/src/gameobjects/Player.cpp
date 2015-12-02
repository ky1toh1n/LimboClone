#include "Player.h"

using namespace GAME;

Player::Player(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0) {
	currentState = PlayerState::JUMPING;
	animations = new std::vector<Animation*>();

	scenePtr->CreateBoxGameObject(this, b2_dynamicBody, x, y, "res/placeholders/player/idle/idle0.png");

	// There is no spritesheet class, so we are adding individual images to the animation

	//TODO: ->SetBlendMode(SDL_BLENDMODE_BLEND) .. enable alpha transparency on the images
	// NTS: The images dont have transparency yet, I tested it and it works

	Animation* anim = new Animation(0.08);
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/idle/idle0.png", SDL_BLENDMODE_BLEND));
	animations->push_back(anim);

	anim = new Animation(0.08);
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl1.png", SDL_BLENDMODE_BLEND));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl2.png", SDL_BLENDMODE_BLEND));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl3.png", SDL_BLENDMODE_BLEND));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl4.png", SDL_BLENDMODE_BLEND));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl5.png", SDL_BLENDMODE_BLEND));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl6.png", SDL_BLENDMODE_BLEND));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl7.png", SDL_BLENDMODE_BLEND));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/run/pl8.png", SDL_BLENDMODE_BLEND));
	animations->push_back(anim);

	// then we add the animation to a collection of animations
	anim = new Animation(0.08, false);
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/jump/jump0.png", SDL_BLENDMODE_BLEND));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/jump/jump1.png", SDL_BLENDMODE_BLEND));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/jump/jump2.png", SDL_BLENDMODE_BLEND));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/jump/jump3.png", SDL_BLENDMODE_BLEND));
	animations->push_back(anim);
}

Player::~Player() {
}

void Player::MoveLeft() {
	// body->ApplyForceToCenter(b2Vec2(-200, 0), true);

	body->ApplyLinearImpulse(b2Vec2(-5, 0), body->GetWorldCenter(), true);
}

void Player::MoveRight() {
	// body->ApplyForceToCenter(b2Vec2(200, 0), true);
	body->ApplyLinearImpulse(b2Vec2(5, 0), body->GetWorldCenter(), true);
}

void Player::Jump() {
	if (currentState == PlayerState::JUMPING) return;
	animations->at(2)->Reset();
	currentState = PlayerState::JUMPING;
	body->ApplyLinearImpulse(b2Vec2(0, -body->GetMass() * 5), body->GetWorldCenter(), true);
}

void Player::Stop() {
	currentState = PlayerState::IDLE;
}

void Player::HandleInput(const bool keyDownW, const bool keyDownA,
						 const bool keyDownS, const bool keyDownD,
						 const bool keyDownSPACE) {

	if (keyDownA || keyDownD) {
		if (currentState != PlayerState::JUMPING)
			currentState = PlayerState::RUNNING;
	}
	else {
		if (currentState != PlayerState::JUMPING)
			currentState = PlayerState::IDLE;
	}

	if (keyDownA) {
		MoveLeft();
		flipTex = SDL_FLIP_HORIZONTAL;
	} else if (keyDownD) {
		MoveRight();
		flipTex = SDL_FLIP_NONE;
	}

	if (keyDownSPACE) {
		Jump();
	}

}



void Player::HandleCollision(const b2Contact* contact, const PhysicsObject& physObjRef) {
	if (physObjRef.GetType() == TYPE::BLOCK_64x32) {
		//std::cout << "Life -1;";
	}

	/* if (physObjRef.GetType() == TYPE::GROUND_1024x32 || contact->GetManifold) {
		if (currentState != PlayerState::IDLE) currentState = PlayerState::IDLE;
	} */

	if (contact->GetManifold()->localNormal.y < 0 && contact->GetManifold()->localPoint.x == 0) {
		if (currentState != PlayerState::IDLE) currentState = PlayerState::IDLE;
	}

}

void Player::Update(const float deltaTime) {
	PhysicsObject::Update(deltaTime);

	SetSprite(*animations->at(static_cast<PlayerState>(currentState))->Play(deltaTime));
}

void Player::Draw(const int xOffset, const int yOffset, const float scale, SDL_Rect* clip,
	const double angle, SDL_Point* center, const SDL_RendererFlip flip) const {

	PhysicsObject::Draw(xOffset, yOffset, scale, clip, angle, center, flipTex);
}

