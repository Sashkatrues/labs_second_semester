#ifndef FUNCTIONS
#define FUNCTIONS


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <random>


void InputSize(int32_t&);


//void CreateArray(int32_t*& array, int32_t size);
//void CreateArray(double*& array, int32_t size);


void TaskFirst(int32_t, char);
void TaskSecond(int32_t, char);
void InputChoose(char&);


template <class Type>
void InputArray(Type* array, int32_t size)
{
	std::cout << "Input elements of array\n";
	for (size_t i{}; i < size; ++i)
	{
		std::cin >> array[i];
	}
}


template <class Type>
void InputInterval(Type& firstElement, Type& lastElement)
{
	std::cout << "Input first element in interval\n";
	std::cin >> firstElement;
	std::cout << "Input last element in interval\n";
	std::cin >> lastElement;
	if (firstElement >= lastElement)
	{
		throw std::invalid_argument("Impossible to complete. Wrong interval\n");
	}
}


void FillArray(int32_t*, int32_t, int32_t, int32_t);
void FillArray(double*, int32_t, double, double);

template <class Type>
void CreateArray(Type*& array, int32_t size)
{
	array = new Type[size];
}

template <class Type>
void ChooseInputingArray(Type*& array, int32_t size, char chouse)
{
	Type firstElement{};
	Type lastElement{};
	switch (chouse)
	{
	case 'h':
		CreateArray(array, size);
		InputArray(array, size);
		system("cls");
		break;
	case 'r':
		CreateArray(array, size);
		InputInterval(firstElement, lastElement);
		FillArray(array, size, firstElement, lastElement);
		break;
	default:
		throw std::invalid_argument("Impossible to complete. Wrong chouse\n");
		break;
	}
}


template <class Type>
void PrintArray(Type* array, int32_t size)
{
	for (size_t i{}; i < size; ++i)
	{
		std::cout << array[i] << '\t';
	}
	std::cout << '\n';
}


template <class Type>
void DeleteArray(Type*& array)
{
	delete[] array;
}


double SumPositiveElements(double*, int32_t);
double MultiplicationElements(double*, int32_t);
void BubbleSort(double*&, int32_t);
int32_t CountDifferentElements(int32_t*, int32_t);
int32_t IndexOfMaxElement(int32_t*, int32_t);
int64_t MultiplicationElements(int32_t*, int32_t);
void BubbleSort(int32_t*&, int32_t);


#endif