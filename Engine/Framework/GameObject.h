#pragma once
#include "Math/Transform.h"

namespace defender
{
	class GameObject
	{
	public:
		GameObject() = default;

		virtual void Update() = 0;
	};
}