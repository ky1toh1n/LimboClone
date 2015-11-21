
#include <sstream>
#include "AudioFile.h"

#include "SDL_mixer.h"
#include "Debug.h"

using namespace GAME;

AudioFile::AudioFile() {

	const int mixFlags = MIX_INIT_MP3 | MIX_INIT_OGG;
	if (!(Mix_Init(mixFlags) == mixFlags)) {
		Debug::Log(EMessageType::FATAL_ERROR,"Failed to initialize SDL Mix!  SDL Error: " + std::string(SDL_GetError()),__FILENAME__,__LINE__);
	}	
	int audioFrequency = MIX_DEFAULT_FREQUENCY;
	Uint16 audioFormat = AUDIO_S16; /* 16-bit stereo */
	int audioChannels = MIX_DEFAULT_CHANNELS;
	int audioChunkSize = 4096;
	
	if (Mix_OpenAudio(audioFrequency, audioFormat, audioChannels, audioChunkSize)) {
		Debug::Log(EMessageType::FATAL_ERROR, "Failed to initialize SDL Mix Audio!  SDL Error: " + std::string(SDL_GetError()),__FILENAME__,__LINE__);
		
	}

	if (!Mix_QuerySpec(&audioFrequency, &audioFormat, &audioChannels)) {
		std::stringstream SS;
		SS << "Audio Rate: " << audioFrequency << ", Audio Format: " << audioFormat << ", Audio Channels: " << audioChannels;
		Debug::Log(EMessageType::WARNING, SS.str(), __FILENAME__,__LINE__);
	}
}
AudioFile::~AudioFile() {}


void AudioFile::SetMasterVolume(const int masterVolume) const {
	Mix_Volume(-1, masterVolume);
}

int AudioFile::GetMasterVolume() const {
	return Mix_Volume(-1, -1);
}
