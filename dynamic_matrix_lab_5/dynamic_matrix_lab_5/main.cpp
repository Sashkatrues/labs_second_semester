#include "header.h"


int main()
{

	try
	{
		std::cout << "Task first\n";
		int32_t rows{};
		std::cout << "Input rows of array\n";
		InputSizeFirst(rows);
		TaskFirst(rows);
	}
	catch (std::invalid_argument& e) { std::cout << e.what(); }


	try
	{
		std::cout << "Task second\n";
		int32_t rows{};
		std::cout << "Input rows of array\n";
		InputSizeSecond(rows);		
		TaskSecond(rows);
	}
	catch (std::invalid_argument& e) { std::cout << e.what(); }
	std::cout << '\n';
	system("pause");
	return 0;
}
