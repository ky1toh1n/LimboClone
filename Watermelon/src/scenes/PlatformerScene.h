#ifndef PlatformerScene_H
#define PlatformerScene_H

#include "SDL.h"

#include "framework/Scene.h"
#include "framework/Window.h"
#include "framework/Texture.h"
#include "framework/Music.h"
#include "framework/ContactListener.h"
#include "framework/WorldManager.h"
#include "gameobjects/GameObject.h"
#include "gameobjects/PhysicsObject.h"
#include "framework/OrthographicCamera.h"

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
		void AddToScene(GameObject* gameObjPtr);

		Texture* LoadTexture(const std::string& path, const SDL_BlendMode blendType = SDL_BLENDMODE_NONE) const;

		void CreateBoxGameObject(PhysicsObject* gameObjectPtr, const std::string& path,
			const float32 x, const float32 y, const b2BodyType& type, const float32 friction = WorldManager::DEF_FRICTION,
			const float32 restitution = WorldManager::DEF_RESTITUTION, const float32 density = WorldManager::DEF_DENSITY);
		
		void CreateCircleGameObject(PhysicsObject* gameObjectPtr, const std::string& path,
			const float32 x, const float32 y, const b2BodyType& type, const float32 friction = WorldManager::DEF_FRICTION,
			const float32 restitution = WorldManager::DEF_RESTITUTION, const float32 density = WorldManager::DEF_DENSITY);
		
		void CreateTriangleGameObject(PhysicsObject* gameObjectPtr, const std::string& path,
			const float32 x, const float32 y, const b2Vec2 vertices[], const b2BodyType& type,
			const float32 friction = WorldManager::DEF_FRICTION, const float32 restitution = WorldManager::DEF_RESTITUTION,
			const float32 density = WorldManager::DEF_DENSITY);

		b2Joint* CreateJoint(b2Body* bodyA, b2Body* bodyB, const bool collideConnected);

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
		std::vector<GameObject*>* gameObjects;
		Player* player;

	private:
		void BindToScene(Texture* tmpTex, b2Body * tmpBody, PhysicsObject * gameObjectPtr);
	};
}

#endif