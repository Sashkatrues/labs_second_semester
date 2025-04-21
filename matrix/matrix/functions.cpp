#include "matrix.h"


void InputSize(int32_t& size)
{
	std::cin >> size;
	if (size <= 0)
	{
		throw std::invalid_argument("wrong size");
	}
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
	std::uniform_int_distribution<int32_t>dist(1, 40);
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < cols; ++j)
		{
			matrix[i][j] = dist(gen);
		}
	}
}


void FoundIndexRowMaxElement(int32_t** matrix, int32_t rows, int32_t cols, int32_t& indexRowMaxElement)
{
	int32_t max{ matrix[0][0] };
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < cols; ++j)
		{
			if (max < matrix[i][j])
			{
				max = matrix[i][j];
				indexRowMaxElement = i;
			}
		}
	}
}


void FoundIndexColMinElement(int32_t** matrix, int32_t rows, int32_t cols, int32_t& indexColMinElement)
{
	int32_t min{ matrix[0][0] };
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < cols; ++j)
		{
			if (min >= matrix[i][j])
			{
				min = matrix[i][j];
				indexColMinElement = j;
			}
		}
	}
}


int64_t CountSum(int32_t** matrix, int32_t cols, int32_t indexRowMaxElement)
{
	int64_t sum{};
	for (int32_t j{}; j < cols; ++j)
	{
		sum += matrix[indexRowMaxElement][j];
	}
	return sum;
}


int64_t CountMultiply(int32_t** matrix, int32_t rows, int32_t indexColMinElement)
{
	int64_t multiply{1};
	for (int32_t i{}; i < rows; ++i)
	{
		multiply *= matrix[i][indexColMinElement];
	}
	return multiply;
}


void FillMatrixZero(int32_t** matrix, int32_t rows, int32_t cols)
{
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < cols; ++j)
		{
			matrix[i][j] = 0;
		}
	}
}


void MultiplyMatrices(int32_t** multiply, int32_t** matrixFirst, int32_t** matrixSecond, int32_t rowsFirst, int32_t colsFirst, int32_t colsSecond)
{
	for (int32_t i{}; i < rowsFirst; ++i)
	{
		for (int32_t j{}; j < colsSecond; ++j)
		{
			for (int32_t k{}; k < colsFirst; ++k)
			{
				multiply[i][j] += matrixFirst[i][k] * matrixSecond[k][j];
			}
		}
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


void SumAndMultiply(int32_t rows, int32_t cols)
{
	int32_t** matrix = CreateMatrix(rows, cols);
	FillMatrix(matrix, rows, cols);
	PrintMatrix(matrix, rows, cols);
	std::cout << '\n';

	int32_t indexRowMaxElement{};
	int32_t indexColMinElement{};
	FoundIndexRowMaxElement(matrix, rows, cols, indexRowMaxElement);
	FoundIndexColMinElement(matrix, rows, cols, indexColMinElement);
	std::cout << "sum of row elements = " << CountSum(matrix, cols, indexRowMaxElement) << '\n';
	std::cout << "multiply of col elements = " << CountMultiply(matrix, rows, indexRowMaxElement) << '\n';

	DeleteMatrix(matrix, rows);
}


void MultiplyMatrices(int32_t rowsFirst, int32_t colsFirst)
{
	int32_t** matrixFirst = CreateMatrix(rowsFirst, colsFirst);
	FillMatrix(matrixFirst, rowsFirst, colsFirst);
	PrintMatrix(matrixFirst, rowsFirst, colsFirst);
	std::cout << '\n';

	int32_t rowsSecond{};
	int32_t colsSecond{};
	try
	{
		std::cout << "input rows second matrix\n";
		InputSize(rowsSecond);
		try
		{
			if (colsFirst != rowsSecond)
			{
				throw std::logic_error("multiplication is impossible");
			}

			try
			{
				std::cout << "input cols second matrix\n";
				InputSize(colsSecond);
				int32_t** matrixSecond = CreateMatrix(rowsSecond, colsSecond);
				FillMatrix(matrixSecond, rowsSecond, colsSecond);
				PrintMatrix(matrixSecond, rowsSecond, colsSecond);
				std::cout << '\n';

				int32_t** multiply = CreateMatrix(rowsFirst, colsSecond);
				FillMatrixZero(multiply, rowsFirst, colsSecond);
				MultiplyMatrices(multiply, matrixFirst, matrixSecond, rowsFirst, colsFirst, colsSecond);
				PrintMatrix(multiply, rowsFirst, colsSecond);
				std::cout << '\n';
			}
			catch (const std::invalid_argument& e) { std::cout << e.what() << '\n'; };
		}
		catch (const std::logic_error& e) { std::cout << e.what() << '\n'; };
	}
	catch (const std::invalid_argument& e) { std::cout << e.what() << '\n'; }
}