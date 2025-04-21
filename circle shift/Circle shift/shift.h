#ifndef SHIFT
#define SHIFT


#include <iostream>
#include <iomanip>
#include <random>


void InputSize(int32_t&);
int32_t** CreateMatrix(int32_t, int32_t);
void FillMatrix(int32_t**, int32_t, int32_t);
void InputType(char&);
void CircleShiftLeft(int32_t**, int32_t, int32_t);
void CircleShiftRight(int32_t**, int32_t, int32_t);
void CircleShiftUp(int32_t**, int32_t, int32_t);
void CircleShiftDown(int32_t**, int32_t, int32_t);
void PrintMatrix(int32_t**, int32_t, int32_t);
void DeleteMatrix(int32_t**, int32_t);
void ChooseShift(char, int32_t**, int32_t, int32_t);


#endif