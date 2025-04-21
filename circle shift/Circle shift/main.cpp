#include "shift.h"


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
			int32_t** matrix = CreateMatrix(rows, cols);
			FillMatrix(matrix, rows, cols);
			PrintMatrix(matrix, rows, cols);
			std::cout << '\n';
			try
			{
				char type{};
				InputType(type);
				ChooseShift(type, matrix, rows, cols);
				DeleteMatrix(matrix, rows);
			}
			catch (const std::invalid_argument& e) { std::cout << e.what() << '\n'; };
		}
		catch (const std::invalid_argument& e) { std::cout << e.what() << '\n'; };
	}
	catch (const std::invalid_argument& e) { std::cout << e.what() << '\n'; }

	return 0;
}