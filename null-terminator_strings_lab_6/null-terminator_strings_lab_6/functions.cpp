#include "header.h"


char* CreateString()
{
	char* str = new char[300]();
	return str;
}


void InputString(char* str)
{
	std::cin.getline(str, 300);
	if (strlen(str) == 0)
	{
		throw  std::invalid_argument("Impossible to complete. Sentence is empty\n");
	}

}


bool OrderSymbols(char* token)
{
	for (int32_t i{}; i < strlen(token) - 1; ++i)
	{
		if (token[i] >= token[i + 1])
		{
			return false;
		}
	}
	return true;
}


void FindMaxOrderWords(char* str, char* delim)
{
	char* demy = CreateString();
	char* result = CreateString();

	char* token = strtok(str, delim);
	if (token == NULL)
	{
		throw std::invalid_argument("Impossible to complete. Sentence doesn't consist of letters\n");
	}
	while (token != NULL)
	{
		if (OrderSymbols(token))
		{
			if (strlen(token) > strlen(demy))
			{
				strcpy(demy, token);
				strcpy(result, demy);
			}
			else if (strlen(demy) == strlen(token))
			{
				strcat(result, " ");
				strcat(result, token);
			}
		}
		token = strtok(NULL, delim);
	}
	if (strlen(result) == 0)
	{
		throw std::invalid_argument("No words with order\n");
	}
	std::cout << "Max order words: " << result << '\n';
	DeleteString(demy);
	DeleteString(result);

}


void DeleteString(char* str)
{
	delete[]str;
}