#include "TVSet.h"

bool TVSet::IsTurnedOn() const
{
	return m_isOn;
}

void TVSet::TurnOn()
{
	m_isOn = true;
}

void TVSet::TurnOff()
{
	m_isOn = false;
}

int TVSet::GetCurrentChannel() const
{
	return IsTurnedOn() ? m_channel : 0;
}

int TVSet::GetPrevousChannel() const
{
	return IsTurnedOn() ? m_prevChannel : 0;
}

bool TVSet::SetChannel(int channel)
{
	if (!IsTurnedOn() || !IsValidChannelNumber(channel))
	{
		return false;
	}
	m_prevChannel = m_channel;
	m_channel = channel;
	return true;
}

bool TVSet::SetChannel(std::string channel)
{
	if (!IsTurnedOn() || m_channelAliasList.count(channel) == 0)
	{
		return false;
	}
	m_prevChannel = m_channel;
	m_channel = m_channelAliasList[channel];
	return true;
}

bool TVSet::SelectPrevousChannel()
{
	return SetChannel(GetPrevousChannel());
}


bool TVSet::SetChannelAlias(int channel, std::string alias)
{
	if (!IsTurnedOn() || !IsValidChannelNumber(channel))
	{
		return false;
	}
	m_channelAliasList[alias] = channel;
	return true;
}

bool TVSet::IsValidChannelNumber(int channel)
{
	return (channel >= 1 && channel <= 99);
}
