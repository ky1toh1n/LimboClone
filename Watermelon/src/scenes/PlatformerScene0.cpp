#include "PlatformerScene0.h"

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

	player = new Player(this, 50, 30);
	camera->SetFocus(player);

	
	new Ground1024x32(this, 0, 500);

	// Testing collisions
	//new Block64x32(this, 250, 0);
	new Block64x32(this, 350, 50);
	new Block64x32(this, 450, 100);
	new Circle64x64(this, 300, -50);

	Debug::Log(EMessageType::INFO, "Created Scene 0", __FILENAME__, __LINE__);
	return true;
}

void PlatformerScene0::HandleInput() {
	if (keyboardManager->IsPressed(Keyboard::Key::A)) {
		// std::cout << "Pressed A" << std::endl;
		player->MoveLeft();
	}

	if (keyboardManager->IsPressed(Keyboard::Key::W)) {
		// std::cout << "Pressed W" << std::endl;
	}

	if (keyboardManager->IsPressed(Keyboard::Key::S)) {
		// std::cout << "Pressed S" << std::endl;
	}

	if (keyboardManager->IsPressed(Keyboard::Key::D)) {
		// std::cout << "Pressed D" << std::endl;
		player->MoveRight();
	}

	if (keyboardManager->IsPressed(Keyboard::Key::SPACE)) {
		// std::cout << "Pressed SPACE" << std::endl;
		player->Jump();
	}
}

