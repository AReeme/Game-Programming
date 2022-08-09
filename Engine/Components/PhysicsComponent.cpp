#include "PhysicsComponent.h"

namespace defender
{
	void PhysicsComponent::Update()
	{
		m_velocity += m_acceleration * g_time.deltaTime;
		m_owner->GetTransform().position += m_velocity * g_time.deltaTime;
		m_velocity *= m_damping;

		m_acceleration = Vector2::zero;
	}

}
