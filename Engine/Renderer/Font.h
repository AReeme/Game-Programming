#pragma once
#include <string>

struct _TTF_Font;

namespace defender
{
	class Font
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		bool Create(const std::string& filename) { return false; }
		void Load(const std::string& filename, int fontSize);

	private:
		friend class Text;
		_TTF_Font* m_ttfFont = nullptr;
	};
}