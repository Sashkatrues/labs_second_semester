#include "functions.h"


void InputSize(int32_t& size)
{
	std::cout << "Input size of array\n";
	std::cin >> size;
	if (size <= 0)
	{
		throw std::invalid_argument("wrong size\n");
	}
}


void InputTask(char& type)
{
	std::cout << "Input number of task '1' - double or '2' - int\n";
	std::cin >> type;

}


void Task(int32_t size, char type)
{
	char chouse{};
	int32_t* array = nullptr;
	double* array2 = nullptr;
	switch (type)
	{
	case '1':
		InputChouse(chouse);
		ChouseInputingArray(array2, size, chouse);
		//system("cls");
		PrintArray(array2, size);
		DeleteArray(array2);
		break;
	case '2':
		InputChouse(chouse);
		ChouseInputingArray(array, size, chouse);
		/*system("cls");*/
		PrintArray(array, size);
		DeleteArray(array);
		break;
	default:
		throw std::invalid_argument("wrong type\n");
		break;
	}
}


void InputChouse(char& chouse)
{
	std::cout << "Input 'h' - by hand or 'r' - by random\n";
	std::cin >> chouse;

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