#include "Font.h"
#include "Renderer.h"
#include "Core/Logger.h"
#include <SDL_ttf.h>
#include <iostream>

namespace defender
{
	Font::Font(const std::string& filename, int fontSize)
	{
		Load(filename, fontSize);
	}

	Font::~Font()
	{
		if (m_ttfFont != nullptr)
		{
			TTF_CloseFont(m_ttfFont);
		}
	}

	bool Font::Create(const std::string& filename, int fontSize)
	{
		return Load(filename, fontSize);
	}

	bool Font::Create(std::string filename, ...)
	{
		va_list args;
		va_start(args, filename);
		int fontSize = va_arg(args, int);
		va_end(args);

		return Create(filename, fontSize);
	}

	bool Font::Load(const std::string& filename, int fontSize)
	{
		m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);

		return true;
	}

	SDL_Surface* Font::CreateSurface(const std::string& text, const Color& color)
	{
		SDL_Color c = *((SDL_Color*)(&color));
		SDL_Surface* surface = TTF_RenderText_Solid(m_ttfFont, text.c_str(), c);

		if (surface == nullptr)
		{
			LOG(SDL_GetError());
		}

		return surface;
	}

}

