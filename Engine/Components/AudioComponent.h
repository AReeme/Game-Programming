#pragma once
#include "Framework/Component.h"

namespace defender
{
	class AudioComponent : public defender::Component
	{
	public:
		AudioComponent() = default;
		void Update() override;

	private:
		
	};
}