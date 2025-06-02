#include "header.h"


int main()
{
	char* str = CreateString();
	char* delim = CreateString();
	try
	{
		std::cout << "Input sentence\n";
		InputString(str);
		std::cout << "Input delim\n";
		InputString(delim);
		FindMaxOrderWords(str, delim);
	}
	catch (std::invalid_argument& e) { std::cout << e.what(); }
	DeleteString(str);
	DeleteString(delim);
	system("pause");
	return 0;
}