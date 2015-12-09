#include <iostream>
#include <thread> /// New in C11
#include <cassert>
#include "GameSceneManager.h"
#include "Debug.h"
#include "Timer.h"

using namespace GAME;

/// See the header file reguarding unique_ptr
std::unique_ptr<GameSceneManager> GameSceneManager::instance(nullptr);

GameSceneManager* GameSceneManager::getInstance(){
	if (instance.get() == nullptr){
		/// I originally set the unique_ptr to be null in the constructor - 
		/// reset() sets the new address
		instance.reset(new GameSceneManager());
	}
	return instance.get();
}

GameSceneManager::GameSceneManager() : windowInstance(), currentScene(nullptr),isRunning(false),fps(60) {
	Debug::Log(EMessageType::INFO, "Sucessfully created GameSceneManager.cpp", __FILENAME__, __LINE__);
}

GameSceneManager::~GameSceneManager(){
	windowInstance.Shutdown();
	delete currentScene;
	currentScene = nullptr;
	isRunning = false;
	Debug::Log(EMessageType::INFO, "Sucessfully destroyed GameSceneManager.cpp", __FILENAME__, __LINE__);
}




void GameSceneManager::ThreadDemo(){  /// Just a threading demo
	Debug::Log(EMessageType::INFO, "Running", __FILENAME__, __LINE__);
	for(int i = 0 ; i < 30; ++i){
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		std::cout << i << " :Hello from thread " << std::endl;
	}
}



bool GameSceneManager::Initialize(){
	Debug::Log(EMessageType::INFO, "Initializing" ,__FILENAME__, __LINE__);
	windowInstance.SetWindowSize(800, 600);
	if (!windowInstance.Initialize()) {
		Debug::Log(EMessageType::FATAL_ERROR, "Failed to initialize a GUI Window!",__FILENAME__, __LINE__);
		return false;
	}

	keyboardManager.Initialize();
	
	return LoadScene(MAINMENU);
}

bool GameSceneManager::LoadScene(GameSceneManager::ScreenState state){
	switch (state){
		case MAINMENU:
			currentScene = new MainMenu(windowInstance, keyboardManager);
			break;
		case PLATFORMERSCENE0:
			currentScene = new PlatformerScene0(windowInstance, keyboardManager);
			break;
		case GAMEOVER:
			currentScene = new GameOver(windowInstance, keyboardManager);
			break;
		default:
			Debug::Log(EMessageType::FATAL_ERROR, "ScreenState is unhandled! " + state, __FILENAME__, __LINE__);
			throw state;
			break;
	}

	if (!currentScene->OnCreate()){
		Debug::Log(EMessageType::FATAL_ERROR, "Failed to create a Scene!", __FILENAME__, __LINE__);
		return false;
	}
	return true;
}

void GameSceneManager::Run(){
	isRunning = Initialize();
	Timer timer;
	timer.Start();

	while ( isRunning ) {
		timer.UpdateFrameTicks();

		/// This id the guts of the loop update everyone then render everyone
		Update(timer.GetDeltaTime());
		Render();

		/// Keeep the event loop running at a sane rate
		SDL_Delay(timer.GetSleepTime(fps));
		// std::cout << "main loop running at: " << timer.GetDeltaTime() << "sec/frame" << std::endl;
		
	}
}


void GameSceneManager::Update(const float deltaTime) {
	SDL_Event SDLEvent;
	
	while (SDL_PollEvent(&SDLEvent)) {
		switch (SDLEvent.type) {
			case SDL_EventType::SDL_QUIT:
				isRunning = false;
				return;
			case Keyboard::State::KEYDOWN:
				keyboardManager.OnPress(SDLEvent.key.keysym.scancode);
				break;
			case Keyboard::State::KEYUP:
				keyboardManager.OnRelease(SDLEvent.key.keysym.scancode);
				break;
			default:  
				break;
		}
	}


	if(currentScene) currentScene->Update(deltaTime);
}



void GameSceneManager::Render(){
	if(currentScene == nullptr){
		Debug::Log(EMessageType::ERROR,"No scene selected as current scene",__FILENAME__,__LINE__);
		assert(currentScene); 
	}
	currentScene->Render();
} 