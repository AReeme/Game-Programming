#pragma once
#include "Math\Vector2.h" 
#include "Resource/Resource.h"
#include "Renderer.h"
#include <string>

struct _TTF_Font;

namespace defender
{
	class Font : public Resource
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		bool Create(const std::string& filename) { return false; }
		bool Create(const std::string& filename, int fontSize);
		bool Create(std::string filename, ...) override;
		bool Load(const std::string& filename, int fontSize);

	private:
		friend class Text;
		_TTF_Font* m_ttfFont = nullptr;
	};
}