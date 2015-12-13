#include "MainMenu.h"
#include "framework/GameSceneManager.h"

using namespace GAME;

MainMenu::MainMenu(class Window& windowRef, class KeyboardManager& keymanRef) : Scene(windowRef, keymanRef)
{
	//Background texture & music
	backgroundTexture = new Texture(windowPtr->GetRenderer());
	Debug::Log(EMessageType::INFO, "Successfully created MainMenu.cpp", __FILENAME__, __LINE__);
}


MainMenu::~MainMenu()
{
	delete backgroundTexture;
	backgroundTexture = nullptr;
	Debug::Log(EMessageType::INFO, "Successfully destroyed MainMenu.cpp", __FILENAME__, __LINE__);
}

void MainMenu::HandleInput() {

};

bool MainMenu::OnCreate(){
	/// Load Assets:
	/// Background

	if (!backgroundTexture->Load("res/textures/limb800x600B.bmp"))
	{
		return false;
	}


	/// Title
	/// SoundEffects
	/// Models needed for this scene
	/// Music
	if (!backgroundMusic->Load("res/bgm/Martin Stig Andersen - Limbo (Original Videogame Soundtrack) - 01 Menu.wav"))
	{
		return false;
	}
	backgroundMusic->Play(std::numeric_limits<int>::max());
	return true;
};

void MainMenu::Update(const float deltaTime){
	if (keyboardManager->IsPressed(Keyboard::Action::TO_NEXT_SCREEN)) {
		GameSceneManager::getInstance()->LoadScene(GameSceneManager::ScreenState::PLATFORMERSCENE0);
	}
};

void MainMenu::Render() const{
	windowPtr->ClearRenderer();

	//Draw bg
	backgroundTexture->Draw();

	SDL_RenderPresent(windowPtr->GetRenderer());
};