#ifndef FILES
#define FILES


#include <iostream>
#include <fstream>
#include <iomanip>


void CheckInputFile(std::ifstream&);
void CheckOutputFile(std::ofstream&);
void InputArray(std::ifstream&, double*, int32_t);
int32_t InputArray(double*, int32_t );
void InputSize(int32_t&);
void InputFileName(char*);
int32_t CountSize(std::ifstream&);
void InputMode(int32_t&);
void InputSortType(bool&);
void OutputArray(double*, int32_t);
void OutputArray(std::ostream&, double*, int32_t);
void InputSecondFileName(char*);
void Merge(bool, double*, int32_t, int32_t, int32_t);
void MergeSort(bool, double*, int32_t, int32_t);
int32_t CountDigit(double);
int32_t CompareGrows(const void*, const void*);
int32_t Compare(const void*, const void*);
void ChooseQSort(bool, double*, int32_t);
void QuickSort(bool, double*, int32_t, int32_t);
void InsertionSort(bool, double*, int32_t);
void SelectionSort(bool, double*, int32_t);
void BubbleSort(bool, double*, int32_t);


#endif