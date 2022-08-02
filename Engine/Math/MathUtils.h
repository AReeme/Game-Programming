#pragma once

namespace math
{
	const float PI = 3.14159265f; //180
	const float TwoPI = 6.2831853f; //360
	const float HalfPI = 1.57079633f; //90

	inline float DegToRad(float degrees)
	{
		return degrees * (PI / 180);
	}

	inline float RadToDeg(float radians)
	{
		return radians * (180 / PI);
	}

	int sqr(int v);
	inline int half(int v) { return v / 2; }
}
