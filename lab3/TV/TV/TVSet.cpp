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

bool TVSet::SetChannel(int channel)
{
	if (!IsTurnedOn() || !(channel >= 1 && channel <= 99))
	{
		return false;
	}
	m_channel = channel;
	return true;
}