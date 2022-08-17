#pragma once
#include "Framework/Component.h"

namespace defender
{
	class PlayerComponent : public defender::Component
	{
	public:
		PlayerComponent() = default;
		void Update() override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;
	private:
		float speed{ 0 };
	};
}