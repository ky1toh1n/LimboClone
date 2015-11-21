
#include <sstream>
#include "Debug.h"
#include "Window.h"

using namespace GAME;

Window::Window():SDLWindow(nullptr), SDLRenderer(nullptr), SDLSurface(nullptr), winRect(), isInitialized(false), isFullScreen(false) {
		Debug::Log(EMessageType::INFO,  "Entering Window constructor", __FILENAME__, __LINE__);
}

Window::~Window() {
	Shutdown();
}

bool Window::Initialize() {
	isInitialized = false;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		Debug::Log(EMessageType::FATAL_ERROR,  std::string(SDL_GetError()), __FILENAME__, __LINE__);
		return isInitialized;
	}
	
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		Debug::Log(EMessageType::WARNING,  "Linear texture filtering is not enabled.", __FILENAME__, __LINE__);
	}

	SDLWindow = SDL_CreateWindow("SDL Game Project", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winRect.w, winRect.h, SDL_WINDOW_SHOWN);
	if (!SDLWindow) {
		Debug::Log(EMessageType::FATAL_ERROR, "Failed to create a window!", __FILENAME__, __LINE__);
		Shutdown();
		return false;
	}
	
	SDLRenderer = SDL_CreateRenderer(SDLWindow, -1, SDL_RENDERER_ACCELERATED);

	if (!SDLRenderer) {
		Debug::Log(EMessageType::FATAL_ERROR, std::string(SDL_GetError()), __FILENAME__, __LINE__);
		Shutdown();
		return false;
	}

	SDL_SetRenderDrawColor(SDLRenderer, 100, 100, 100, 255);
	SDL_RenderFillRect(SDLRenderer, &winRect);
	SDL_RenderPresent(SDLRenderer);
	SDLSurface = SDL_GetWindowSurface(SDLWindow);
	ClearRenderer();

	isInitialized = true;
	return true;
}

void Window::Shutdown() {
	SDL_FreeSurface(SDLSurface);
	SDLSurface = nullptr;
	SDL_DestroyRenderer(SDLRenderer);
	SDLRenderer = nullptr;
	SDL_DestroyWindow(SDLWindow);
	SDLWindow = nullptr;
	isInitialized = false;
}

void Window::SetWindowSize(const int width_, const int height_) {
	winRect.w = width_;
	winRect.h = height_;
}

void Window::ClearRenderer() const {
	SDL_SetRenderDrawColor(SDLRenderer, 255, 255, 255, 255);
	SDL_RenderClear(SDLRenderer);
}

void Window::ToggleFullScreen() {
	isFullScreen = !isFullScreen;
	SDL_SetWindowFullscreen(SDLWindow, (isFullScreen ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN));
}

SDL_Renderer* Window::GetRenderer() const {
	return SDLRenderer;
}

int Window::GetWidth() const {
	return winRect.w;
}

int Window::GetHeight() const {
	return winRect.h;
}