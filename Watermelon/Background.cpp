#include "Background.h"

using namespace GAME;

Background::Background(PlatformerScene* scenePtr, const float32 x, const float32 y, const OrthographicCamera* cam) : PhysicsObject(x, y){
	scenePtr->AddToScene(this);
	Texture* tex = scenePtr->LoadTexture("res/textures/background.png");
	SetSprite(*tex);
	camera = cam;
}

Background::~Background() {
}

void Background::Update(float deltaTime) {

}

void Background::Draw(const int xOffset, const int yOffset, const float scale, SDL_Rect* clip,
	const double angle, SDL_Point* center, const SDL_RendererFlip flip) const {

	PhysicsObject::Draw(xOffset,
		camera->GetRect()->h/2, 
		scale*1.1, clip, angle, center, flip);
}