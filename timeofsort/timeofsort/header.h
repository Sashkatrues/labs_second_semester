#ifndef HEADER_H
#define HEADER_H


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include "header.h";
#include <chrono>

struct Student {
	int course;
	int group;
	std::string name;
	int grades[3];
};

void InputChoice(int32_t&);
void InputType(char& type);
void InputFileName(std::string& fileName);
void ChouseType(char type);
bool ChouseSort();
void ChouseTypeOfSort(int32_t& typeOfSort);


template<typename T>
void ShowArray(T* arr, int32_t size)
{
	for (int32_t i{}; i < size; ++i)
	{
		std::cout << arr[i] << '\t';
	}
	std::cout << '\n';
}
void ShowArray(Student* arr, int32_t size);


void BubbleSort(int32_t* arr, int32_t size, bool sort);
void BubbleSort(double* arr, int32_t size, bool sort);
void BubbleSort(char* arr, int32_t size, bool sort);
void BubbleSort(std::string* arr, int32_t size, bool sort);
void BubbleSort(Student* arr, int32_t size, bool sort);

void CombSort(int32_t* arr, int32_t size, bool sort);
void CombSort(double* arr, int32_t size, bool sort);
void CombSort(char* arr, int32_t size, bool sort);
void CombSort(std::string* arr, int32_t size, bool sort);
void CombSort(Student* arr, int32_t size, bool sort);

void InsertionSort(int32_t* arr, int32_t size, bool sort);
void InsertionSort(double* arr, int32_t size, bool sort);
void InsertionSort(char* arr, int32_t size, bool sort);
void InsertionSort(std::string* arr, int32_t size, bool sort);
void InsertionSort(Student* arr, int32_t size, bool sort);

int32_t GetSmallOfBegin(int32_t* arr, int32_t i, int32_t size);
int32_t GetSmallOfBegin(double* arr, int32_t i, int32_t size);
int32_t GetSmallOfBegin(char* arr, int32_t i, int32_t size);
int32_t GetSmallOfBegin(std::string* arr, int32_t i, int32_t size);
int32_t GetSmallOfBegin(Student* arr, int32_t i, int32_t size);

int32_t GetSmallOfEnd(int32_t* arr, int32_t i, int32_t size);
int32_t GetSmallOfEnd(double* arr, int32_t i, int32_t size);
int32_t GetSmallOfEnd(char* arr, int32_t i, int32_t size);
int32_t GetSmallOfEnd(std::string* arr, int32_t i, int32_t size);
int32_t GetSmallOfEnd(Student* arr, int32_t i, int32_t size);

int32_t Divide(int32_t* arr, int32_t start, int32_t sup_elem, int32_t size, bool sort);
int32_t Divide(double* arr, int32_t start, int32_t sup_elem, int32_t size, bool sort);
int32_t Divide(char* arr, int32_t start, int32_t sup_elem, int32_t size, bool sort);
int32_t Divide(std::string* arr, int32_t start, int32_t sup_elem, int32_t size, bool sort);
int32_t Divide(Student* arr, int32_t start, int32_t sup_elem, int32_t size, bool sort);

void CocktailSort(int32_t* arr, int32_t size, bool sort);
void CocktailSort(double* arr, int32_t size, bool sort);
void CocktailSort(char* arr, int32_t size, bool sort);
void CocktailSort(std::string* arr, int32_t size, bool sort);
void CocktailSort(Student* arr, int32_t size, bool sort);

void Merge(int32_t* arr, int32_t start, int32_t end, int32_t mid, bool sort);
void Merge(double* arr, int32_t start, int32_t end, int32_t mid, bool sort);
void Merge(char* arr, int32_t start, int32_t end, int32_t mid, bool sort);
void Merge(std::string* arr, int32_t start, int32_t end, int32_t mid, bool sort);
void Merge(Student* arr, int32_t start, int32_t end, int32_t mid, bool sort);

bool IsSorted(int32_t* arr, int32_t size);
bool IsSorted(double* arr, int32_t size);
bool IsSorted(char* arr, int32_t size);
bool IsSorted(std::string* arr, int32_t size);
bool IsSorted(Student* arr, int32_t size);


void InputSize(int32_t& size);
template <typename T>
int32_t CountSize(T* arr, std::string& fileName)
{
	std::ifstream fin(fileName);
	T element{};
	int32_t count{};
	while (fin >> element)
	{
		++count;
	}
	fin.close();
	return count;
}


template<typename T>
void ReadFromFile(std::string& filename, T* arr, int32_t size) {
	std::ifstream in(filename);
	for (int32_t i{}; i < size; ++i)
	{
		in >> arr[i];
	}
	in.close();
}
template<typename T>
void WriteToFile(std::string& filename, T* arr, int32_t size) {
	std::ofstream out(filename);
	for (int32_t i{}; i < size; ++i)
	{
		out << arr[i] << "\n";
	}
	out.close();
}
template<typename T>
void InputFromConsole(T* arr, int32_t size)
{
	std::cout << "input array\n";
	for (int32_t i{}; i < size; ++i)
	{
		std::cin >> arr[i];
	}
}
void InputFromConsole(Student* arr, int32_t size);


void InputInterval(int32_t& firstElement, int32_t& lastElement);
void InputInterval(double& firstElement, double& lastElement);

void GenerateRandom(int32_t* arr, int32_t size);
void GenerateRandom(double* arr, int32_t size);
void GenerateRandom(char* arr, int32_t size);
std::string GenerateRandomStr();
void GenerateRandom(std::string* arr, int32_t size);
void GenerateRandom(Student* arr, int32_t size);


template<typename T>
void SelectionSort(T* arr, int32_t size, bool sort)
{
	if (sort)
	{
		for (int32_t i{ 0 }; i < size; ++i)
		{
			int32_t small_pos{ GetSmallOfBegin(arr, i, size) };
			std::swap(arr[i], arr[small_pos]);
			ShowArray(arr, size);
		}
	}
	else
	{
		for (int32_t i{ size - 1 }; i >= 0; --i)
		{
			int32_t small_pos{ GetSmallOfEnd(arr, i, size) };
			std::swap(arr[i], arr[small_pos]);
			ShowArray(arr, size);
		}
	}
}
template<typename T>
void QuickSort(T* arr, int32_t start, int32_t end, int32_t size, bool sort)
{
	if (start < end)
	{
		int32_t sup_elem = Divide(arr, start, end, size, sort);
		QuickSort(arr, start, sup_elem - 1, size, sort);
		QuickSort(arr, sup_elem + 1, end, size, sort);
	}
}
template<typename T>
void MergeSort(T* arr, int32_t start, int32_t end, int32_t size, bool sort)
{
	int32_t mid{};
	if (start < end)
	{

		mid = (start + end) / 2;
		MergeSort(arr, start, mid, size, sort);
		MergeSort(arr, mid + 1, end, size, sort);
		Merge(arr, start, end, mid, sort);
		ShowArray(arr, size);
	}
}
//template <typename T>
//T FindMin(T* arr, int32_t size)
//{
//	T min = arr[0];
//	for (int32_t i{}; i < size; ++i)
//	{
//		if (arr[i] < min)
//		{
//			min = arr[i];
//		}
//	}
//	return min;
//}
//
//template <typename T>
//T FindMax(T* arr, int32_t size)
//{
//	T max = arr[0];
//	for (int32_t i{}; i < size; ++i)
//	{
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//	}
//	return max;
//}
//
//template <typename T>
//void CountSort(T*& arr, int32_t size)
//{
//	T min{ FindMin(arr,size) };
//	T max{ FindMax(arr,size) };
//	int32_t range{ static_cast<int32_t>(max) + 1 };
//	T* counter = new T[range];
//	for (int32_t i{}; i < range; ++i)
//	{
//		counter[i] = 0;
//	}
//	for (int32_t i{}; i < size; ++i)
//	{
//		counter[static_cast<int32_t>(arr[i])]++;
//	}
//	int32_t k{};
//	if (ChouseSort()) {
//		for (int32_t i{}; i < range; ++i)
//		{
//			while (counter[i] > 0)
//			{
//				--counter[i];
//				arr[k++] = i;
//				ShowArray(arr, size);
//			}
//		}
//	}
//	else
//	{
//		for (int32_t i{ range - 1 }; i > 0; --i)
//		{
//			while (counter[i] > 0)
//			{
//				--counter[i];
//				arr[k++] = i;
//				ShowArray(arr, size);
//			}
//		}
//	}
//}
template <class T>
void ShuffleElements(T* arr, int32_t size)
{
	int32_t j{};
	T temp{};

	for (int32_t i{}; i < size; ++i)
	{
		j = rand() % size;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
template <class T>
void BogoSort(T* arr, int32_t size, bool sort)
{
	ShowArray(arr, size);
	if (sort)
	{
		srand(static_cast<unsigned>(time(0)));
		while (!IsSorted(arr, size))
		{
			ShuffleElements(arr, size);
			ShowArray(arr, size);
		}
	}
	else
	{
		srand(static_cast<unsigned>(time(0)));
		while (IsSorted(arr, size))
		{
			ShuffleElements(arr, size);
			ShowArray(arr, size);
		}
	}
}


template <typename T>
void SortArray(T* arr, int32_t size)
{
	int32_t typeOfSort{};
	ChouseTypeOfSort(typeOfSort);
	switch (typeOfSort)
	{
	case 1:
	{
		bool sort{ ChouseSort() };
		ShowArray(arr, size);
		auto start = std::chrono::high_resolution_clock::now();
		BubbleSort(arr, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	case 2:
	{
		bool sort{ ChouseSort() };
		auto start = std::chrono::high_resolution_clock::now();
		CombSort(arr, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	case 3:
	{
		bool sort{ ChouseSort() };
		auto start = std::chrono::high_resolution_clock::now();
		InsertionSort(arr, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	case 4:
	{
		bool sort{ ChouseSort() };
		auto start = std::chrono::high_resolution_clock::now();
		SelectionSort(arr, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	case 5:
	{
		bool sort{ ChouseSort() };
		ShowArray(arr, size);
		auto start = std::chrono::high_resolution_clock::now();
		QuickSort(arr, 0, size - 1, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	case 6:
	{
		bool sort{ ChouseSort() };
		auto start = std::chrono::high_resolution_clock::now();
		MergeSort(arr, 0, size - 1, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	case 7:
	{
		bool sort{ ChouseSort() };
		auto start = std::chrono::high_resolution_clock::now();
		CocktailSort(arr, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	/*case 8:
	{
		auto start = std::chrono::high_resolution_clock::now();
		CountSort(arr, size);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}*/
	case 9:
	{
		bool sort{ ChouseSort() };
		auto start = std::chrono::high_resolution_clock::now();
		BogoSort(arr, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	default:
	{
		throw std::invalid_argument("false choice\n");
		break;
	}

	}

}

template<typename T>
void ChouseInputAndOutput(int32_t choice, T* arr)
{
	switch (choice)
	{
	case 1:
	{
		int32_t size{};
		InputSize(size);
		arr = new T[size];
		InputFromConsole(arr, size);
		SortArray(arr, size);

		std::string filename;
		InputFileName(filename);
		WriteToFile(filename, arr, size);
		delete[] arr;
		break;
	}
	case 2:
	{
		int32_t size{};
		InputSize(size);
		arr = new T[size];
		GenerateRandom(arr, size);
		SortArray(arr, size);

		std::string filename;
		InputFileName(filename);
		WriteToFile(filename, arr, size);
		delete[] arr;
		break;
	}
	case 3:
	{
		std::string fileName;
		InputFileName(fileName);
		int32_t size = CountSize(arr, fileName);
		arr = new T[size];
		ReadFromFile(fileName, arr, size);
		SortArray(arr, size);

		ShowArray(arr, size);
		delete[] arr;
		break;
	}
	default:
	{
		throw std::invalid_argument("false choice\n");
		break;
	}
	}
}


#endif
