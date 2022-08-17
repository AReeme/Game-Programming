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
		void ApplyForce(const Vector2& force) { acceleration += force; }

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		Vector2 velocity;
		Vector2 acceleration;

		float damping = 1;

	};
}