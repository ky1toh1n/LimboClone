#include "GameObject.h"

using namespace GAME;

GameObject::GameObject(int x, int y) {
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

void GameObject::SetPosition(int x, int y) {
	position.x = x;
	position.y = y;
}

Vec2 GameObject::Position() const {
	return position;
}

float GameObject::Width() const {
	return sprite->GetWidth();
}

float GameObject::Height() const {
	return sprite->GetHeight();
}

void GameObject::SetSprite(Texture& spriteRef) {
	sprite = &spriteRef;
}

const b2Body* GameObject::GetBody() {
	return nullptr;
}

void GameObject::Update(const float deltaTime) {
}

void GameObject::Draw() const {
	if (sprite != nullptr)
		sprite->Draw(position.x-Width()/2, position.y-Width()/2);	
}






