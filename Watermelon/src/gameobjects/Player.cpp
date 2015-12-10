#include "Player.h"

using namespace GAME;

Player::Player(PlatformerScene* scenePtr, const float32 x = 0, const float32 y = 0) {
	currentState = PlayerState::JUMPING;
	animations = new std::vector<Animation*>();
	scenePtr->CreateCircleGameObject(this, "res/placeholders/player/idle/idle0.png", x, y, b2_dynamicBody, 25, 0.5);
	
	body->SetFixedRotation(true);
	// There is no spritesheet class, so we are adding individual images to the animation

	//TODO: ->SetBlendMode(SDL_BLENDMODE_BLEND) .. enable alpha transparency on the images
	// NTS: The images dont have transparency yet, I tested it and it works

	Animation* anim = new Animation(0.08f);
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/idle/idle0.png", SDL_BLENDMODE_BLEND));
	animations->push_back(anim);

	anim = new Animation(0.08f);
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
	anim = new Animation(0.08f, false);
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/jump/jump0.png", SDL_BLENDMODE_BLEND));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/jump/jump1.png", SDL_BLENDMODE_BLEND));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/jump/jump2.png", SDL_BLENDMODE_BLEND));
	anim->AddFrame(scenePtr->LoadTexture("res/placeholders/player/jump/jump3.png", SDL_BLENDMODE_BLEND));
	animations->push_back(anim);
}

Player::~Player() {
}

// === Private Functions ====
void Player::Move(const float32 force) {
	if (currentState != PlayerState::JUMPING) { currentState = PlayerState::RUNNING; }
	body->ApplyLinearImpulse(b2Vec2(force, 0), body->GetWorldCenter(), true);
	flipTex = force > 0 ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL;
}

void Player::Jump() {
	if (currentState == PlayerState::JUMPING) return;
	animations->at(static_cast<PlayerState>(PlayerState::JUMPING))->Reset();
	currentState = PlayerState::JUMPING;
	body->ApplyLinearImpulse(b2Vec2(0, -body->GetMass() * 5), body->GetWorldCenter(), true);
}

void Player::Stop() {
	if (currentState == PlayerState::IDLE) return;
	currentState = PlayerState::IDLE;
}

bool Player::IsDead() const{
	return currentState == DEAD;
}

// === Private Functions End ===

void Player::HandleInput(const bool moveUp, const bool moveLeft,
	const bool keyDownS, const bool moveRight,
						 const bool jump) {

	if (moveRight) { Move(4); }
	else if (moveLeft) { Move(-4); }
	else if (currentState != PlayerState::JUMPING) { currentState = PlayerState::IDLE; }

	if (jump) { Jump(); }

}



void Player::BeginContact(const b2Contact* contact, const PhysicsObject& physObjRef) {
	numContacts++;
	if (physObjRef.GetType() == TYPE::CRATE_32x32) {
		//std::cout << "Life -1;";
	}

	/* if (physObjRef.GetType() == TYPE::GROUND_1024x32 || contact->GetManifold) {
		if (currentState != PlayerState::IDLE) currentState = PlayerState::IDLE;
	} */

	if (contact->GetManifold()->localNormal.y < 0) {
		// Insert ground contacts here if you would count hitting ceiling objects
		// ie) groundContacts++;
		Stop();
	}

}


void Player::EndContact(const b2Contact* contact, const PhysicsObject& physObjRef) {
	numContacts--;

	if (numContacts <= 0) {
		currentState = PlayerState::JUMPING;
 	}

}



void Player::Update(const float deltaTime) {
	PhysicsObject::Update(deltaTime);

	SetSprite(*animations->at(static_cast<PlayerState>(currentState))->Play(deltaTime));

	if (position.y > 600) { 
		currentState = PlayerState::DEAD;
	}
}

void Player::Draw(const int xOffset, const int yOffset, const float scale, SDL_Rect* clip,
	const double angle, SDL_Point* center, const SDL_RendererFlip flip) const {

	PhysicsObject::Draw(xOffset, yOffset, scale, clip, angle, center, flipTex);
}

