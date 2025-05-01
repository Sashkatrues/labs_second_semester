#include "polinom.h"


void InputSize(int32_t& size)
{
	std::cin >> size;
	if (size <= 0)
	{
		throw std::invalid_argument("wrong size\n");
	}
}


void CreateArray(double*& array, int32_t size)
{
	array = new double[size];
}


void InputArray(double*& array, int32_t size)
{
	for (size_t i{}; i < size; ++i)
	{
		std::cin >> array[i];
	}
}


void InputX(double& x)
{
	std::cout << "Input x\n";
	std::cin >> x;
}


double CountGorner(double* array, double x, int32_t size)
{
	double sum{};
	for (int32_t i{ size - 1 }; i >= 0; --i)
	{
		sum = sum * x + array[i];
	}
	return sum;
}


void InputElement(double& element)
{
	std::cout << "Input element\n";
	std::cin >> element;
}


int32_t FindElement(double* array, double element, int32_t size)
{
	int32_t index{ false };
	for (int32_t i{}; i < size; ++i)
	{
		if (element == array[i])
		{
			return i + 1;
		}
	}
	if (index == false)
	{
		throw std::logic_error("no element \n");
	}
}


void MultiplyPolinomials(double* coeffFirst, int32_t countCoeff1, double* coeffSecond, int32_t countCoeff2, double*& multiplyCoeff, int32_t& multiplyCoeffSize)
{
	multiplyCoeffSize = countCoeff1 + countCoeff2 - 1;
	CreateArray(multiplyCoeff, multiplyCoeffSize);
	for (int32_t i{}; i < multiplyCoeffSize; ++i)
	{
		multiplyCoeff[i] = 0;
	}

	for (int32_t i{}; i < countCoeff1; ++i)
	{
		for (int32_t j{}; j < countCoeff2; ++j)
		{
			multiplyCoeff[i + j] += coeffFirst[i] * coeffSecond[j];
		}
	}
}


void PrintArray(double* array, int32_t size)
{
	for (size_t i{}; i < size; ++i)
	{
		std::cout << array[i] << '\t';
	}
}


void DeleteArray(double*& array)
{
	delete[] array;
}

void CountPolinom(double* array, int32_t size)
{
	double x{};
	InputX(x);
	std::cout << "sum: " << CountGorner(array, x, size) << '\n';
}


void MultiplyPolinomials(int32_t countCoeff1, int32_t countCoeff2)
{
	double* coeffFirst = nullptr;
	double* coeffSecond = nullptr;
	CreateArray(coeffFirst, countCoeff1);
	CreateArray(coeffSecond, countCoeff2);
	std::cout << "input first coeff array\n";
	InputArray(coeffFirst, countCoeff1);
	std::cout << "input second coeff array\n";
	InputArray(coeffSecond, countCoeff2);

	int32_t multiplyCoeffSize{};
	double* multiplyCoeff = nullptr;
	MultiplyPolinomials(coeffFirst, countCoeff1, coeffSecond, countCoeff2, multiplyCoeff, multiplyCoeffSize);
	std::cout << "multiply coeff: ";
	PrintArray(multiplyCoeff, multiplyCoeffSize);
	std::cout << '\n';

	double y{};
	InputX(y);
	std::cout << "multiply polinomials = " << CountGorner(multiplyCoeff, y, multiplyCoeffSize) << '\n';

	DeleteArray(coeffFirst);
	DeleteArray(coeffSecond);
	DeleteArray(multiplyCoeff);
}