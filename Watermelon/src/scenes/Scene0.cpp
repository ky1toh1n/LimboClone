#include "Scene0.h"


using namespace GAME;

Scene0::Scene0(class Window& windowRef):  Scene(windowRef) { }
Scene0::~Scene0(){}



bool Scene0::OnCreate() {
	/// Load Assets:
	/// Background
	backgroundTexture = new Texture(windowPtr->GetRenderer());
	backgroundTexture->Load("res/textures/limb800x600.bmp");

	/// Title
	/// SoundEffects
	/// Models needed for this scene

	/// Load Box2D
	contactListener = new ContactListener();
	worldManager = new WorldManager(*contactListener);


	/// Music
	backgroundMusic = new Music();
	backgroundMusic->Load("res/bgm/Martin Stig Andersen - Limbo (Original Videogame Soundtrack) - 01 Menu.wav");
	backgroundMusic->Play();
	
	Debug::Log(EMessageType::INFO, "Created Scene 0", __FILENAME__, __LINE__);
	return true;
}
void Scene0::OnDestroy(){
	/// Cleanup Assets

}
void Scene0::Update(const float deltaTime){}


void Scene0::Render() const{
	windowPtr->ClearRenderer();
	/// Draw you scene
	backgroundTexture->Draw();
	

	SDL_RenderPresent(windowPtr->GetRenderer());
};
