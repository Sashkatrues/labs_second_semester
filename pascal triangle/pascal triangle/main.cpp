#include "triangle.h"


int main()
{
	int32_t rows;
	InputRows(rows);
	int32_t** pascalTriangle = CreatePascalTriangle(rows);
	PrintPascalTriangle(pascalTriangle, rows);
	DeletePascalTriangle(pascalTriangle, rows);
	system("pause");
	return 0;
}