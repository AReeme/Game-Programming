#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace defender
{
	void PlayerComponent::Update()
	{
		//Movement
		//Input
		if (defender::g_inputSystem.GetKeyDown(defender::key_left))
		{
			m_owner->GetTransform().position.x -= 180 * defender::g_time.deltaTime;
		}

		if (defender::g_inputSystem.GetKeyDown(defender::key_right))
		{
			m_owner->GetTransform().position.x += 180 * defender::g_time.deltaTime;
		}

		//Set Thrust Speed
		m_speed = 0;
		if (defender::g_inputSystem.GetKeyDown(defender::key_up))
		{
			m_owner->GetTransform().position.y -= 180 * defender::g_time.deltaTime;
		}

		if (defender::g_inputSystem.GetKeyDown(defender::key_down))
		{
			m_owner->GetTransform().position.y += 180 * defender::g_time.deltaTime;
		}

		//Calculate Force
		defender::Vector2 direction{ 1, 0 };
		direction = defender::Vector2::Rotate(direction, m_owner->GetTransform().rotation);
		defender::Vector2 force = direction * m_speed * defender::g_time.deltaTime;

		//Wrap
		if (m_owner->GetTransform().position.x > defender::g_renderer.GetWidth()) m_owner->GetTransform().position.x = 0;
		if (m_owner->GetTransform().position.x < 0) m_owner->GetTransform().position.x = (float)defender::g_renderer.GetWidth();
		if (m_owner->GetTransform().position.y > defender::g_renderer.GetHeight()) m_owner->GetTransform().position.y = 0;
		if (m_owner->GetTransform().position.y < 0) m_owner->GetTransform().position.y = (float)defender::g_renderer.GetHeight();
	}
}
