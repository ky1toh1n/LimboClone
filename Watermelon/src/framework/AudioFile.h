#ifndef AUDIOFILE_H
#define AUDIOFILE_H

#include <string>

namespace GAME {
	
	class AudioFile {
	public:
		AudioFile();
		virtual ~AudioFile();
		void SetMasterVolume(const int masterVolume) const;
		int GetMasterVolume() const;
		/// Pure viturals
		virtual bool Load(const std::string& fileName) = 0;
		virtual void Play(const int loopCount = 0) const = 0;
		virtual void SetVolume(int volume) const = 0;
		virtual void Destroy() = 0;
	protected:
	private:
	};
}

#endif