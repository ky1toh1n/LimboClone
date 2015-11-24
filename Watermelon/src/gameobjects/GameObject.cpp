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

void GameObject::SetSprite(Texture& spriteRef) {
	sprite = &spriteRef;
}

void GameObject::Update(const float deltaTime) {
}

void GameObject::Draw() const {
	sprite->Draw(position.x, position.y);	
}






