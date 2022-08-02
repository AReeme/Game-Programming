#pragma once
#include <iostream>
#include <cstdint>
#include <string>

namespace defender
{
	struct Color
	{
		uint8_t r;
		uint8_t g;
		uint8_t b;
		uint8_t a;

		friend std::istream& operator >> (std::istream& stream, Color& color);
	};

	inline std::istream& operator >> (std::istream& stream, Color& color)
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
}