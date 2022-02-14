#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int expectedArgument = 5;
const int errorStatusCode = 1;

struct CommandLineArgument
{
	string inputFile;
	string outputFile;
	string search;
	string replace;
};

CommandLineArgument ParseCommandLineArgument(int argc, char* argv[])
{
	if (argc != expectedArgument)
	{
		cerr << "Invalid argument." << endl
			 << "Usage: replace.exe <input file> <output file> <search string> <replace string>" << endl;
		exit(errorStatusCode);
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
	string result = subject;
	size_t position = 0;
	while (position < result.length())
	{
		size_t replacedPosition = result.find(search, position);
		if (replacedPosition == string::npos)
		{
			return result;
		}
		position = replacedPosition;

		result.erase(replacedPosition, search.length());
		result.insert(replacedPosition, replace);

		position += replace.length();
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
	CommandLineArgument argument = ParseCommandLineArgument(argc, argv);

	ifstream inputFile(argument.inputFile);
	if (!inputFile.is_open())
	{
		cerr << "Input file does not exist." << endl;
		exit(errorStatusCode);
	}

	ofstream outputFile(argument.outputFile);
	if (!outputFile.is_open())
	{
		cerr << "Error opening output file." << endl;
		exit(errorStatusCode);
	}

	CopyFileWithReplace(inputFile, outputFile, argument.search, argument.replace);
}
