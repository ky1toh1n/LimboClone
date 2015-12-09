#include "Scene.h"

using namespace GAME;

Scene::Scene(Window& windowRef, KeyboardManager& keymanRef) : windowPtr(&windowRef), keyboardManager(&keymanRef) {
	///Heap allocation for things that every Scene needs:
	//Background music
	backgroundMusic = new Music();
}

Scene::~Scene() {
	delete windowPtr;
	windowPtr = nullptr;
	delete backgroundMusic;
	backgroundMusic = nullptr;
	Debug::Log(EMessageType::INFO, "Successfully destroyed Scene.cpp", __FILENAME__, __LINE__);
}
