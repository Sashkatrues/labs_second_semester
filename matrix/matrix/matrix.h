#ifndef MATRIX
#define MATRIX


#include <iostream>
#include <iomanip>
#include <random>


void InputSize(int32_t&);
int32_t** CreateMatrix(int32_t, int32_t);
void FillMatrix(int32_t**, int32_t, int32_t);
void FoundIndexRowMaxElement(int32_t**, int32_t, int32_t, int32_t&);
void FoundIndexColMinElement(int32_t**, int32_t, int32_t, int32_t&);
int64_t CountSum(int32_t**, int32_t, int32_t);
int64_t CountMultiply(int32_t**, int32_t, int32_t);
void FillMatrixZero(int32_t**, int32_t, int32_t);
void MultiplyMatrices(int32_t**, int32_t**, int32_t**, int32_t, int32_t, int32_t);
void PrintMatrix(int32_t**, int32_t, int32_t);
void DeleteMatrix(int32_t**, int32_t);
void SumAndMultiply(int32_t, int32_t);
void MultiplyMatrices(int32_t, int32_t);


#endif