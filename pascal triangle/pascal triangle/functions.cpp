#include "triangle.h"


void InputRows(int32_t& rows)
{
	std::cout << "input count rows\n";
	std::cin >> rows;
}


int32_t** CreatePascalTriangle(int32_t rows)
{
	int32_t** triangle = new int32_t * [rows];

	for (int32_t i{}; i < rows; ++i)
	{
		triangle[i] = new int32_t[i + 1];
		triangle[i][0] = 1;
		triangle[i][i] = 1;

		for (int32_t j{ 1 }; j < i; ++j)
		{
			triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
		}
	}
	return triangle;
}


void PrintPascalTriangle(int32_t** triangle, int32_t rows)
{
	std::cout << "pascal triangle\n";
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j <= i; ++j)
		{
			std::cout << triangle[i][j] << '\t';
		}
		std::cout << '\n';
	}
}


void DeletePascalTriangle(int32_t** triangle, int32_t rows)
{
	for (int32_t i{}; i < rows; ++i)
	{
		delete[] triangle[i];
	}
	delete[] triangle;
}