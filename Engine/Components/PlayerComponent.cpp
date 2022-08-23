#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>
#include <Components/PhysicsComponent.h>

namespace defender
{
	void PlayerComponent::Update()
	{
		//Movement
		Vector2 direction2 = Vector2::zero;
		if (defender::g_inputSystem.GetKeyDown(defender::key_left))
		{
			direction2 = Vector2::left;
		}

		if (defender::g_inputSystem.GetKeyDown(defender::key_right))
		{
			direction2 = Vector2::right;
		}

		float m_thrust = 0;
		if (defender::g_inputSystem.GetKeyDown(defender::key_up))
		{
			m_thrust = 500;
		}

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->ApplyForce(direction2 * speed);
		}

		//Jump
		if (defender::g_inputSystem.GetKeyDown(defender::key_space) == InputSystem::State::Pressed)
		{
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::up * 500);
			}
		}

		//Calculate Force
		defender::Vector2 direction{ 1, 0 };
		direction = defender::Vector2::Rotate(direction, m_owner->GetTransform().rotation);
		defender::Vector2 force = direction * speed * defender::g_time.deltaTime;

		//Wrap
		if (m_owner->GetTransform().position.x > defender::g_renderer.GetWidth()) m_owner->GetTransform().position.x = 0;
		if (m_owner->GetTransform().position.x < 0) m_owner->GetTransform().position.x = (float)defender::g_renderer.GetWidth();
		if (m_owner->GetTransform().position.y > defender::g_renderer.GetHeight()) m_owner->GetTransform().position.y = 0;
		if (m_owner->GetTransform().position.y < 0) m_owner->GetTransform().position.y = (float)defender::g_renderer.GetHeight();
	}
	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}
	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, speed);

		return true;
	}
}
