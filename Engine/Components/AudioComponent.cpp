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

}
