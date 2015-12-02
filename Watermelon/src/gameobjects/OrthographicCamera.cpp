#include "OrthographicCamera.h"

using namespace GAME;

OrthographicCamera::OrthographicCamera(const int x, const int y, const int width, const int height) { 
	cam = new SDL_Rect();
	cam->x = x;
	cam->y = y;
	cam->w = width;
	cam->h = height;
}

OrthographicCamera::~OrthographicCamera() { }

void OrthographicCamera::SetFocus(const GameObject* focusPtr) {
	focus = focusPtr;
}

Vec2 OrthographicCamera::GetPosition() const {
	return focus->Position();
}

SDL_Rect* OrthographicCamera::GetRect() const {
	return cam;
}

void OrthographicCamera::Update(const float deltaTime) {
	cam->x = (int)focus->Position().x;
	cam->y = (int)focus->Position().y;
}