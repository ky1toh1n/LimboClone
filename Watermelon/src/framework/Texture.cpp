#include "Texture.h"

#include "SDL_image.h"

#include "Debug.h"

using namespace GAME;

Texture::Texture(SDL_Renderer* sdlRenderer): SDLTexture(nullptr), SDLRenderer(sdlRenderer), width(0), height(0) {}

Texture::~Texture() {
	Destroy();
}

bool Texture::Load(const std::string& FileName) {
	Destroy();
	SDL_Texture* NewSDLTexture = nullptr;

	SDL_Surface* LoadedSurface = IMG_Load(FileName.c_str());
	if (!LoadedSurface) {
		Debug::Log(EMessageType::ERROR,  "Failed to load " + FileName + "  SDL Error: " + SDL_GetError(), __FILENAME__, __LINE__);
	} else {
		if (SDL_SetColorKey(LoadedSurface, SDL_TRUE, SDL_MapRGB(LoadedSurface->format, 0, 0xFF, 0xFF)) < 0) {
			Debug::Log(EMessageType::WARNING, "Failed to set color key for " + FileName + ".  SDL Error: " + SDL_GetError(),__FILENAME__, __LINE__);
		}

		NewSDLTexture = SDL_CreateTextureFromSurface(SDLRenderer, LoadedSurface);
		if (!NewSDLTexture) {
			Debug::Log(EMessageType::ERROR,  "Failed to create texture from " + FileName + "!  SDL Error: " + SDL_GetError(),__FILENAME__, __LINE__);
		} else {
			width = LoadedSurface->w;
			height = LoadedSurface->h;
			Debug::Log(EMessageType::INFO,  "Loaded texture " + FileName,__FILENAME__, __LINE__);
		}

		SDL_FreeSurface(LoadedSurface);
		LoadedSurface = nullptr;
	}

	SDLTexture = NewSDLTexture;
	return SDLTexture != nullptr;
}

void Texture::SetTexture(SDL_Texture& SDLTexture_, const int width_, const int height_) {
	Destroy();
	SDLTexture = &SDLTexture_;
	width = width_;
	height = height_;
}

void Texture::Destroy() {
	SDL_DestroyTexture(SDLTexture);
	SDLTexture = nullptr;
	width = 0;
	height = 0;
}

void Texture::Draw(const DrawParams& Params) const {
	SDL_Rect DrawRect = {
		(int)(Params.x + (-width * (Params.scale - 1.0f) * 0.5f)),
		(int)(Params.y + (-height * (Params.scale - 1.0f) * 0.5f)),
		(int)(width * Params.scale),
		(int)(height * Params.scale) };

	if (Params.clip) {
		DrawRect.w = Params.clip->w;
		DrawRect.h = Params.clip->h;
	}

	SDL_RenderCopyEx(SDLRenderer, SDLTexture, Params.clip, &DrawRect, Params.angle, Params.center, Params.flip);
}

void Texture::Draw(const int x,const int y,const float scale,SDL_Rect* clip,const double angle,
	SDL_Point* center,const SDL_RendererFlip flip) const {
	DrawParams params = DrawParams { x, y, scale, clip, angle, center, flip };
	Draw(params);
}

void Texture::SetAlpha(const Uint8 a_) {
	SDL_SetTextureAlphaMod(SDLTexture, a_);
}

void Texture::SetBlendMode(const SDL_BlendMode blendMode_) {
	SDL_SetTextureBlendMode(SDLTexture, blendMode_);
}

void Texture::SetColor(const SDL_Color& SDLColor_) {
	SetColor(SDLColor_.r, SDLColor_.g, SDLColor_.b, SDLColor_.a);
}

void Texture::SetColor(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a) {
	SDL_SetTextureColorMod(SDLTexture, r, g, b);
	SDL_SetTextureAlphaMod(SDLTexture, a);
}

int Texture::GetWidth() const {
	return width;
}

int Texture::GetHeight() const {
	return height;
}
