#include "PlatformerScene0.h"
#include "GameSceneManager.h"

using namespace GAME;

PlatformerScene0::PlatformerScene0(class Window& windowRef, class KeyboardManager& keymanRef): PlatformerScene(windowRef, keymanRef) {
	
}

PlatformerScene0::~PlatformerScene0(){
	Debug::Log(EMessageType::INFO, "Successfully destroyed PlatformerScene0.cpp", __FILENAME__, __LINE__);
}

bool PlatformerScene0::LoadAssets() {
	/// Load Assets:
	/// Background

	if (!backgroundTexture->Load("res/textures/limb800x600.bmp"))
		{return false;}
	



	/// Title
	/// SoundEffects
	/// Models needed for this scene
	/// Music
	if (!backgroundMusic->Load("res/bgm/Martin Stig Andersen - Limbo (Original Videogame Soundtrack) - 01 Menu.wav"))
		{return false;}
	backgroundMusic->Play(std::numeric_limits<int>::max());
	return true;
}

bool PlatformerScene0::LoadActors() {
	gameObjects = new std::vector<GameObject*>();


	// Scrolling Background
	// TODO: Myles
	// Create a GameObject class for backgrounds
	
	/*
	Texture* tex = LoadTexture("res/textures/background.png");
	GameObject* bg = new GameObject(1151, 195);
	bg->SetSprite(*tex);
	AddToScene(bg);
	bg = new GameObject(0, 195);
	bg->SetSprite(*tex);
	AddToScene(bg);
	*/
	

	new Background(this, 0, 195, camera);
	new Background(this, 1265, 195, camera);

	player = new Player(this, 200, 30);
	camera->SetFocus(player);

	new SeeSaw(this, 300, 270);

	new Ground1024x32(this, 0, 300);
	new Ground1024x32(this, 1025, 268);


	// Testing collisions
	//new Block64x32(this, 250, 0);
	//new Block64x32(this, 350, 50);
	//new Block64x32(this, 450, 100);
	//new Circle64x64(this, 300, -50);

	//Testing
	new Ramp64x32LR(this, 1200, 0);
	new Crate32x32(this, 0, 0);
	new Crate32x32(this, 33, 0);
	new Crate32x32(this, 60, 0);
	new Boulder64x64(this, 800, 50);



	Debug::Log(EMessageType::INFO, "Created Scene 0", __FILENAME__, __LINE__);
	return true;
}



void PlatformerScene0::HandleInput() {
	player->HandleInput(keyboardManager->IsPressed(Keyboard::Key::W),
						keyboardManager->IsPressed(Keyboard::Key::A),
						keyboardManager->IsPressed(Keyboard::Key::S),
						keyboardManager->IsPressed(Keyboard::Key::D),
						keyboardManager->IsPressed(Keyboard::Key::SPACE));

	

		// Reset Scene

		// NOTE: Implement/Enable this only after properly deallocating the scene's gameObjects. 
		// Of course, under special situations you may still decide to use it, though it isn't advised.

		// (Current Status: Not Ready For Use)
		// ResetScene();
		// 	Debug::Log(EMessageType::INFO, "Successfully Reset PlatformerScene0.cpp", __FILENAME__, __LINE__);

}

void PlatformerScene0::Update(const float deltaTime) {
	PlatformerScene::Update(deltaTime);
	if (player->IsDead())
		GameSceneManager::getInstance()->LoadScene(GameSceneManager::ScreenState::GAMEOVER);
}

