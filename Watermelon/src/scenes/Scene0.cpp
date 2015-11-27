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

	b2Shape* tmpShape = worldManager->CreateBoxShape(8, 16);
	b2FixtureDef* tmpFixtureDef = worldManager->CreateFixtureDef(1,1.0f,100,tmpShape);
	b2Body* tmpBody = worldManager->CreateBody(b2_dynamicBody, 10, 10, tmpFixtureDef);
	GameObject* player = new Player(*tmpBody, 10, 10);


	Texture* tmpTex = new Texture(windowPtr->GetRenderer());
	tmpTex->Load("res/placeholders/ph_player1.bmp");

	if (tmpTex == nullptr) {
		std::cout << "No Image" << std::endl;
	}

	player->SetSprite(*tmpTex);


	AddGameObjectToScene(player);

	tmpShape = worldManager->CreateBoxShape(100, 16);
	tmpFixtureDef = worldManager->CreateFixtureDef(1, 1.0f, 100, tmpShape);
	tmpBody = worldManager->CreateBody(b2_staticBody, 0, 70, tmpFixtureDef);
	GameObject* tmp = new Player(*tmpBody, 0, 70);

	AddGameObjectToScene(tmp);

	GetGameObjectWithBody(*tmpBody);

	tmpBody = worldManager->CreateBody(b2_staticBody, 0, 70, tmpFixtureDef);
	GetGameObjectWithBody(*tmpBody);


	
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
		std::cout << "Pressed SPACE" << std::endl;
	}

}

void Scene0::AddGameObjectToScene(GameObject* gameObjRef) {
	gameObjects->push_back(gameObjRef);
}

GameObject* Scene0::GetGameObjectWithBody(const b2Body& bodyRef) const {
	for (std::vector<GameObject*>::iterator it = gameObjects->begin(); it != gameObjects->end(); ++it) {
		GameObject* gameObject = *it;
		if (gameObject->GetBody() == &bodyRef) {
			std::cout << "Body Found" << std::endl;
			return gameObject;
		}
	}
	std::cout << "No Body Found" << std::endl;
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
};
