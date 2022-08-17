#pragma once
#include "GameObject.h"

namespace defender
{
	class Actor;

	class Component : public GameObject, public ISerializable
	{
	public:
		Component() = default;

		virtual void Update() = 0;

		friend class Actor;

	protected:
		Actor* m_owner = nullptr;
	};
}