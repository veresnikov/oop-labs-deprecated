#pragma once
#include "map"
#include "string"

class TVSet
{
public:
	bool IsTurnedOn() const;
	void TurnOn();
	void TurnOff();
	int GetCurrentChannel() const;
	int GetPrevousChannel() const;
	bool SetChannel(int channel);
	bool SetChannel(std::string channel);
	bool SelectPrevousChannel();
	bool SetChannelAlias(int channel, std::string alias);

private:
	bool m_isOn = false;
	int m_channel = 1;
	int m_prevChannel = m_channel;
	std::map<std::string, int> m_channelAliasList;

	static bool IsValidChannelNumber(int channel);
};
