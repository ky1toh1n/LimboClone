#include "Main.h"

using namespace GAME;

int main(int, char**){
	//Initializes debug log
	Debug::Init();

	//Creates and starts the game
	GameSceneManager * gameSceneManager = GameSceneManager::getInstance();
	gameSceneManager->Run();

	return 0;
}