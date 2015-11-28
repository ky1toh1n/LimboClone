#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "SDL.h"
#include "Window.h"
#include "Texture.h"
#include "Music.h"
#include "ContactListener.h"
#include "WorldManager.h"
#include "GameObject.h"
#include "PhysicsObject.h"
#include "OrthographicCamera.h"


namespace GAME {
	class Player;

	class Scene {
	public:
		explicit Scene(class Window& windowRef, class KeyboardManager& keymanRef);
		virtual ~Scene();

		Scene(const Scene&) = delete;
		Scene(Scene&&) = delete;
		Scene& operator = (const Scene&) = delete;
		Scene& operator = (Scene&&) = delete;

		/// Create the following four abstract functions and make them polymorphic
		/// The proper term for these are "pure virtuals"
		virtual bool OnCreate() = 0;
		virtual void OnDestroy() = 0;
		virtual void HandleInput() = 0;

		virtual void AddGameObjectToScene(GameObject* gameObjPtr) = 0;
		virtual void CreateBoxGameObject(PhysicsObject* gameObjectPtr, const b2BodyType& type,
			const float32 x, const float32 y, const std::string& path) = 0;

		virtual void Update(const float deltaTime) = 0;
		virtual void Render() const = 0;

	protected:
		Window* windowPtr;
		KeyboardManager* keyboardManager;

		//Assets
		Music* backgroundMusic;
		Texture* backgroundTexture;

		// Collections
		OrthographicCamera* camera;
		Player* player;

		// TODO: Adam
		// switch to whatever container you think is best
		std::vector<GameObject*>* gameObjects;

		//Box2D
		WorldManager* worldManager;
		ContactListener* contactListener;
	};
}

#endif