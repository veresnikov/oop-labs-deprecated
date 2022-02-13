#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int ExpectedArgument = 5;
const int ErrorStatusCode = 1;

struct CommandLineArgument
{
	string InputFile;
	string OutputFile;
	string Search;
	string Replace;
};

CommandLineArgument ParseCommandLineArgument(int argc, char* argv[])
{
	if (argc != ExpectedArgument)
	{
		cerr << "Invalid argument." << endl
			 << "Usage: replace.exe <input file> <output file> <search string> <replace string>" << endl;
		exit(ErrorStatusCode);
	}
	CommandLineArgument argument;
	argument.InputFile = argv[1];
	argument.OutputFile = argv[2];
	argument.Search = argv[3];
	argument.Replace = argv[4];

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

	ifstream inputFile(argument.InputFile);
	if (!inputFile.is_open())
	{
		cerr << "Input file does not exist." << endl;
		exit(ErrorStatusCode);
	}

	ofstream outputFile(argument.OutputFile);
	if (!outputFile.is_open())
	{
		cerr << "Error opening output file." << endl;
		exit(ErrorStatusCode);
	}

	CopyFileWithReplace(inputFile, outputFile, argument.Search, argument.Replace);
}
