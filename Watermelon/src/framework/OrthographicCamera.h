#ifndef ORTHOGRAPHIC_CAMERA_H
#define ORTHOGRAPHIC_CAMERA_H

#include "gameobjects/GameObject.h"
#include "framework/Vector.h"
using namespace MATH;

namespace GAME {

	class OrthographicCamera {
	public:
		OrthographicCamera(const int x = 0, const int y = 0, const int width = 800, const int height = 600);
		~OrthographicCamera();

		OrthographicCamera(const OrthographicCamera&) = delete;
		OrthographicCamera(OrthographicCamera &&) = delete;
		OrthographicCamera& operator=(const OrthographicCamera &) = delete;
		OrthographicCamera& operator=(OrthographicCamera &&) = delete;

		void SetFocus(const GameObject* focusPtr);
		Vec2 GetPosition() const;
		SDL_Rect* GetRect() const;
		void Render(); // Put this on the render call, not Update

	public:
		SDL_Rect* cam;

	private:
		const GameObject* focus;
	};
}


#endif