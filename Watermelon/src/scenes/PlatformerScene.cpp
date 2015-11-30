#include "PlatformerScene.h"

using namespace GAME;
using namespace std;
using namespace std::placeholders;

PlatformerScene::PlatformerScene(Window& windowRef, KeyboardManager& keymanRef) : Scene(windowRef, keymanRef) {
	///Heap allocation for things that every PlatformerScene needs:
	//Background texture & music
	backgroundTexture = new Texture(windowPtr->GetRenderer());

	//Box2D physics
	contactListener = new ContactListener(gameObjects);
	worldManager = new WorldManager(*contactListener);

	//Framework
	gameObjects = new std::vector<GameObject*>();
	camera = new OrthographicCamera();
}

PlatformerScene::~PlatformerScene() {
	delete backgroundTexture;
	backgroundTexture = nullptr;
	delete contactListener;
	contactListener = nullptr;
	delete worldManager;
	worldManager = nullptr;
	delete gameObjects;
	gameObjects = nullptr;
	delete camera;
	camera = nullptr;
	Debug::Log(EMessageType::INFO, "Successfully destroyed PlatformerScene.cpp", __FILENAME__, __LINE__);
}

bool PlatformerScene::OnCreate() {
	if (!LoadAssets()) { return false; }
	if (!LoadActors()) { return false; }
	return true;
}

void PlatformerScene::AddGameObjectToPlatformerScene(GameObject* gameObjRef) {
	gameObjects->push_back(gameObjRef);
}

/*
This function:
-Creates a b2Body
-Attaches the b2Body to a GameObject
-Adds the GameObject to the PlatformerScene.
*/
void PlatformerScene::CreateBoxGameObject(PhysicsObject* gameObjectPtr, const b2BodyType& type, const float32 x, const float32 y, const std::string& path) {
	//Load texture
	Texture* tmpTex = new Texture(windowPtr->GetRenderer());
	tmpTex->Load(path);

	//Convert from pixels to meters
	float32 width = ((float32)tmpTex->GetWidth() / 2) / WorldManager::PTM;
	float32 height = ((float32)tmpTex->GetHeight() / 2) / WorldManager::PTM;
	float32 ptmX = x / WorldManager::PTM;
	float32 ptmY = y / WorldManager::PTM;

	//Create b2Body
	b2Shape* tmpShape = worldManager->CreateBoxShape(width, height);
	b2FixtureDef* tmpFixtureDef = worldManager->CreateFixtureDef(0, 1, 1, tmpShape);
	b2Body* tmpBody = worldManager->CreateBody(type
		, ptmX + width, ptmY + height, tmpFixtureDef);
	tmpBody->SetUserData(gameObjectPtr);

	//Binding b2Body to GameObject
	gameObjectPtr->SetBody(*tmpBody);
	gameObjectPtr->SetSprite(*tmpTex);

	//Add to PlatformerScene
	AddGameObjectToPlatformerScene(gameObjectPtr);
}

Texture* PlatformerScene::LoadTexture(const string& path) const {
	Texture* tmpTex = new Texture(windowPtr->GetRenderer());
	tmpTex->Load(path);
	return tmpTex;
}

void PlatformerScene::Update(const float deltaTime){
	HandleInput();

	//Update players & World
	for_each(gameObjects->begin(), gameObjects->end(), bind(&GameObject::Update, _1, deltaTime));
	worldManager->Update(deltaTime);
}

void PlatformerScene::Render() const{
	windowPtr->ClearRenderer();

	//Draw bg
	backgroundTexture->Draw();

	//Draw actors
	for_each(gameObjects->begin(), gameObjects->end(),
		bind(&GameObject::Draw, _1, camera->GetPosition().x, camera->GetPosition().y));

	//std::cout << camera->GetPosition().x << std::endl;

	// SDL_RenderSetViewport(windowPtr->GetRenderer(), camera->GetRect());
	// SDL_Surface* screenSurface = windowPtr->GetWindowSurface();
	// SDL_Texture* currentScreen = SDL_CreateTextureFromSurface(windowPtr->GetRenderer(), screenSurface);

	SDL_RenderPresent(windowPtr->GetRenderer());
}
