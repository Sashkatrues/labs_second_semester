#include "shift.h"


void InputSize(int32_t& size)
{
	std::cin >> size;
	if (size <= 0)
	{
		throw std::invalid_argument("wrong size");
	}
}


void InputType(char& type)
{
	std::cout << "input type 'L' - left, 'R' - right, 'U' - up, 'D' - down \n";
	std::cin >> type;
}


int32_t** CreateMatrix(int32_t rows, int32_t cols)
{
	int32_t** matrix = new int32_t * [rows];

	for (int32_t i{}; i < rows; ++i)
	{
		matrix[i] = new int32_t[cols];
	}
	return matrix;
}


void FillMatrix(int32_t** matrix, int32_t rows, int32_t cols)
{
	srand(time(0));
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int32_t>dist(1, 100);
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < cols; ++j)
		{
			matrix[i][j] = dist(gen);
		}
	}
}


void CircleShiftLeft(int32_t** matrix, int32_t rows, int32_t cols)
{
	for (int32_t i{}; i < rows; ++i)
	{
		int32_t temp{ matrix[i][0] };
		for (int32_t j{}; j < cols - 1; ++j)
		{
			matrix[i][j] = matrix[i][j + 1];
		}
		matrix[i][cols - 1] = temp;
	}
}


void CircleShiftRight(int32_t** matrix, int32_t rows, int32_t cols)
{
	for (int32_t i{}; i < rows; ++i)
	{
		int32_t temp{ matrix[i][cols - 1] };
		for (int32_t j{ cols - 1 }; j > 0; --j)
		{
			matrix[i][j] = matrix[i][j - 1];
		}
		matrix[i][0] = temp;
	}
}


void CircleShiftUp(int32_t** matrix, int32_t rows, int32_t cols)
{
	for (int32_t j{}; j < cols; ++j)
	{
		int32_t temp{ matrix[0][j] };
		for (int32_t i{}; i < rows - 1; ++i)
		{
			matrix[i][j] = matrix[i + 1][j];
		}
		matrix[rows - 1][j] = temp;
	}
}


void CircleShiftDown(int32_t** matrix, int32_t rows, int32_t cols)
{
	for (int32_t j{}; j < cols; ++j)
	{
		int32_t temp{ matrix[rows - 1][j] };
		for (int32_t i{ rows - 1 }; i > 0; --i)
		{
			matrix[i][j] = matrix[i - 1][j];
		}
		matrix[0][j] = temp;
	}
}


void PrintMatrix(int32_t** matrix, int32_t rows, int32_t cols)
{
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < cols; ++j)
		{
			std::cout << std::setw(5) << matrix[i][j];

		}
	}
}


void DeleteMatrix(int32_t** matrix, int32_t rows)
{
	for (int32_t i{}; i < rows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}


void ChooseShift(char type, int32_t** matrix, int32_t rows, int32_t cols)
{
	switch (type)
	{
	case 'L':
		CircleShiftLeft(matrix, rows, cols);
		PrintMatrix(matrix, rows, cols);
		break;
	case 'R':
		CircleShiftRight(matrix, rows, cols);
		PrintMatrix(matrix, rows, cols);
		break;
	case 'U':
		CircleShiftUp(matrix, rows, cols);
		PrintMatrix(matrix, rows, cols);
		break;
	case 'D':
		CircleShiftDown(matrix, rows, cols);
		PrintMatrix(matrix, rows, cols);
		break;
	default:
		throw std::invalid_argument("wrong type");
		break;
	}
}