#include "GameOver.h"
#include "framework/GameSceneManager.h"

using namespace GAME;

GameOver::GameOver(class Window& windowRef, class KeyboardManager& keymanRef) : Scene(windowRef, keymanRef)
{
	//Background texture & music
	backgroundTexture = new Texture(windowPtr->GetRenderer());
}


GameOver::~GameOver()
{
	delete backgroundTexture;
	backgroundTexture = nullptr;
	Debug::Log(EMessageType::INFO, "Successfully destroyed MainMenu.cpp", __FILENAME__, __LINE__);
}

void GameOver::HandleInput() {

};

bool GameOver::OnCreate(){
	/// Load Assets:
	/// Background

	if (!backgroundTexture->Load("res/textures/GameOver.jpg"))
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

void GameOver::Update(const float deltaTime){
	if (keyboardManager->IsPressed(Keyboard::Key::ESCAPE)) {
		GameSceneManager::getInstance()->LoadScene(GameSceneManager::ScreenState::MAINMENU);
	}
};

void GameOver::Render() const{
	windowPtr->ClearRenderer();

	//Draw bg
	backgroundTexture->Draw();

	SDL_RenderPresent(windowPtr->GetRenderer());
};