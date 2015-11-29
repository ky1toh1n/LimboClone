#include "Main.h"

using namespace GAME;

int main(int, char**){
	static_assert(sizeof(void*) == 4, "Code-base is designed for 32-bit architectures.");

	//Initializes debug log
	Debug::Init();

	//Creates and starts the game
	GameSceneManager * gameSceneManager = GameSceneManager::getInstance();
	gameSceneManager->Run();

	return 0;
}