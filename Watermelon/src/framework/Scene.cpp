#include "Scene.h"

using namespace GAME;

Scene::Scene(Window& windowRef, KeyboardManager& keymanRef) : windowPtr(&windowRef), keyboardManager(&keymanRef) {
	///Heap allocation for things that every Scene needs:
	//Background music
	backgroundMusic = new Music();
	Debug::Log(EMessageType::INFO, "Sucessfully created Scene.cpp", __FILENAME__, __LINE__);
}

Scene::~Scene() {
	delete backgroundMusic;
	backgroundMusic = nullptr;
	Debug::Log(EMessageType::INFO, "Successfully destroyed Scene.cpp", __FILENAME__, __LINE__);
}
