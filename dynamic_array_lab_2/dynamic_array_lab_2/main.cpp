#include "functions.h"


int main()
{
	int32_t size{};
	char type{};

	try
	{
		std::cout << "First Task\n";
		InputSize(size);
		TaskFirst(size, type);
	}
	catch (std::invalid_argument& e) { std::cout << e.what(); }

	try
	{
		std::cout << "Second Task\n";
		InputSize(size);
		TaskSecond(size, type);
	}
	catch (std::invalid_argument& e) { std::cout << e.what(); }
	system("pause");
	return 0;
}