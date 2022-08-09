#pragma once
#include "Framework/Component.h"
#include "Math/Vector2.h"
#include "Engine.h"

namespace defender
{
	class PhysicsComponent : public defender::Component
	{
	public:
		PhysicsComponent() = default;

		void Update() override;
		void ApplyForce(const Vector2& force) { m_acceleration += force; }

	public:
		Vector2 m_velocity;
		Vector2 m_acceleration;

		float m_damping = 1;
	};
}