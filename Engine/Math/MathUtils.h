#pragma once

namespace math
{
	constexpr float PI = 3.14159265f; //180
	constexpr float TwoPI = 6.2831853f; //360
	constexpr float HalfPI = 1.57079633f; //90

	constexpr float DegToRad(float degrees)
	{
		return degrees * (PI / 180);
	}

	constexpr float RadToDeg(float radians)
	{
		return radians * (180 / PI);
	}

	int sqr(int v);
	inline int half(int v) { return v / 2; }
}
