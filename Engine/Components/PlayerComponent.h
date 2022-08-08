#pragma once
#include "Framework/Component.h"

namespace defender
{
	class PlayerComponent : public defender::Component
	{
	public:
		PlayerComponent() = default;
		void Update() override;

	private:
		float m_health{ 10 };

		float m_speed = 0;
		float m_maxSpeed = 400;
	};
}