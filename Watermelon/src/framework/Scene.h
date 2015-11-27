#ifndef SCENE_H
#define SCENE_H

#include "SDL.h"
#include "Window.h"
#include "Texture.h"
#include "Music.h"
#include "ContactListener.h"
#include "WorldManager.h"
#include "GameObject.h"
#include <vector>

namespace GAME {
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
		virtual GameObject* GetGameObjectWithBody(const b2Body& bodyRef) const = 0;

		virtual void Update(const float deltaTime) = 0;
		virtual void Render() const = 0;

	protected:
		Window* windowPtr;
		KeyboardManager* keyboardManager;

		//Assets
		Music* backgroundMusic;
		Texture* backgroundTexture;

		// Collections

		// TODO: Adam
		// switch to whatever container you think is best
		std::vector<GameObject*>* gameObjects;

		//Box2D
		WorldManager* worldManager;
		ContactListener* contactListener;
	};
}

#endif