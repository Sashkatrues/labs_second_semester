#include "polinom.h"


int main()
{
	int32_t size{};
	try
	{
		std::cout << "Input size of coeff array\n";
		InputSize(size);

		double* array = nullptr;
		CreateArray(array, size);
		std::cout << "input coeff array\n";
		InputArray(array, size);

		CountPolinom(array, size);

		double element{};
		try
		{
			InputElement(element);
			std::cout << "pozition element: " << FindElement(array, element, size) << '\n';
		}
		catch (std::logic_error& e) { std::cout << e.what(); }

		DeleteArray(array);

		std::cout << '\n';
	}
	catch (std::invalid_argument& e) { std::cout << e.what(); }

	try
	{
		std::cout << "Input size of first coeff array\n";
		int32_t countCoeff1{};
		InputSize(countCoeff1);
		std::cout << "Input size of second coeff array\n";
		int32_t countCoeff2{};
		InputSize(countCoeff2);

		MultiplyPolinomials(countCoeff1, countCoeff2);

		system("pause");
	}
	catch (std::invalid_argument& e) { std::cout << e.what(); }

	return 0;
}