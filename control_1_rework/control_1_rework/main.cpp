#include "header.h"

int main()
{
	try
	{
		int32_t size{};
		InputSize(size);
		try
		{
			char** matrix = new char* [size];
			InputMatrix(matrix, size);

			try
			{
				int32_t* arrayNum = new int32_t[size];
				FoundNumbers(matrix, arrayNum, size);

				SortMatrix(matrix, arrayNum, size);

				PrintMatrix(matrix, size);

				std::cout << "Sum: " << CountSum(arrayNum, size) << '\n';
				std::cout << "Min: " << arrayNum[0] << '\n';
				std::cout << "Max: " << arrayNum[size - 1] << '\n';

				delete arrayNum;
				delete[] matrix;
			}
			catch (std::invalid_argument& e) { std::cout << e.what(); }
		} 
		catch (std::invalid_argument& e) { std::cout << e.what(); }
	}
	catch (std::invalid_argument& e) { std::cout << e.what(); }

	system("pause");
	return 0;
}