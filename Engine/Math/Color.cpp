#include "Color.h"

namespace defender
{
	const Color Color::white{ 255, 255, 255, 255 };
	const Color Color::black{ 0, 0, 0, 0 };
	const Color Color::red{ 255, 0, 0, 0 };
	const Color Color::green{ 0, 255, 0, 0 };
	const Color Color::blue{ 0, 0, 255, 0 };

	std::istream& operator >> (std::istream& stream, Color& color)
	{
		std::string line;
		std::getline(stream, line);

		// line: { #r, #g, #b } 

		std::string str;

		// red 
		str = line.substr(line.find("{") + 1, line.find(",") - line.find("{") - 1);
		color.r = (uint8_t)(stof(str) * 255);

		// setting line to another sub section of the string to read green and blue 
		line = line.substr(line.find(",") + 1);
		// line: #g, #b } 

		// green 
		str = line.substr(0, line.find(","));
		color.g = (uint8_t)(stof(str) * 255);

		// blue 
		str = line.substr(line.find(",") + 1, line.find("}") - line.find(",") - 1);
		color.b = (uint8_t)(stof(str) * 255);

		// default alpha to 255 
		color.a = 255;

		return stream;
	}

	std::ostream& operator << (std::ostream& stream, const Color& color)
	{
		stream << (int)color.r << " " << (int)color.g << " " << (int)color.b << " " << (int)color.a;

		return stream;
	}
}