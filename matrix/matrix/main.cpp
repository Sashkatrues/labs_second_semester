#include "matrix.h"


int main()
{
	int32_t rows{};
	int32_t cols{};
	try
	{
		std::cout << "input rows\n";
		InputSize(rows);
		try
		{
			std::cout << "input cols\n";
			InputSize(cols);
			SumAndMultiply(rows, cols);
		}
		catch (const std::invalid_argument& e) { std::cout << e.what() << '\n'; };
	}
	catch (const std::invalid_argument& e) { std::cout << e.what() << '\n'; }


	int32_t rowsFirst{};
	int32_t colsFirst{};
	try
	{
		std::cout << "input rows first matrix\n";
		InputSize(rowsFirst);
		try
		{
			std::cout << "input cols first matrix\n";
			InputSize(colsFirst);
			MultiplyMatrices(rowsFirst, colsFirst);
		}
		catch (const std::invalid_argument& e) { std::cout << e.what() << '\n'; };
	}
	catch (const std::invalid_argument& e) { std::cout << e.what() << '\n'; }

	return 0;
}