#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>
#include <Components/PhysicsComponent.h>

namespace defender
{
	void PlayerComponent::Initialize()
	{
		auto component = m_owner->GetComponent<CollisionComponent>();
		if (component)
		{
			component->SetCollisionEnter(std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1));
			component->SetCollisionExit(std::bind(&PlayerComponent::OnCollisionExit, this, std::placeholders::_1));
		}
	}

	void PlayerComponent::Update()
	{
		//Movement
		Vector2 direction = Vector2::zero;
		if (defender::g_inputSystem.GetKeyDown(defender::key_left))
		{
			direction = Vector2::left;
		}

		if (defender::g_inputSystem.GetKeyDown(defender::key_right))
		{
			direction = Vector2::right;
		}

		float m_thrust = 0;
		if (defender::g_inputSystem.GetKeyDown(defender::key_up))
		{
			m_thrust = 500;
		}

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->ApplyForce(direction * speed);
		}

		//Jump
		if (defender::g_inputSystem.GetKeyDown(defender::key_space) == InputSystem::State::Pressed)
		{
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::up * 100);
			}
		}
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

	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		if (other->GetName() == "Coin")
		{
			other->SetDestroy();
		}

		std::cout << "Player Enter\n";
	}

	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		std::cout << "Player Exit\n";
	}
}
