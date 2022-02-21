#include <fstream>
#include <iomanip>
#include <iostream>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int MATRIX_SIZE = 3;

const int EXPECTED_ARGUMENT = 3;
const int ERROR_STATUS_CODE = 1;

typedef double matrix[MATRIX_SIZE][MATRIX_SIZE];

struct CommandLineArgument
{
	string leftMatrix;
	string rightMatrix;
};

optional<CommandLineArgument> ParseCommandLineArgument(int argc, char* argv[])
{
	if (argc != EXPECTED_ARGUMENT)
	{
		return nullopt;
	}
	CommandLineArgument argument;
	argument.leftMatrix = argv[1];
	argument.rightMatrix = argv[2];
	return argument;
}

vector<string> split(const string& line)
{
	stringstream ss(line);
	vector<string> result;
	string word;
	while (ss >> word)
	{
		result.push_back(word);
	}
	return result;
}

double stringToDouble(const string& value, bool& error)
{
	try
	{
		return stod(value);
	}
	catch (const exception&)
	{
		error = true;
		return 0;
	}
}

void ParseMatrixFromFile(istream& inputFile, matrix& result, bool& error)
{
	string line;
	int r = 0;
	while (!inputFile.eof())
	{
		getline(inputFile, line);
		auto row = split(line);
		if (row.size() != MATRIX_SIZE)
		{
			error = true;
			return;
		}
		for (int i = 0; i < MATRIX_SIZE; i++)
		{
			result[r][i] = stringToDouble(row[i], error);
			if (error)
			{
				return;
			}
		}
		++r;
	}
	return;
}

void multMatrix(const matrix& a, const matrix& b, matrix& result)
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			for (int k = 0; k < MATRIX_SIZE; k++)
			{
				result[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

void printMatrix(const matrix& a)
{
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			cout << setprecision(3) << a[i][j];
			if (j < MATRIX_SIZE)
			{
				cout << " ";
			}
		}
		cout << '\n';
	}
}

int main(int argc, char* argv[])
{
	auto args = ParseCommandLineArgument(argc, argv);
	if (args == nullopt)
	{
		cerr << "Invalid argument." << endl
			 << "Usage: multmatrix.exe <matrix file1> <matrix file2>" << endl;
		return ERROR_STATUS_CODE;
	}

	ifstream leftMatrix(args->leftMatrix);
	if (!leftMatrix.is_open())
	{
		cerr << "Input matrix file does not exist." << endl;
		return ERROR_STATUS_CODE;
	}

	ifstream rightMatrix(args->rightMatrix);
	if (!rightMatrix.is_open())
	{
		cerr << "Input matrix file does not exist." << endl;
		return ERROR_STATUS_CODE;
	}

	matrix a = {
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 }
	};
	matrix b = {
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 }
	};

	bool error = false;
	ParseMatrixFromFile(leftMatrix, a, error);
	if (error)
	{
		cerr << "Error during matrix parsing." << endl;
		return ERROR_STATUS_CODE;
	}
	ParseMatrixFromFile(rightMatrix, b, error);
	if (error)
	{
		cerr << "Error during matrix parsing." << endl;
		return ERROR_STATUS_CODE;
	}

	matrix result = {
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 }
	};
	multMatrix(a, b, result);
	printMatrix(result);
}
