#include "header.h"

void InputSize(int32_t& size)
{
	std::cout << "Input count of strings\n";
	std::cin >> size;
	std::cin.ignore();
	if (size <= 0)
	{
		throw std::invalid_argument("Wrong size");
	}
}

void InputMatrix(char** matrix, int32_t size)
{
	for (int32_t i{}; i < size; ++i)
	{
		std::cout << "Input string " << i + 1 << '\n';
		matrix[i] = new char[100];
		std::cin.getline(matrix[i], 100);
		if (strlen(matrix[i]) == 0)
		{
			throw  std::invalid_argument("Sentence is empty\n");
		}
	}
}

void FoundNumbers(char** matrix, int32_t* arrayNum, int32_t size)
{
	for (int32_t i{}; i < size; ++i)
	{
		char* copy = new char[100];
		strcpy(copy, matrix[i]);
		char* token = strtok(copy, " ");
		token = strtok(NULL, " ");
		if (token == NULL)
		{
			throw std::invalid_argument("No number in one of string\n");
		}
		// как сделать проверку на запись только цифр после пробела не знаю
		arrayNum[i] = atoi(token);
	}
}

void SortMatrix(char** matrix, int32_t* arrayNum, int32_t size)
{
	bool isSwap{ false };

	for (int32_t i{}; i < size; ++i)
	{
		for (int32_t j{}; j < size - 1 - i; ++j)
		{
			if (arrayNum[j] > arrayNum[j + 1])
			{
				std::swap(arrayNum[j], arrayNum[j + 1]);
				std::swap(matrix[j], matrix[j + 1]);
				isSwap = true;
			}
		}
		if (!isSwap)
		{
			break;
		}
	}
}

void PrintMatrix(char** matrix, int32_t size)
{
	std::cout << "Sort strings:\n";
	for (int32_t i{}; i < size; ++i)
	{
		std::cout << matrix[i] << '\n';
	}
}

int64_t CountSum(int32_t* arrayNum, int32_t size)
{
	int64_t sum{};
	for (int32_t i{}; i < size; ++i)
	{
		sum += arrayNum[i];
	}
	return sum;
}