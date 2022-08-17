#include "PhysicsComponent.h"

namespace defender
{
	void PhysicsComponent::Update()
	{
		velocity += acceleration * g_time.deltaTime;
		m_owner->GetTransform().position += velocity * g_time.deltaTime;
		velocity *= damping;

		acceleration = Vector2::zero;
	}

	bool PhysicsComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PhysicsComponent::Read(const rapidjson::Value& value)
	{
		return true;
	}

}
