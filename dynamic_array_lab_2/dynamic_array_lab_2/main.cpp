#include "functions.h"


int main()
{
	int32_t size{};
	char type{};

	try
	{
		InputSize(size);

		try
		{
			InputTask(type);
			Task(size, type);
		}
		catch (std::invalid_argument& e) { std::cout << e.what(); }
	}
	catch (std::invalid_argument& e) { std::cout << e.what(); }
	system("pause");
	return 0;
}