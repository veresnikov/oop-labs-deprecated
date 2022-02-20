#include <array>
#include <bitset>
#include <iostream>

using namespace std;

bool checkBit(int value, int mask)
{
	return (value & mask) != 0;
}

int flipByte(int value)
{
	int mask = 0b00000001;
	int flipBit = 0b10000000;
	int result = 0;
	for (size_t i = 0; i < 8; i++)
	{
		if (checkBit(value, mask))
		{
			result = result | flipBit;
		}
		flipBit = flipBit >> 1;
		mask = mask << 1;
	}
	return result;
}

int main()
{
	int a = 25;
	cout << flipByte(a) << endl;
	return 0;
}