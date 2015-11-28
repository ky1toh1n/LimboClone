#ifndef Scene0_H
#define Scene0_H

#include "Scene.h"
#include "Window.h"
#include "Debug.h"

#include "GameObject.h"
#include "Player.h"
#include "Ground1024x32.h"

#include "KeyboardManager.h"

namespace GAME {
	class Scene0 : public Scene  {
	public:
		explicit Scene0(Window& windowRef, KeyboardManager& keymanRef);
		virtual ~Scene0();

		Scene0(const Scene0&) = delete;
		Scene0(Scene0 &&) = delete;
		Scene0& operator=(const Scene0 &) = delete;
		Scene0& operator=(Scene0 &&) = delete;

		virtual bool OnCreate() ;
		virtual void OnDestroy();
		virtual void HandleInput();

		virtual void AddGameObjectToScene(GameObject* gameObjPtr);
		virtual void CreateBoxGameObject(PhysicsObject* gameObjectPtr, const b2BodyType& type,
			const float32 x, const float32 y, const std::string& path);
		
		virtual void Update(const float deltaTime);
		virtual void Render() const;


	private:
		Music * bgm;
		Texture * bg;
		
	};
}
#endif