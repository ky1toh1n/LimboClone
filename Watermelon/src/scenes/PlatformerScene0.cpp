#include "PlatformerScene0.h"
#include "framework/GameSceneManager.h"

using namespace GAME;

PlatformerScene0::PlatformerScene0(class Window& windowRef, class KeyboardManager& keymanRef): PlatformerScene(windowRef, keymanRef) {
	Debug::Log(EMessageType::INFO, "Successfully created PlatformerScene0.cpp", __FILENAME__, __LINE__);
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
	new Background(this, 2530, 195, camera);
	new Background(this, 3795, 195, camera);


	float x = 0, y = 0;

	for (int i = 0; i < 3; i++) {
		new Crate32x32(this, 0, (float32)210+i*32, b2_staticBody);
	}
	new Crate32x32(this, 190, 271, b2_staticBody);

	// new Crate32x32(this, 0, 241, b2_staticBody);
	//new Crate32x32(this, 0, 219, b2_staticBody);
	new Boulder64x64(this, 800, 250);
	new Ramp64x32LR(this, 1064, 250);
	//new Crate32x32(this, 1100, 250);
	new Crate32x32(this, 1400, 250);

	x = 1200;
	y = 240;
	new SeeSaw(this, x, y);
	new Crate32x32(this, x + 70, y, b2_staticBody);
	new Crate32x32(this, x + 86, y - 32, b2_staticBody);

	new Pulley(this, x + 800, y - 300);
	new Crate32x32(this, x + 720, y, b2_staticBody);
	


	new Boulder64x64(this, 575, 100);
	new Crate32x32(this, 420, 100, b2_staticBody);


	new Boulder64x64(this, 1864, 100); // Rock spawn on Pulley
	
	player = new Player(this, 80, 0);
	camera->SetFocus(player);

	new Ground1024x32(this, 0, 300);
	new Ground1024x32(this, 0, 132);

	new Ground1024x32(this, 1025, 268);
	new Ground1024x32(this, 3000, 268);

	Debug::Log(EMessageType::INFO, "Initialized PlatformerScene0", __FILENAME__, __LINE__);

	return true;
}



void PlatformerScene0::HandleInput() {
	player->HandleInput(keyboardManager->IsPressed(Keyboard::Action::MOVE_UP),
		keyboardManager->IsPressed(Keyboard::Action::MOVE_LEFT),
		keyboardManager->IsPressed(Keyboard::Action::MOVE_DOWN),
		keyboardManager->IsPressed(Keyboard::Action::MOVE_RIGHT),
		keyboardManager->IsPressed(Keyboard::Action::JUMP));

	

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

