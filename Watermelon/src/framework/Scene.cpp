#include "Scene.h"

using namespace GAME;

Scene::Scene(Window& windowRef, KeyboardManager& keymanRef) : windowPtr(&windowRef), keyboardManager(&keymanRef) {
	//Heap allocation:
	//Background texture & music
	backgroundTexture = new Texture(windowPtr->GetRenderer());
	backgroundMusic = new Music();
	//Box2D
	contactListener = new ContactListener();
	worldManager = new WorldManager(*contactListener);
}


Scene::~Scene() {

	delete windowPtr;
	windowPtr = nullptr;

	delete keyboardManager;
	keyboardManager = nullptr;

	delete backgroundTexture;
	backgroundTexture = nullptr;

	delete backgroundMusic; 
	backgroundMusic = nullptr;

	delete contactListener;
	contactListener = nullptr;

	delete worldManager;
	worldManager = nullptr;

	Debug::Log(EMessageType::INFO, "Successfully destroyed Scene.cpp", __FILENAME__, __LINE__);
}