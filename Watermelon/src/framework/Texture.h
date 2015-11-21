#ifndef TEXTURE_H
#define TEXTURE_H

#include "SDL.h"
#include <string>

namespace GAME {
	class Texture {
		struct DrawParams {
			int x;
			int y;
			float scale;
			SDL_Rect*clip;
			double angle;
			SDL_Point* center;
			SDL_RendererFlip flip;
		};
	private:
		SDL_Texture* SDLTexture;
		SDL_Renderer* SDLRenderer;
		int width;
		int height;
	public:
		explicit Texture(SDL_Renderer* Renderer);
		Texture(const Texture&) = delete;
		Texture(Texture&&) = delete;
		Texture& operator=(const Texture&) = delete;
		Texture& operator=(Texture&&) = delete;

		~Texture();
		bool Load(const std::string& fileName);
		void SetTexture(SDL_Texture& SDLTexture_, const int width_, const int height_);
		void Destroy();
		void Draw(const DrawParams& params) const;
		void Draw(const int x = 0,const int y = 0,const float scale = 1,SDL_Rect* clip = nullptr,
				  const double angle = 0, SDL_Point* center = nullptr,
				  const SDL_RendererFlip flip = SDL_RendererFlip::SDL_FLIP_NONE) const;
		void SetAlpha(const Uint8 a);
		void SetBlendMode(const SDL_BlendMode blendMode_);
		void SetColor(const SDL_Color& color_);
		void SetColor(const Uint8 r, const Uint8 g_, const Uint8 b_, const Uint8 a_);
		int  GetWidth() const;
		int  GetHeight() const;

	
	};
}

#endif
