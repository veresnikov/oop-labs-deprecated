#include <iostream>
#include <string>

using namespace std;

const int MATRIX_SIZE = 3;

typedef double matrix[MATRIX_SIZE][MATRIX_SIZE];

void muiltMatrix(const matrix& a, const matrix& b, matrix result)
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

string matrixToString(const matrix& a)
{
	string result = "";
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			result += to_string(a[i][j]);
			if (j < MATRIX_SIZE)
			{
				result += " ";
			}
		}
		if (i < MATRIX_SIZE)
		{
			result += '\n';
		}
	}
	return result;
}

int main()
{
	matrix a = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};
	matrix b = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};

	matrix result = {
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 0, 0, 0 }
	};
	muiltMatrix(a, b, result);
	string m = matrixToString(result);
	cout << m << endl;
}
