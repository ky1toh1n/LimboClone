#include "Scene0.h"


using namespace GAME;
using namespace std;

Scene0::Scene0(class Window& windowRef, class KeyboardManager& keymanRef):  Scene(windowRef, keymanRef) {
	
}

Scene0::~Scene0(){
	Debug::Log(EMessageType::INFO, "Successfully destroyed Scene0.cpp", __FILENAME__, __LINE__);
}

bool Scene0::OnCreate() {

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

	player = new Player(10, 10);

	Texture* tmpTex = new Texture(windowPtr->GetRenderer());
	tmpTex->Load("res/placeholders/ph_player1.bmp");

	if (tmpTex == nullptr) {
		std::cout << "No Image" << std::endl;
	}

	player->SetSprite(*tmpTex);


	
	Debug::Log(EMessageType::INFO, "Created Scene 0", __FILENAME__, __LINE__);
	return true;
}

void Scene0::OnDestroy(){
	/// Cleanup Assets
}

void Scene0::HandleInput() {
	if (keyboardManager->IsPressed(Keyboard::Key::A)) {
		std::cout << "Pressed A" << std::endl;
	}

	if (keyboardManager->IsPressed(Keyboard::Key::W)) {
		std::cout << "Pressed W" << std::endl;
	}

	if (keyboardManager->IsPressed(Keyboard::Key::S)) {
		std::cout << "Pressed S" << std::endl;
	}

	if (keyboardManager->IsPressed(Keyboard::Key::D)) {
		std::cout << "Pressed D" << std::endl;
	}

	if (keyboardManager->IsPressed(Keyboard::Key::SPACE)) {
		std::cout << "Pressed SPACE-DESU" << std::endl;
	}

}

void Scene0::Update(const float deltaTime){
	HandleInput();
	player->Update(deltaTime);
}

void Scene0::Render() const{
	windowPtr->ClearRenderer();
	/// Draw you scene
	backgroundTexture->Draw();
	player->Draw();
	

	SDL_RenderPresent(windowPtr->GetRenderer());
};
