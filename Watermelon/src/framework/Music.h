#ifndef MUSIC_H
#define MUSIC_H

#include "AudioFile.h"
#include <string>

/// This is called a forward declaration 
/// Geez,  I'm tired - go look it up - SSF
struct _Mix_Music;

namespace GAME {
	class Music : public AudioFile {
	public:
		Music();

		/// Delete the possible constructors and operators 
		Music(const Music&) = delete;
		Music(Music&&) = delete;
		Music& operator=(const Music&) = delete;
		Music& operator=(Music&&) = delete;

		~Music();

		virtual bool Load(const std::string& fileName) override;
		virtual void Play(const int loopCount = 0) const override;
		virtual void SetVolume(int volume) const override;
		virtual void Destroy() override;
		void Stop() const;
		void Pause() const;
		void Resume() const;
		void TogglePause() const;

	protected:
	private:
		_Mix_Music* mixMusic;
	};
}

#endif