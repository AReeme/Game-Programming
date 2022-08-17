#include "AudioComponent.h"

namespace defender
{
	void AudioComponent::Update()
	{

	}

	void AudioComponent::Play()
	{
		g_audiosystem.PlayAudio(m_soundName);
	}

	void AudioComponent::Stop()
	{

	}

	bool AudioComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}

	bool AudioComponent::Read(const rapidjson::Value& value)
	{
		return false;
	}

}
