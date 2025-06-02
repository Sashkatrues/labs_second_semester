#include "header.h"


void InputSizeFirst(int32_t& size)
{
	std::cin >> size;
	if (size <= 0)
	{
		throw std::invalid_argument("Impossible to complete. Wrong size\n");
	}
}


void TaskFirst(int32_t rows)
{
	int32_t** matrix = CreateMatrix(rows);
	InputingSpiralMatrix(matrix, rows);
	PrintMatrix(matrix, rows);
	std::cout << "Sum secondary diagonal: " << SumSecondaryDiagonal(matrix, rows) << '\n';
	DeleteMatrix(matrix, rows);
}


int32_t** CreateMatrix(int32_t rows)
{
	int32_t** matrix = new int32_t * [rows];
	for (size_t i{}; i < rows; ++i)
	{
		matrix[i] = new int32_t[rows];

	}
	return matrix;
}


void InputingSpiralMatrix(int32_t** matrix, int32_t rows)
{
	int32_t element{};
	int32_t leftSide{};
	int32_t rightSide{ rows - 1 };
	int32_t upperSide{};
	int32_t lowerSide{ rows - 1 };
	while (element < rows * rows)
	{
		for (int32_t i{ leftSide }; i <= rightSide; ++i)
		{
			matrix[upperSide][i] = ++element;
		}
		++upperSide;
		for (int32_t i{ upperSide }; i <= lowerSide; ++i)
		{
			matrix[i][rightSide] = ++element;
		}
		--rightSide;
		for (int32_t i{ rightSide }; i >= leftSide; --i)
		{
			matrix[lowerSide][i] = ++element;
		}
		--lowerSide;
		for (int32_t i{ lowerSide }; i >= upperSide; --i)
		{
			matrix[i][leftSide] = ++element;
		}
		++leftSide;
	}
}


void PrintMatrix(int32_t** matrix, int32_t rows)
{
	for (size_t i{}; i < rows; ++i)
	{
		for (size_t j{}; j < rows; ++j)
		{
			std::cout << std::setw(5) << matrix[i][j];
		}
		std::cout << '\n';
	}
	std::cout << '\n';
}


int32_t SumSecondaryDiagonal(int32_t** matrix, int32_t rows)
{
	int64_t sum{};
	for (int32_t i{}; i < rows; ++i)
	{
		sum += matrix[i][rows - 1 - i];
	}
	return sum;
}


void DeleteMatrix(int32_t** matrix, int32_t rows)
{
	for (size_t i{}; i < rows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}


void InputSizeSecond(int32_t& size)
{
	std::cin >> size;
	if (size < 3 || size > 101 || size % 2 == 0)
	{
		throw std::invalid_argument("Impossible to complete. Wrong size\n");
	}
}


void TaskSecond(int32_t rows)
{
	char choose{};
	int32_t** matrix = CreateMatrix(rows);
	InputChoose(choose);
	try
	{
		ChooseInputingMatrix(matrix, rows, choose);
		PrintMatrix(matrix, rows);
		std::cout << "Sum lower right triangle: " << SumLowerRightTriangle(matrix, rows) << '\n';
		std::cout << "Output center spiral matrix:\n";
		CenterSpiralMatrix(matrix, rows);
		DeleteMatrix(matrix, rows);
	}
	catch (std::invalid_argument& e) { std::cout << e.what(); }
}


void InputChoose(char& choose)
{
	std::cout << "Input 'h' - by hand or 'r' - by random\n";
	std::cin >> choose;
}


void ChooseInputingMatrix(int32_t** matrix, int32_t rows, char chouse)
{
	int32_t firstElement{};
	int32_t lastElement{};
	switch (chouse)
	{
	case 'h':
		InputMatrix(matrix, rows);
		system("cls");
		break;
	case 'r':
		InputInterval(firstElement, lastElement);
		FillMatrix(matrix, rows, firstElement, lastElement);
		break;
	default:
		throw std::invalid_argument("Impossible to complete. Wrong chouse\n");
		break;
	}
}


void InputMatrix(int32_t** matrix, int32_t rows)
{
	std::cout << "Input elements of matrix\n";
	for (size_t i{}; i < rows; ++i)
	{
		for (size_t j{}; j < rows; ++j)
		{
			std::cin >> matrix[i][j];
		}
	}
}


void InputInterval(int32_t& firstElement, int32_t& lastElement)
{
	std::cout << "Input first element in interval\n";
	std::cin >> firstElement;
	std::cout << "Input last element in interval\n";
	std::cin >> lastElement;
	if (firstElement > lastElement)
	{
		std::swap(firstElement, lastElement);
	}
	else if (firstElement == lastElement)
	{
		throw std::invalid_argument("Impossible to complete. Wrong interval\n");
	}
}


void FillMatrix(int32_t** matrix, int32_t rows, int32_t firstElement, int32_t lastElement)
{
	srand(time(0));
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int32_t>dist(firstElement, lastElement);
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < rows; ++j)
		{
			matrix[i][j] = dist(gen);
		}
	}
}


int32_t SumLowerRightTriangle(int32_t** matrix, int32_t rows)
{
	int64_t sum{};
	for (int32_t i{}; i < rows; ++i)
	{
		for (int32_t j{}; j < rows; ++j)
		{
			if (i >= rows - 1 - j)
			{
				sum += matrix[i][j];
			}
		}
	}
	return sum;
}


void CenterSpiralMatrix(int32_t** matrix, int32_t rows)
{
	int32_t count{ 1 };
	int32_t orientation{};
	int32_t centerRow{ (rows - 1) / 2 };
	int32_t centerCol{ (rows - 1) / 2 };
	std::cout << std::setw(5) << matrix[centerRow][centerCol];
	while (count < rows)
	{
		for (int32_t i{}; i < 2; ++i)
		{
			for (int32_t j{}; j < count; ++j)
			{
				if (orientation == 0)
				{
					++centerRow;
				}
				else if (orientation == 1)
				{
					--centerCol;
				}
				else if (orientation == 2)
				{
					--centerRow;
				}
				else if (orientation == 3)
				{
					++centerCol;
				}
				std::cout << std::setw(5) << matrix[centerRow][centerCol];
			}
			orientation = (orientation + 1) % 4;
		}
		++count;
	}
	for (int32_t i{}; i < rows - 1; ++i)
	{
		std::cout << std::setw(5) << matrix[++centerRow][centerCol];
	}
}