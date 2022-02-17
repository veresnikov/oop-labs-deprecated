#include <fstream>
#include <iostream>
#include <optional>
#include <regex>
#include <string>

using namespace std;

const int EXPECTED_ARGUMENT = 5;
const int ERROR_STATUS_CODE = 1;

struct CommandLineArgument
{
	string inputFile;
	string outputFile;
	string search;
	string replace;
};

optional<CommandLineArgument> ParseCommandLineArgument(int argc, char* argv[])
{
	if (argc != EXPECTED_ARGUMENT)
	{
		return nullopt;
	}
	CommandLineArgument argument;
	argument.inputFile = argv[1];
	argument.outputFile = argv[2];
	argument.search = argv[3];
	argument.replace = argv[4];

	return argument;
}

string ReplaceString(const string& subject, const string& search, const string& replace)
{
	if (search.empty())
	{
		return subject;
	}

	string result;
	size_t position = 0;
	size_t replacedPosition = subject.find(search, position);
	if (replacedPosition == string::npos)
	{
		return subject;
	}

	while (position < subject.length())
	{
		replacedPosition = subject.find(search, position);
		if (replacedPosition == string::npos)
		{
			result.append(subject, position, subject.length() - position);
			break;
		}
		result.append(subject, position, replacedPosition - position);
		result.append(replace);
		position = replacedPosition + search.length();
	}
	return result;
}

void CopyFileWithReplace(istream& inputFile, ostream& outputFile, string search, string replace)
{
	string line;
	while (!inputFile.eof())
	{
		getline(inputFile, line);
		line = ReplaceString(line, search, replace);
		outputFile << line;

		if (!inputFile.eof())
		{
			outputFile << endl;
		}
	}

	outputFile.flush();
}

int main(int argc, char* argv[])
{
	auto argument = ParseCommandLineArgument(argc, argv);
	if (!argument)
	{
		cerr << "Invalid argument." << endl
			 << "Usage: replace.exe <input file> <output file> <search string> <replace string>" << endl;
		return ERROR_STATUS_CODE;
	}

	ifstream inputFile(argument->inputFile);
	if (!inputFile.is_open())
	{
		cerr << "Input file does not exist." << endl;
		return ERROR_STATUS_CODE;
	}

	ofstream outputFile(argument->outputFile);
	if (!outputFile.is_open())
	{
		cerr << "Error opening output file." << endl;
		return ERROR_STATUS_CODE;
	}

	CopyFileWithReplace(inputFile, outputFile, argument->search, argument->replace);
}
