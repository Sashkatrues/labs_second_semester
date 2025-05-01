#ifndef POLINOM
#define POLINOM


#include <iostream>
#include <cstdlib>
#include <random>


void InputSize(int32_t&);
void CreateArray(double*&, int32_t);
void InputArray(double*&, int32_t);
void InputX(double&);
void InputElement(double&);
int32_t FindElement(double*, double, int32_t);
double CountGorner(double*, double, int32_t);
void MultiplyPolinomials(double*, int32_t, double*, int32_t, double*&, int32_t&);
void PrintArray(double*, int32_t);
void DeleteArray(double*&);
void CountPolinom(double*, int32_t);
void MultiplyPolinomials(int32_t, int32_t);


#endif