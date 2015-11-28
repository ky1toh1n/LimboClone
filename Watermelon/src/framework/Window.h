#ifndef WINDOW_H
#define WINDOW_H

#include "SDL.h"

namespace GAME {
	class Window {
	public:
		Window();
		~Window();

		/// C11 precautions delete these non-needed default constructors and operators
		Window(const Window&) = delete;
		Window(Window&&) = delete;
		Window& operator = (const Window&) = delete;
		Window& operator = (Window&&) = delete;
		
		bool Initialize();
		void Shutdown();
		void ClearRenderer() const;
		void SetWindowSize(const int Width_, const int Height_);
		void ToggleFullScreen();
		SDL_Surface* GetWindowSurface() const;
		SDL_Renderer* GetRenderer() const;
		int GetWidth() const;
		int GetHeight() const;

	protected:
	private:
		SDL_Window* SDLWindow;
		SDL_Renderer* SDLRenderer;
		SDL_Surface* SDLSurface;

		SDL_Rect winRect;

		bool isInitialized;
		bool isFullScreen;
	};
}

#endif