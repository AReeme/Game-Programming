#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>
#include <Components/PhysicsComponent.h>

namespace defender
{
	void PlayerComponent::Update()
	{
		//Movement
		//Input
		if (defender::g_inputSystem.GetKeyDown(defender::key_left))
		{
			m_owner->GetTransform().rotation -= 180 * g_time.deltaTime;
		}

		if (defender::g_inputSystem.GetKeyDown(defender::key_right))
		{
			m_owner->GetTransform().rotation += 180 * g_time.deltaTime;
		}

		float m_thrust = 0;
		if (defender::g_inputSystem.GetKeyDown(defender::key_up))
		{
			m_thrust = 500;
		}

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			//Thrust Force
			Vector2 force = Vector2::Rotate({ 1, 0 }, math::DegToRad(m_owner->GetTransform().rotation)) * m_thrust;
			component->ApplyForce(force);

			//Gravitational Force
			/*force = (Vector2{ 400, 300 } - m_owner->GetTransform().position).Normalized() * 60.f;
			component->ApplyForce(force);*/
		}


		if (defender::g_inputSystem.GetKeyDown(defender::key_space) == InputSystem::State::Pressed)
		{
			auto component = m_owner->GetComponent<AudioComponent>();
			if (component)
			{
				component->Play();
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
