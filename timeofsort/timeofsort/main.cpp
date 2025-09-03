#include "header.h"


int main()
{
	char type{};
	try
	{
		InputType(type);
		ChouseType(type);
	}
	catch (std::invalid_argument& e) { std::cout << e.what(); }
	system("pause");
	return 0;
}
