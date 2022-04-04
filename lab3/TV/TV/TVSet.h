#pragma once

class TVSet
{
public:
	bool IsTurnedOn() const;
	void TurnOn();
	void TurnOff();
	int GetCurrentChannel() const;
	bool SetChannel(int channel);

private:
	bool m_isOn = false;
	int m_channel = 1;
};
