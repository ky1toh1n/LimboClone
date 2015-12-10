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
	Debug::Log(EMessageType::INFO, "Successfully created PlatformerScene.cpp", __FILENAME__, __LINE__);
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

void PlatformerScene::AddToScene(GameObject* gameObjPtr) {
	gameObjects->push_back(gameObjPtr);
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
	Texture* tmpTex = LoadTexture(path, SDL_BLENDMODE_BLEND);

	//Box creation
	b2Body * tmpBody = worldManager->CreateBox(x, y, (float32)tmpTex->GetWidth(), (float32)tmpTex->GetHeight(),
		type, friction, restitution, density);
	tmpBody->SetUserData(gameObjectPtr);
		

	BindToScene(tmpTex, tmpBody, gameObjectPtr);
	gameObjectPtr->Print();
}

void PlatformerScene::CreateCircleGameObject(PhysicsObject* gameObjectPtr, const std::string& path,
	const float32 x, const float32 y, const b2BodyType& type, const float32 radius, const float32 friction,
	const float32 restitution, const float32 density) {
	//Load texture
	Texture* tmpTex = LoadTexture(path, SDL_BLENDMODE_BLEND);

	//Box creation
	b2Body * tmpBody = worldManager->CreateCircle(x, y, radius,
		type, friction, restitution, density);

	BindToScene(tmpTex, tmpBody, gameObjectPtr);
}

void PlatformerScene::CreateTriangleGameObject(PhysicsObject* gameObjectPtr, const std::string& path,
	const float32 x, const float32 y, const b2Vec2 vertices[], const b2BodyType& type,
	const float32 friction, const float32 restitution,
	const float32 density)
{
	//Load texture
	Texture* tmpTex = LoadTexture(path, SDL_BLENDMODE_BLEND);

	//Box creation
	b2Body * tmpBody = worldManager->CreatePolygon(x, y, vertices, 3,
		(float32)tmpTex->GetWidth(), (float32)tmpTex->GetHeight(), type, friction, restitution, density);

	BindToScene(tmpTex, tmpBody, gameObjectPtr);
}


b2Joint* PlatformerScene::CreateRevoluteJoint(const b2JointDef& jointDef) const {
	return (b2RevoluteJoint*)worldManager->CreateJoint(jointDef);
}

b2Joint* PlatformerScene::CreatePulleyJoint(const b2JointDef& jointDef) const {
	return (b2PulleyJoint*)worldManager->CreateJoint(jointDef);
}

void PlatformerScene::BindToScene(Texture* tmpTex, b2Body * tmpBody, PhysicsObject * gameObjectPtr){
	//Binding b2Body to GameObject
	tmpBody->SetUserData(gameObjectPtr);
	gameObjectPtr->SetBody(*tmpBody);
	gameObjectPtr->SetSprite(*tmpTex);

	//Add to PlatformerScene
	AddToScene(gameObjectPtr);
	//gameObjectPtr->Print();
}

Texture* PlatformerScene::LoadTexture(const string& path, const SDL_BlendMode blendType) const {
	Texture* tmpTex = new Texture(windowPtr->GetRenderer());
	tmpTex->Load(path);
	tmpTex->SetBlendMode(blendType);
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
	camera->Render();
	//Draw bg
	backgroundTexture->Draw();

	//Draw actors
	// Sorry replaced it for now, not sure how to get it to work
	for (std::vector<GameObject*>::iterator it = gameObjects->begin(); it != gameObjects->end(); ++it) {
		GameObject* gameObject = *it;
		gameObject->Draw((int)camera->GetPosition().x, (int)camera->GetPosition().y);
	}
	
	// for_each(gameObjects->begin(), gameObjects->end(),
	//	bind(&GameObject::Draw, _1, camera->GetPosition().x, camera->GetPosition().y));

	
	//Camera-disabled draw
	/*
	for_each(gameObjects->begin(), gameObjects->end(),
		bind(&GameObject::Draw, _1, 0, 1));
	*/
	SDL_RenderPresent(windowPtr->GetRenderer());
}
