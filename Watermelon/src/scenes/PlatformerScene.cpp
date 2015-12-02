#include "PlatformerScene.h"

using namespace GAME;
using namespace std;
using namespace std::placeholders;

PlatformerScene::PlatformerScene(Window& windowRef, KeyboardManager& keymanRef) : Scene(windowRef, keymanRef) {
	///Heap allocation for things that every PlatformerScene needs:
	//Background texture & music
	backgroundTexture = new Texture(windowPtr->GetRenderer());

	//Box2D physics
	contactListener = new ContactListener(gameObjects);
	worldManager = new WorldManager(*contactListener);

	//Framework
	gameObjects = new std::vector<GameObject*>();
	camera = new OrthographicCamera();
}

PlatformerScene::~PlatformerScene() {
	delete backgroundTexture;
	backgroundTexture = nullptr;
	delete contactListener;
	contactListener = nullptr;
	delete worldManager;
	worldManager = nullptr;
	delete gameObjects;
	gameObjects = nullptr;
	delete camera;
	camera = nullptr;
	Debug::Log(EMessageType::INFO, "Successfully destroyed PlatformerScene.cpp", __FILENAME__, __LINE__);
}

bool PlatformerScene::OnCreate() {
	if (!LoadAssets()) { return false; }
	if (!LoadActors()) { return false; }
	return true;
}

void PlatformerScene::AddToScene(GameObject* gameObjRef) {
	gameObjects->push_back(gameObjRef);
}

/*
The 'create' functions are responsible for:
-Creates a b2Body via WorldManager
-Attaches the b2Body to a GameObject
-Adds the GameObject to the PlatformerScene.
*/
void PlatformerScene::CreateBoxGameObject(PhysicsObject* gameObjectPtr, const std::string& path,
	const float32 x, const float32 y, const b2BodyType& type, const float32 friction,
	const float32 restitution, const float32 density) {
	//Load texture
	Texture* tmpTex = LoadTexture(path);

	//Box creation
	b2Body * tmpBody = worldManager->CreateBox(x, y, (float32)tmpTex->GetWidth(), (float32)tmpTex->GetHeight(),
		type, friction, restitution, density);

	BindToScene(tmpTex, tmpBody, gameObjectPtr);
}

void PlatformerScene::CreateCircleGameObject(PhysicsObject* gameObjectPtr, const std::string& path,
	const float32 x, const float32 y, const b2BodyType& type, const float32 friction,
	const float32 restitution, const float32 density) {
	//Load texture
	Texture* tmpTex = LoadTexture(path);
	
	#ifndef _DEBUG 
		if (tmpTex->GetWidth() != tmpTex->GetHeight())
		{Debug::Log(EMessageType::ERROR, "Texture's width and height are not equal: " + path, __FILENAME__, __LINE__);}
	#endif

	//Box creation
	b2Body * tmpBody = worldManager->CreateCircle(x, y, (float32)tmpTex->GetWidth() / 2,
		type, friction, restitution, density);

	BindToScene(tmpTex, tmpBody, gameObjectPtr);

	gameObjectPtr->Print();
}

void PlatformerScene::BindToScene(Texture* tmpTex, b2Body * tmpBody, PhysicsObject * gameObjectPtr){
	//Binding b2Body to GameObject
	tmpBody->SetUserData(gameObjectPtr);
	gameObjectPtr->SetBody(*tmpBody);
	gameObjectPtr->SetSprite(*tmpTex);

	//Add to PlatformerScene
	AddToScene(gameObjectPtr);
}

Texture* PlatformerScene::LoadTexture(const string& path) const {
	Texture* tmpTex = new Texture(windowPtr->GetRenderer());
	tmpTex->Load(path);
	return tmpTex;
}

void PlatformerScene::Update(const float deltaTime){
	HandleInput();

	//Update players & World
	for_each(gameObjects->begin(), gameObjects->end(), bind(&GameObject::Update, _1, deltaTime));
	worldManager->Update(deltaTime);
}

void PlatformerScene::Render() const{
	windowPtr->ClearRenderer();

	//Draw bg
	backgroundTexture->Draw();

	//Draw actors
	
	for_each(gameObjects->begin(), gameObjects->end(),
		bind(&GameObject::Draw, _1, camera->GetPosition().x, camera->GetPosition().y));

	/*//Camera-disabling
	for_each(gameObjects->begin(), gameObjects->end(),
		bind(&GameObject::Draw, _1, 0, 1));
	*/

	SDL_RenderPresent(windowPtr->GetRenderer());
}
