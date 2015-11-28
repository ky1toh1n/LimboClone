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

	/////////////////////////////// End of Load Assets

	/// Create Game Objects!!!!!!!!!
	gameObjects = new std::vector<GameObject*>();


	camera = new OrthographicCamera();
	player = new Player(this, 50, 450);
	camera->SetFocus(player);
	Ground1024x32* groundZero = new Ground1024x32(this, 0, 500);

	Debug::Log(EMessageType::INFO, "Created Scene 0", __FILENAME__, __LINE__);
	return true;
}


void Scene0::CreateBoxGameObject(PhysicsObject* gameObjectPtr, const b2BodyType& type, const float32 x, const float32 y, const std::string& path) {
	// Attaches a Box b2Body to a GameObject
	
	Texture* tmpTex = new Texture(windowPtr->GetRenderer());
	tmpTex->Load(path);
	float32 width = (float32)tmpTex->GetWidth()/2;
	float32 height = (float32)tmpTex->GetHeight() / 2;

	b2Shape* tmpShape = worldManager->CreateBoxShape(width, height);
	b2FixtureDef* tmpFixtureDef = worldManager->CreateFixtureDef(0, 1, 1, tmpShape);
	//SWEEP! Add width and height ONLY if they are boxes!! This is to handle their centering issue.
	b2Body* tmpBody = worldManager->CreateBody(type, x + width, y + height, tmpFixtureDef);

	gameObjectPtr->SetBody(*tmpBody);
	gameObjectPtr->SetSprite(*tmpTex);

	AddGameObjectToScene(gameObjectPtr);
}

void Scene0::OnDestroy(){
	/// Cleanup Assets
}

void Scene0::HandleInput() {
	if (keyboardManager->IsPressed(Keyboard::Key::A)) {
		std::cout << "Pressed A" << std::endl;
		player->MoveLeft();
	}

	if (keyboardManager->IsPressed(Keyboard::Key::W)) {
		std::cout << "Pressed W" << std::endl;
	}

	if (keyboardManager->IsPressed(Keyboard::Key::S)) {
		std::cout << "Pressed S" << std::endl;
	}

	if (keyboardManager->IsPressed(Keyboard::Key::D)) {
		std::cout << "Pressed D" << std::endl;
		player->MoveRight();
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
		// gameObject->Draw();
		gameObject->Draw(camera->GetPosition().x, camera->GetPosition().y);
	} 
	std::cout << camera->GetPosition().x << std::endl;

	// SDL_RenderSetViewport(windowPtr->GetRenderer(), camera->GetRect());
	// SDL_Surface* screenSurface = windowPtr->GetWindowSurface();
	// SDL_Texture* currentScreen = SDL_CreateTextureFromSurface(windowPtr->GetRenderer(), screenSurface);



	SDL_RenderPresent(windowPtr->GetRenderer());
}
