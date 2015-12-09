#pragma once
#include <memory>
#include <thread>
#include "Window.h"

#include "Scene.h"
#include "scenes/PlatformerScene0.h"
#include "scenes/MainMenu.h"
#include "scenes/GameOver.h"

namespace GAME {

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
	//PlatformerScene *currentScene;
	Scene *currentScene;

	///std::unique_ptr is a smart pointer that destroys the object it point to when the unique_ptr goes out of scope.
	static std::unique_ptr<GameSceneManager> instance;

	/// Since my destructor is private the template std::unique_ptr needs access so I made it a friend.
	/// However, std::default_delete is the default destruction policy used by std::unique_ptr 
	/// when no deleter is specified, therefore I'll make std::default_delete my friend as well. 
	friend std::default_delete<GameSceneManager>;



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
	void LoadScene(GameSceneManager::ScreenState state);
	
};

}