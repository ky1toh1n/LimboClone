#pragma once
#include <memory>
#include <thread>
#include "Window.h"

#include "Scene.h"
#include "scenes/PlatformerScene0.h"
#include "scenes/MainMenu.h"
#include "scenes/GameOver.h"

namespace GAME {

	class GameSceneManager;

class GameSceneManager {
public:
	enum ScreenState{
		MAINMENU = 0,
		PLATFORMERSCENE0 = 1,
		GAMEOVER = 2
	};
private:
	
	GameSceneManager();
	~GameSceneManager();

public:
	GameSceneManager(const GameSceneManager&) = delete;
	GameSceneManager(GameSceneManager&&) = delete;
	GameSceneManager& operator=(const GameSceneManager&) = delete;
	GameSceneManager& operator=(GameSceneManager&&) = delete;

private:

	/// Notice that windowInstance is a stack variable here - see the 
	/// GameSceneManager constructor for the best way to initialize it 
	Window windowInstance;
	Scene *currentScene;

	/*
	Unique_ptr code is DISABLED due to it throwing exceptions. Revert to an older commit to obtain it.
	*/
	static GameSceneManager * instance;

	


private: 
	KeyboardManager keyboardManager;
	bool isRunning;
	unsigned int fps; /// Frames / second
	
	// I've modified the access level of the following methods from PUBLIC to PRIVATE,
	// because only the GameSceneManager uses these methods.
	bool Initialize();
	void Update(const float deltaTime);
	void Render();

public:
	static GameSceneManager* getInstance();
	void ThreadDemo(); /// Just a thread demo
	void Run();
	bool LoadScene(GameSceneManager::ScreenState state);
	
};

}