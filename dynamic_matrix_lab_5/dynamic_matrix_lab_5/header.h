#ifndef HEADER
#define HEADER


#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <random>


void InputSizeFirst(int32_t&);
void TaskFirst(int32_t);
int32_t** CreateMatrix(int32_t);
void InputingSpiralMatrix(int32_t**, int32_t);
void PrintMatrix(int32_t**, int32_t);
int32_t SumSecondaryDiagonal(int32_t**, int32_t);
void DeleteMatrix(int32_t**, int32_t);
void InputSizeSecond(int32_t&);
void TaskSecond(int32_t);
void InputChoose(char&);
void ChooseInputingMatrix(int32_t**, int32_t, char);
void InputMatrix(int32_t**, int32_t);
void InputInterval(int32_t&, int32_t&);
void FillMatrix(int32_t**, int32_t, int32_t, int32_t);
int32_t SumLowerRightTriangle(int32_t**, int32_t);
void CenterSpiralMatrix(int32_t**, int32_t);


#endif