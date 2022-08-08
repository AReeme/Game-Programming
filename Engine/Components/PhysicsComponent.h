#pragma once
#include "Framework/Component.h"

namespace defender
{
	class PhysicsComponent : public defender::Component
	{
	public:
		PhysicsComponent() = default;
		void Update() override;

	private:

	};
}