#include "Font.h"
#include "Renderer.h"
#include <SDL_ttf.h>
#include <iostream>

defender::Font::Font(const std::string& filename, int fontSize)
{
	Load(filename, fontSize);
}

defender::Font::~Font()
{
	if (m_ttfFont != nullptr)
	{
		TTF_CloseFont(m_ttfFont);
	}
}

bool defender::Font::Create(const std::string& filename, int fontSize)
{
	return Load(filename, fontSize);
}

bool defender::Font::Create(std::string filename, ...)
{
	va_list args;
	va_start(args, filename);
	int fontSize = va_arg(args, int);
	va_end(args);

	return Create(filename, fontSize);
}

bool defender::Font::Load(const std::string& filename, int fontSize)
{
	m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);

	return true;
}
