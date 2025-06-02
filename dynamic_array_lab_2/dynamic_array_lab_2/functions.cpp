#include "functions.h"


void InputSize(int32_t& size)
{
	std::cout << "Input size of array\n";
	std::cin >> size;
	if (size <= 0)
	{
		throw std::invalid_argument("Impossible to complete. Wrong size\n");
	}
}


void TaskFirst(int32_t size1, char type)
{
	char choose{};
	double* array1 = nullptr;
	InputChoose(choose);
	try
	{
		ChooseInputingArray(array1, size1, choose);
		PrintArray(array1, size1);
		std::cout << "Sum of elements = " << SumPositiveElements(array1, size1) << '\n';
		try
		{
			std::cout << "Multiplication = " << MultiplicationElements(array1, size1) << '\n';
		}
		catch (std::domain_error& e) { std::cout << e.what(); }
		BubbleSort(array1, size1);
		PrintArray(array1, size1);
		DeleteArray(array1);
	}
	catch (std::invalid_argument& e) { std::cout << e.what(); }
}


void TaskSecond(int32_t size, char type)
{
	char choose2{};
	int32_t* array = nullptr;
	InputChoose(choose2);
	try
	{
		ChooseInputingArray(array, size, choose2);
		PrintArray(array, size);
		std::cout << "Count of different elements = " << CountDifferentElements(array, size) << '\n';
		try
		{
			std::cout << "Multiplication = " << MultiplicationElements(array, size) << '\n';
		}
		catch (std::domain_error& e) { std::cout << e.what(); }
		BubbleSort(array, size);
		PrintArray(array, size);
		DeleteArray(array);
	}
	catch (std::invalid_argument& e) { std::cout << e.what(); }
}


void InputChoose(char& choose)
{
	std::cout << "Input 'h' - by hand or 'r' - by random\n";
	std::cin >> choose;

}

//void CreateArray(int32_t*& array, int32_t size)
//{
//	array = new int32_t[size];
//}
//
//
//void CreateArray(double*& array, int32_t size)
//{
//	array = new double[size];
//}


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

double MultiplicationElements(double* array, int32_t size)
{
	int32_t indexMax{ IndexOfFirstMaxElement(array, size) };
	int32_t indexMin{ IndexOfLastMinElement(array, size) };
	if (indexMin - indexMax - 1 <= 0)
	{
		throw std::domain_error("Impossible to complete multiplication. Received an interval that doesn't match the condition\n");
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


int32_t CountDifferentElements(int32_t* array, int32_t size)
{
	int32_t count{};

	for (size_t i{}; i < size; ++i)
	{
		bool isUnique{true};

		for (size_t j{}; j < i; ++j) {
			if (array[i] == array[j]) {
				isUnique = false;
				break;
			}
		}

		if (isUnique)
		{
			++count;
		}
	}

	return count;
}


int32_t IndexOfMaxElement(int32_t* array, int32_t size)
{
	int32_t max{ abs(array[0]) };
	int32_t index{};
	for (int32_t i{ 1 }; i < size; ++i)
	{
		if (max <= abs(array[i]))
		{
			max = abs(array[i]);
			index = i;
		}
	}
	return index;
}


int64_t MultiplicationElements(int32_t* array, int32_t size)
{
	int32_t indexMax{ IndexOfMaxElement(array, size) };
	if (indexMax == size - 1)
	{
		throw std::domain_error("Impossible to complete multiplication. Location of the element doesn't match the condition\n");
	}
	else
	{
		double multiplication{ 1 };
		for (int32_t i{ indexMax + 1 }; i < size; ++i)
		{
			multiplication *= array[i];
		}
		return multiplication;
	}
}


void BubbleSort(int32_t*& array, int32_t size)
{
	for (size_t i{}; i < size; ++i)
	{
		for (size_t j{}; j < size - i - 1; ++j)
		{
			if (array[j] >= 0 && array[j + 1] < 0)
			{
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}