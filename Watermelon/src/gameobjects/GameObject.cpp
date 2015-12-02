#include "GameObject.h"


using namespace GAME;

GameObject::GameObject(const float32 x, const float32 y) : position(x,y) {
	sprite = nullptr;
}

GameObject::~GameObject() {
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
	// printf("Object info: %f, %f\n", position.x, position.y);

}


const b2Body* GameObject::GetBody() const {
	return nullptr;
}

void GameObject::Update(const float deltaTime) {
}


// TODO: Get actual screen size values and recalculate position
// HardCoded values for now
void GameObject::Draw(const int xOffset, const int yOffset, const float scale, SDL_Rect* clip,
	const double angle, SDL_Point* center,
	const SDL_RendererFlip flip) const {
	if (sprite != nullptr){

		sprite->Draw((int)(position.x - Width() / 2) - xOffset + 400,
			(int)(position.y - Height() / 2) - yOffset + 350, scale, clip, angle, center, flip);
	}
}

void GameObject::Print() const
{
	printf("Object DRAW info: %f, %f, %f, %f\n", position.x, position.y, Width(), Height());
}





