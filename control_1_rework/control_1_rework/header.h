#ifndef HEADER
#define HEADER

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>

void InputSize(int32_t&);
void InputMatrix(char**, int32_t);
void FoundNumbers(char**, int32_t*, int32_t);
void SortMatrix(char**, int32_t*, int32_t);
void PrintMatrix(char**, int32_t);
int64_t CountSum(int32_t*, int32_t);

#endif