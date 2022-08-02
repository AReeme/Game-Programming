#include "Font.h"
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

void defender::Font::Load(const std::string& filename, int fontSize)
{
	m_ttfFont = TTF_OpenFont(filename.c_str(), fontSize);
}
