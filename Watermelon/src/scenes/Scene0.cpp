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

	gameObjects = new std::vector<GameObject*>();

	string s = "res/placeholders/ph_player1.png";
	b2BodyType t = b2_dynamicBody;
	CreateBoxGameObject(t, 10.0f, 10.0f, s);

	s = "res/placeholders/ground128x32.png";
	t = b2_staticBody;
	CreateBoxGameObject(t, 10.0f, 100.0f, s);


	Debug::Log(EMessageType::INFO, "Created Scene 0", __FILENAME__, __LINE__);
	return true;
}


void Scene0::CreateBoxGameObject(const b2BodyType& type, const float32 x, const float32 y, const std::string& path) {

	Texture* tmpTex = new Texture(windowPtr->GetRenderer());
	tmpTex->Load(path);
	float32 width = tmpTex->GetWidth()/2;
	float32 height = tmpTex->GetHeight()/2;


	b2Shape* tmpShape = worldManager->CreateBoxShape(width, height);
	b2FixtureDef* tmpFixtureDef = worldManager->CreateFixtureDef(1, 0.2f, 100, tmpShape);
	b2Body* tmpBody = worldManager->CreateBody(type, x, y, tmpFixtureDef);
	GameObject* gameObject = new Player(*tmpBody);

	gameObject->SetSprite(*tmpTex);

	AddGameObjectToScene(gameObject);
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
		std::cout << "Pressed SPACE" << std::endl;
	}

}

void Scene0::AddGameObjectToScene(GameObject* gameObjRef) {
	gameObjects->push_back(gameObjRef);
}

void Scene0::Update(const float deltaTime){
	HandleInput();

	// TODO: Nicco/Adam Simplify, put in a separate function or something
	for (std::vector<GameObject*>::iterator it = gameObjects->begin(); it != gameObjects->end(); ++it) {
		GameObject* gameObject = *it;
		gameObject->Update(deltaTime);
	}
	worldManager->Update(deltaTime);
}

void Scene0::Render() const{
	windowPtr->ClearRenderer();
	/// Draw you scene
	backgroundTexture->Draw();

	// TODO: Nicco/Adam Simplify, put in a separate function or something
	for (std::vector<GameObject*>::iterator it = gameObjects->begin(); it != gameObjects->end(); ++it) {
		GameObject* gameObject = *it;
		gameObject->Draw();
	}
	SDL_RenderPresent(windowPtr->GetRenderer());
}
