#include "GameObject.h"

using namespace GAME;

GameObject::GameObject(const float32 x, const float32 y) {
	position.x = x;
	position.y = y;
	sprite = nullptr;
}

GameObject::~GameObject() {
	Destroy();
}

void GameObject::Destroy() {
	sprite = nullptr;
}

void GameObject::SetPosition(const float32 x, const float32 y) {
	position.x = x;
	position.y = y;
}

Vec2 GameObject::Position() const {
	return position;
}

float32 GameObject::Width() const {
	return (float32)sprite->GetWidth();
}

float32 GameObject::Height() const {
	return (float32)sprite->GetHeight();
}

void GameObject::SetSprite(Texture& spriteRef) {
	sprite = &spriteRef;
}

const b2Body* GameObject::GetBody() {
	return nullptr;
}

void GameObject::Update(const float deltaTime) {
}


// TODO: Get actual screen size values and recalculate position
// HardCoded values for now.. im tired.
void GameObject::Draw(const int xOffset, const int yOffset) const {
	if (sprite != nullptr)
		sprite->Draw((int)(position.x - Width() / 2) - xOffset + 400, 
					 (int)(position.y - Height() / 2) - yOffset + 500);
}






