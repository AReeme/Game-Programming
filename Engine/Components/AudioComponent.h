#pragma once
#include "Framework/Component.h"
#include "Engine.h"
#include <string>

namespace defender
{
	class AudioComponent : public defender::Component
	{
	public:
		AudioComponent() = default;
		void Update() override;

		void Play();
		void Stop();

	public:
		std::string m_soundName;
		bool m_playOnAwake = false;
		float m_volume = 1;
		float m_pitch = 1;
		bool m_loop = false;
	};
}