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
			// if in the air (m_groundCount == 0) then reduce force 
			float multiplier = (m_groundCount > 0) ? 1 : 0.2f;

			component->ApplyForce(direction * speed * multiplier);
			velocity = component->velocity;
		}

		//Jump
		if (m_groundCount > 0 && defender::g_inputSystem.GetKeyDown(defender::key_space) == InputSystem::State::Pressed)
		{
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::up * jump);
			}
		}

		auto animComponent = m_owner->GetComponent<SpriteAnimComponent>();
		if (animComponent)
		{
			if (velocity.x != 0) animComponent->SetFlipHorizontal(velocity.x < 0);
			if (std::fabs(velocity.x) > 0)
			{
				animComponent->SetSequence("run");
			}
			else
			{
				animComponent->SetSequence("idle");
			}
		}

		// set camera 
		auto camera = m_owner->GetScene()->GetActorFromName("Camera");
		if (camera)
		{
			camera->m_transform.position = math::Lerp(camera -> m_transform.position, m_owner->m_transform.position, 2 * g_time.deltaTime);
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
			if (health <= 0)
			{
				lives--;
				health = 100;
			}

			if (lives <= 0)
			{
				m_owner->SetDestroy();
			}
		}
	}

	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		if (other->GetTag() == "Ground")
		{
			m_groundCount++;
		}

		if (other->GetName() == "Coin")
		{
			Event event;
			event.name = "EVENT_ADD_POINTS";
			event.data = 100;

			g_eventManager.Notify(event);

			other->SetDestroy();
		}
	}

	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		if (other->GetTag() == "Ground")
		{
			m_groundCount--;
		}
	}
}
