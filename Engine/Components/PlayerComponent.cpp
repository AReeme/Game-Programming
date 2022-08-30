#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>
#include <Components/PhysicsComponent.h>

namespace defender
{
	void PlayerComponent::Initialize()
	{
		CharacterComponent::Initialize();
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

		Vector2 velocity;
		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->ApplyForce(direction * speed);
			velocity = component->velocity;
		}

		//Jump
		if (defender::g_inputSystem.GetKeyDown(defender::key_space) == InputSystem::State::Pressed)
		{
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::up * 30);
			}
		}

		auto renderComponent = m_owner->GetComponent<RenderComponent>();
		if (renderComponent)
		{
			if (velocity.x != 0) renderComponent->SetFlipHorizontal(velocity.x < 0);
		}
	}
	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}
	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		CharacterComponent::Read(value);
		READ_DATA(value, jump);

		return true;
	}

	void PlayerComponent::OnNotify(const Event& event)
	{
		if (event.name == "EVENT_DAMAGE")
		{
			health -= std::get<float>(event.data);
			std::cout << health << std::endl;
			if (health <= 0)
			{
				//Player Dead
			}
		}
	}

	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		if (other->GetName() == "Coin")
		{
			Event event;
			event.name = "EVENT_ADD_POINTS";
			event.data = 100;

			g_eventManager.Notify(event);

			other->SetDestroy();
		}

		if (other->GetTag() == "Enemy")
		{
			Event event;
			event.name = "EVENT_DAMAGE";
			event.data = damage;
			event.receiver = other;

			g_eventManager.Notify(event);
		}
	}

	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		//
	}
}
