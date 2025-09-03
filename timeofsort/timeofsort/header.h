#ifndef HEADER_H
#define HEADER_H


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>

struct Student {
	int32_t course;
	int32_t group;
	std::string name;
	int32_t grades[3];
};

bool operator<(const Student& a, const Student& b);
bool operator>(const Student& a, const Student& b);
bool operator==(const Student& a, const Student& b);
bool operator<<(std::ostream& out, const Student& a);


void CheckInputFile(std::ifstream& fin);
void CheckOutputFile(std::ofstream& fout);


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
	std::ifstream fin(filename);
	CheckInputFile(fin);
	for (int32_t i{}; i < size; ++i)
	{
		fin >> arr[i];
	}
	fin.close();
}
template<typename T>
void WriteToFile(std::string& filename, T* arr, int32_t size) {
	std::ofstream fout(filename);
	CheckOutputFile(fout);
	for (int32_t i{}; i < size; ++i)
	{
		fout << arr[i] << " ";
	}
	fout.close();
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



template <typename T>
void BubbleSort(T* arr, int32_t size, bool sort)
{
	bool swap{ false };
	for (int32_t i{}; i < size; ++i)
	{
		swap = false;
		for (int32_t j{}; j < size - i - 1; ++j)
		{
			if ((arr[j] > arr[j + 1]) ^ sort)
			{
				std::swap(arr[j], arr[j + 1]);
				swap = true;
			}
		}
		if (!swap)
		{
			break;
		}
		ShowArray(arr, size);
	}
	ShowArray(arr, size);
}
template <typename T>
void CombSort(T* arr, int32_t size, bool sort)
{
	int32_t step{ size * 4 / 5 };
	bool swap{ false };
	while (step > 1 || swap) {
		if (step < 1)
		{
			step = 1;
			swap = false;
		}
		for (int32_t i{}; i + step < size; ++i)
		{
			if ((arr[i] > arr[i + step]) ^ sort)
			{
				std::swap(arr[i], arr[i + step]);
				swap = true;
			}
		}
		ShowArray(arr, size);
		step = step * 4 / 5;
	}
}
template<typename T>
void InsertionSort(T* arr, int32_t size, bool sort)
{
	ShowArray(arr, size);
	for (int32_t i{ 1 }; i < size; i++)
	{
		int32_t j{ i - 1 };

		while (j >= 0 && (arr[j] > arr[j + 1]) ^ sort)
		{
			std::swap(arr[j], arr[j + 1]);
			--j;
			ShowArray(arr, size);
		}
	}
}
template<typename T>
int32_t GetSmallOfBegin(T* arr, int32_t i, int32_t size)
{
	int32_t position{ i };
	for (int32_t k{ i }; k < size; ++k)
	{
		if (arr[k] < arr[position])
			position = k;
	}
	return position;
}
template<typename T>
int32_t GetSmallOfEnd(T* arr, int32_t i)
{
	int32_t position{ i };
	for (int32_t k{}; k <= i; ++k)
	{
		if (arr[k] < arr[position])
			position = k;
	}
	return position;
}
template<typename T>
void SelectionSort(T* arr, int32_t size, bool sort)
{
	if (sort)
	{
		for (int32_t i{}; i < size; ++i)
		{
			int32_t small_position{ GetSmallOfBegin(arr, i, size) };
			std::swap(arr[i], arr[small_position]);
			ShowArray(arr, size);
		}
	}
	else
	{
		for (int32_t i{ size - 1 }; i >= 0; --i)
		{
			int32_t small_position{ GetSmallOfEnd(arr, i) };
			std::swap(arr[i], arr[small_position]);
			ShowArray(arr, size);
		}
	}
}
template<typename T>
int32_t Divide(T* arr, int32_t start, int32_t sup_elem, bool sort, int32_t size)
{
	int32_t i{ start };

	while (i < sup_elem)
	{
		if ((arr[i] > arr[sup_elem]) ^ sort && i == sup_elem - 1)
		{
			std::swap(arr[i], arr[sup_elem]);
			--sup_elem;
			ShowArray(arr, size);
		}
		else if ((arr[i] > arr[sup_elem]) ^ sort)
		{
			std::swap(arr[sup_elem - 1], arr[sup_elem]);
			std::swap(arr[i], arr[sup_elem]);
			--sup_elem;
			ShowArray(arr, size);
		}
		else
		{
			++i;
		}
	}

	return sup_elem;
}
template<typename T>
void QuickSortInside(T* arr, int32_t start, int32_t end, bool sort, int32_t size)
{
	if (start < end)
	{
		int32_t sup_elem = Divide(arr, start, end, sort, size);
		ShowArray(arr, size);
		QuickSortInside(arr, start, sup_elem - 1, sort, size);
		QuickSortInside(arr, sup_elem + 1, end, sort, size);
	}
}
template<typename T>
void QuickSort(T* arr, int32_t size, bool sort)
{
	int32_t start{};
	int32_t end{ size - 1 };
	QuickSortInside(arr, start, end, sort, size);
}
template<typename T>
void Merge(T* arr, int32_t start, int32_t end, int32_t mid, bool sort)
{
	T* merge_array{ new T[end + 1] };
	int32_t i{ start };
	int32_t k{ start };
	int32_t j{ mid + 1 };
	while (i <= mid && j <= end)
	{
		if ((arr[i] < arr[j]) ^ sort)
		{
			merge_array[k++] = arr[i++];
		}
		else
		{
			merge_array[k++] = arr[j++];
		}
	}

	while (i <= mid)
	{
		merge_array[k++] = arr[i++];
	}

	while (j <= end)
	{
		merge_array[k++] = arr[j++];
	}

	for (i = start; i < k; ++i)
	{
		arr[i] = merge_array[i];
	}
}
template<typename T>
void MergeSortInside(T* arr, int32_t start, int32_t end, bool sort, int32_t size)
{
	int32_t mid{};
	if (start < end)
	{

		mid = (start + end) / 2;
		MergeSortInside(arr, start, mid, sort, size);
		MergeSortInside(arr, mid + 1, end, sort, size);
		Merge(arr, start, end, mid, sort);
		ShowArray(arr, size);
	}
}
template<typename T>
void MergeSort(T* arr, int32_t size, bool sort)
{
	int32_t start{};
	int32_t end{ size - 1 };
	MergeSortInside(arr, start, end, sort, size);
}
template<typename T>
void CocktailSort(T* arr, int32_t size, bool sort)
{
	ShowArray(arr, size);
	int32_t left{};
	int32_t right{ size };
	bool swap{ true };
	while (swap)
	{
		swap = false;
		for (int32_t i{ left }; i < right - 1; ++i)
		{
			if ((arr[i] > arr[i + 1]) ^ sort)
			{
				std::swap(arr[i], arr[i + 1]);
				swap = true;
				ShowArray(arr, size);
			}
		}
		--right;
		for (int32_t i{ right }; i > left; --i)
		{
			if ((arr[i] < arr[i - 1]) ^ sort)
			{
				std::swap(arr[i], arr[i - 1]);
				swap = true;
				ShowArray(arr, size);
			}
		}
		++left;
	}
}
template <typename T>
T FindMin(T* arr, int32_t size)
{
	T min = arr[0];
	for (int32_t i{1}; i < size; ++i)
	{
		if (arr[i] < min)
		{
			min = arr[i];
		}
	}
	return min;
}
template <typename T>
T FindMax(T* arr, int32_t size)
{
	T max = arr[0];
	for (int32_t i{1}; i < size; ++i)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}
	return max;
}
template <typename T>
void CountSort(T* arr, int32_t size, bool sort)
{
	if constexpr (std::is_same_v<T, int> || std::is_same_v<T, char>)
	{
		ShowArray(arr, size);
		T min{ FindMin(arr,size) };
		T max{ FindMax(arr,size) };
		int32_t range{ static_cast<int32_t>(max) - static_cast<int32_t>(min) + 1 };
		T* counter = new T[range];
		for (int32_t i{}; i < range; ++i)
		{
			counter[i] = 0;
		}
		for (int32_t i{}; i < size; ++i)
		{
			++counter[static_cast<int32_t>(arr[i]) - static_cast<int32_t>(min)];
		}
		int32_t k{};
		if (sort) {
			for (int32_t i{}; i < range; ++i)
			{
				while (counter[i] > 0)
				{
					counter[i]--;
					arr[k++] = i + static_cast<int32_t>(min);
					ShowArray(arr, size);
				}
			}
		}
		else
		{
			for (int32_t i{ range - 1 }; i >= 0; --i)
			{
				while (counter[i] > 0)
				{
					counter[i]--;
					arr[k++] = i + static_cast<int32_t>(min);
					ShowArray(arr, size);
				}
			}
		}
		delete[] counter;
	}
	else
	{
		throw std::invalid_argument("unsupported array type\n");
	}
}
template <class T>
bool IsSorted(T* arr, int32_t size)
{
	for (int32_t i{ 1 }; i < size; ++i)
	{
		if (arr[i - 1] > arr[i])
		{
			return false;
		}
	}
	return true;
}
template <class T>
void ShuffleElements(T* arr, int32_t size)
{
	int32_t j{};
	T temp{};

	for (int32_t i{}; i < size; ++i)
	{
		j = rand() % size;
		std::swap(arr[i], arr[j]);
	}
}
template <class T>
void BogoSort(T* arr, int32_t size, bool sort)
{
	ShowArray(arr, size);
	srand(static_cast<unsigned>(time(0)));
	if (sort)
	{

		while (!IsSorted(arr, size))
		{
			ShuffleElements(arr, size);
			ShowArray(arr, size);
		}
	}
	else
	{
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
		QuickSort(arr, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	case 6:
	{
		bool sort{ ChouseSort() };
		auto start = std::chrono::high_resolution_clock::now();
		MergeSort(arr, size, sort);
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
	case 8:
	{
		bool sort{ ChouseSort() };
		auto start = std::chrono::high_resolution_clock::now();
		CountSort(arr, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
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
