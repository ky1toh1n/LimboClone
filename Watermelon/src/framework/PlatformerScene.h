#ifndef PlatformerScene_H
#define PlatformerScene_H

#include "SDL.h"

#include "Scene.h"
#include "Window.h"
#include "Texture.h"
#include "Music.h"
#include "ContactListener.h"
#include "WorldManager.h"
#include "GameObject.h"
#include "PhysicsObject.h"
#include "OrthographicCamera.h"

#include <vector>
#include <functional>

namespace GAME {
	//Forward declarations
	class Player;

	/*
	The PlatformerScene is an abstract scene that represents a 2D platformer Limbo-esque level.
	*/
	class PlatformerScene : public Scene {
	public:
		//Constructor, destructor, C11 deletes
		explicit PlatformerScene(class Window& windowRef, class KeyboardManager& keymanRef);
		virtual ~PlatformerScene();
		PlatformerScene(const PlatformerScene&) = delete;
		PlatformerScene(PlatformerScene&&) = delete;
		PlatformerScene& operator = (const PlatformerScene&) = delete;
		PlatformerScene& operator = (PlatformerScene&&) = delete;

		//Concrete functions
		virtual bool OnCreate();
		virtual void Update(const float deltaTime);
		virtual void Render() const;
		void AddGameObjectToPlatformerScene(GameObject* gameObjPtr);
		void CreateBoxGameObject(PhysicsObject* gameObjectPtr, const b2BodyType& type,
			const float32 x, const float32 y, const std::string& path);

	protected:
		//Abstract functions
		virtual bool LoadActors() = 0;
		virtual bool LoadAssets() = 0;

		///Members:
		//Assets
		Texture* backgroundTexture;

		//Box2D
		WorldManager* worldManager;
		ContactListener* contactListener;

		//Collections
		OrthographicCamera* camera;
		// TODO: We won't have a lot of entities so we shouldn't have to worry about scale. 
		// Meaning, I am fine with any kind of container. YOLO!
		std::vector<GameObject*>* gameObjects;
		Player* player;
	};
}

#endif