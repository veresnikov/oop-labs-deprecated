#include <array>
#include <bitset>
#include <iostream>
#include <optional>
#include <string>

using namespace std;

typedef unsigned char byteNumber;

const int EXPECTED_ARGUMENT = 2;
const int ERROR_STATUS_CODE = 1;

struct CommandLineArgument
{
	string input;
};

optional<CommandLineArgument> ParseCommandLineArgument(int argc, char* argv[])
{
	if (argc != EXPECTED_ARGUMENT)
	{
		return nullopt;
	}
	CommandLineArgument argument;
	argument.input = argv[1];

	return argument;
}

void tryConvertStringToByteNumber(const string& value, byteNumber& result, bool& error)
{
	if (value.empty())
	{
		error = true;
		return;
	}
	for (size_t i = 0; i < value.length(); i++)
	{
		if (isdigit(value[i]) == 0)
		{
			error = true;
			return;
		}
	}
	int converted = stoi(value);
	if (converted < 0 || converted > 255)
	{
		error = true;
		return;
	}
	result = converted;
}

bool checkBit(const byteNumber& value, const byteNumber& mask)
{
	return (value & mask) != 0;
}

byteNumber flipByte(const byteNumber& value)
{
	byteNumber mask = 0b00000001;
	byteNumber flipBit = 0b10000000;
	byteNumber result = 0;
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

int main(int argc, char* argv[])
{
	auto args = ParseCommandLineArgument(argc, argv);
	if (args == nullopt)
	{
		cerr << "Invalid argument." << endl
			 << "Usage: flipbyte.exe <input byte>" << endl;
		return ERROR_STATUS_CODE;
	}

	byteNumber input = 0;
	bool error = false;
	tryConvertStringToByteNumber(args->input, input, error);
	if (error)
	{
		cerr << "Error converting input value to byte." << endl;
		return ERROR_STATUS_CODE;
	}
	byteNumber result = flipByte(input);
	cout << (int)result << endl;
	return 0;
}