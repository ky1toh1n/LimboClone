#ifndef SCENE_H
#define SCENE_H

#include "SDL.h"
#include "Window.h"

namespace GAME {
	class Scene {
	public:
		explicit Scene(class Window& windowRef);
		virtual ~Scene();

		Scene(const Scene&) = delete;
		Scene(Scene&&) = delete;
		Scene& operator = (const Scene&) = delete;
		Scene& operator = (Scene&&) = delete;
		
		

		/// Create the following four abstract functions and make them polymorphic
		/// The proper term for these are "pure viruals"
		virtual bool OnCreate() = 0;
		virtual void OnDestroy() = 0;
		virtual void Update(const float deltaTime) = 0;
		virtual void Render() const = 0;

	protected:
		Window* windowPtr;

	};
}

#endif