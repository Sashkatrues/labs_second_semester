#include "functions.h"


void InputSize(int32_t& size)
{
	std::cout << "Input size of array\n";
	std::cin >> size;
	if (size <= 0)
	{
		throw std::invalid_argument("Wrong size\n");
	}
}


void InputTask(char& type)
{
	std::cout << "Input number of task '1' - double or '2' - int\n";
	std::cin >> type;

}


void Task(int32_t size, char type)
{
	char choose{};
	int32_t* array = nullptr;
	double* array2 = nullptr;
	switch (type)
	{
	case '1':
		InputChoose(choose);
		try
		{
			ChooseInputingArray(array2, size, choose);
			PrintArray(array2, size);
			std::cout << "Sum of elements = " << SumPositiveElements(array2, size) << '\n';
			try
			{
				std::cout << "Multiplication = " << MultiplicationOfElements(array2, size) << '\n';
			}
			catch (std::domain_error& e) { std::cout << e.what(); }
			BubbleSort(array2, size);
			PrintArray(array2, size);
			DeleteArray(array2);
		}
		catch (std::invalid_argument& e) { std::cout << e.what(); }
		break;
	case '2':
		InputChoose(choose);
		ChooseInputingArray(array, size, choose);
		system("cls");
		PrintArray(array, size);
		DeleteArray(array);
		break;
	default:
		throw std::invalid_argument("Wrong type\n");
		break;
	}
}


void InputChoose(char& choose)
{
	std::cout << "Input 'h' - by hand or 'r' - by random\n";
	std::cin >> choose;

}

void CreateArray(int32_t*& array, int32_t size)
{
	array = new int32_t[size];
}


void CreateArray(double*& array, int32_t size)
{
	array = new double[size];
}


void FillArray(int32_t* array, int32_t size, int32_t firstElement, int32_t lastElement)
{
	srand(time(NULL));
	for (size_t i{}; i < size; ++i)
	{
		array[i] = rand() % (lastElement - firstElement + 1) + firstElement;
	}
}


void FillArray(double* array, int32_t size, double firstElement, double lastElement)
{
	srand(time(NULL));
	for (size_t i{}; i < size; ++i)
	{
		array[i] = static_cast<double>(rand()) / RAND_MAX * (lastElement - firstElement) + firstElement;
	}
}


double SumPositiveElements(double* array, int32_t size)
{
	double sum{};
	for (size_t i{}; i < size; ++i)
	{
		if (array[i] >= 0)
		{
			sum += array[i];
		}
	}
	return sum;
}

int32_t IndexOfFirstMaxElement(double* array, int32_t size)
{
	double max{ abs(array[0]) };
	int32_t index{};
	for (int32_t i{1}; i < size; ++i)
	{
		if (max < abs(array[i]))
		{
			max = abs(array[i]);
			index = i;
		}
	}
	return index;
}

int32_t IndexOfLastMinElement(double* array, int32_t size)
{
	double min{ abs(array[0]) };
	int32_t index{};
	for (int32_t i{1}; i < size ; ++i)
	{
		if (min >= abs(array[i]))
		{
			min = abs(array[i]);
			index = i;
		}
	}
	return index;
}

double MultiplicationOfElements(double* array, int32_t size)
{
	int32_t indexMax{ IndexOfFirstMaxElement(array, size) };
	int32_t indexMin{ IndexOfLastMinElement(array, size) };
	if (indexMin - indexMax - 1 <= 0)
	{
		throw std::domain_error("Impossible to complete. Received an interval that doesn't match the condition\n");
	}
	else
	{
		double multiplication{1};
		for (int32_t i{ indexMax + 1 }; i < indexMin; ++i)
		{
			multiplication *= array[i];
		}
		return multiplication;
	}
}

void BubbleSort(double*& array, int32_t size)
{
	for (size_t i{}; i < size; i += 2)
	{
		for (size_t j{}; j < size - 2; j += 2)
		{
			if (array[j] < array[j + 2])
			{
				std::swap(array[j], array[j + 2]);
			}
		}
	}
}