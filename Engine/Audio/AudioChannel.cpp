//#include "AudioChannel.h"
//#include <fmod.h>
//
//namespace defender
//{
//	bool AudioChannel::IsPlaying()
//	{
//		if (!m_channel)
//		{
//			return false;
//		}
//
//		bool isPlaying;
//		m_channel->isPlaying(&isPlaying);
//
//		return isPlaying;
//	}
//
//	void AudioChannel::Stop()
//	{
//		if (IsPlaying()) m_channel->stop();
//	}
//
//	void AudioChannel::SetPitch(float pitch)
//	{
//		if (IsPlaying()) // !! call setPitch on channel (pass pitch) 
//		{
//			
//		}
//	}
//
//	float AudioChannel::GetPitch()
//	{
//		float pitch = 0;
//		if (IsPlaying()) // !! call getPitch (pass pointer to pitch &) 
//		{
//
//		}
//
//			return pitch;
//	}
//
//	void AudioChannel::SetVolume(float volume)
//	{
//		if (IsPlaying()) // !! call setVolume on channel (pass volume) 
//		{
//
//		}
//	}
//
//	float AudioChannel::GetVolume()
//	{
//		float volume = 0;
//		if (IsPlaying()) // !! call getVolume (pass pointer to volume &)
//		{
//
//		}
//
//			return volume;
//	}
//}