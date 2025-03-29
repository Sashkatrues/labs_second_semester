#ifndef FUNCTIONS
#define FUNCTIONS


#include <iostream>
#include <cmath>
#include <cstdlib>
#include <random>


void InputSize(int32_t&);


void CreateArray(int32_t*& array, int32_t size);
void CreateArray(double*& array, int32_t size);

void InputTask(char&);
void Task(int32_t, char);
void InputChouse(char&);


template <class Type>
void InputArray(Type* array, int32_t size)
{
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
}


void FillArray(int32_t*, int32_t, int32_t, int32_t);
void FillArray(double*, int32_t, double, double);


template <class Type>
void ChouseInputingArray(Type*& array, int32_t size, char chouse)
{
	Type firstElement{};
	Type lastElement{};
	switch (chouse)
	{
	case 'h':
		CreateArray(array, size);
		InputArray(array, size);
		break;
	case 'r':
		CreateArray(array, size);
		InputInterval(firstElement, lastElement);
		FillArray(array, size, firstElement, lastElement);
		break;
	default:
		throw std::invalid_argument("wrong chouse\n");
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


#endif