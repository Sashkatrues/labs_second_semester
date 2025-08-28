#include "header.h"

void BubbleSort(int32_t* arr, int32_t size, bool sort)
{
	bool swap{ false };
	if (sort)
	{
		for (int32_t i{}; i < size; ++i)
		{
			swap = false;
			for (int32_t j{}; j < size - i - 1; ++j)
			{
				if (arr[j] > arr[j + 1])
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
	else
	{
		for (int32_t i{}; i < size; ++i)
		{
			for (int32_t j{}; j < size - i - 1; ++j)
			{
				if (arr[j] < arr[j + 1])
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
}
void BubbleSort(double* arr, int32_t size, bool sort)
{
	bool swap{ false };
	if (sort)
	{
		for (int32_t i{}; i < size; ++i)
		{
			swap = false;
			for (int32_t j{}; j < size - i - 1; ++j)
			{
				if (arr[j] > arr[j + 1])
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
	else
	{
		for (int32_t i{}; i < size; ++i)
		{
			for (int32_t j{}; j < size - i - 1; ++j)
			{
				if (arr[j] < arr[j + 1])
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
}
void BubbleSort(char* arr, int32_t size, bool sort)
{
	bool swap{ false };
	if (ChouseSort())
	{
		for (int32_t i{}; i < size; ++i)
		{
			swap = false;
			for (int32_t j{}; j < size - i - 1; ++j)
			{
				if (arr[j] > arr[j + 1])
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
	else
	{
		for (int32_t i{}; i < size; ++i)
		{
			for (int32_t j{}; j < size - i - 1; ++j)
			{
				if (arr[j] < arr[j + 1])
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
}
void BubbleSort(std::string* arr, int32_t size, bool sort)
{
	bool swap{ false };
	if (sort)
	{
		for (int32_t i{}; i < size; ++i)
		{
			swap = false;
			for (int32_t j{}; j < size - i - 1; ++j)
			{
				if (arr[j] > arr[j + 1])
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
	else
	{
		for (int32_t i{}; i < size; ++i)
		{
			for (int32_t j{}; j < size - i - 1; ++j)
			{
				if (arr[j] < arr[j + 1])
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
}
void BubbleSort(Student* arr, int32_t size, bool sort) {
	bool swap{ false };
	if (sort) {
		for (int32_t i{}; i < size; ++i) {
			swap = false;
			for (int32_t j{}; j < size - i - 1; ++j) {
				if (arr[j].course > arr[j + 1].course ||
					(arr[j].course == arr[j + 1].course && arr[j].group > arr[j + 1].group) ||
					(arr[j].course == arr[j + 1].course && arr[j].group == arr[j + 1].group && arr[j].name > arr[j + 1].name)) {
					std::swap(arr[j], arr[j + 1]);
					swap = true;
				}
			}
			if (!swap) break;
			ShowArray(arr, size);
		}
		ShowArray(arr, size);
	}
	else {
		for (int32_t i{}; i < size; ++i) {
			swap = false;
			for (int32_t j{}; j < size - i - 1; ++j) {
				if (arr[j].course < arr[j + 1].course ||
					(arr[j].course == arr[j + 1].course && arr[j].group < arr[j + 1].group) ||
					(arr[j].course == arr[j + 1].course && arr[j].group == arr[j + 1].group && arr[j].name < arr[j + 1].name))
				{
					std::swap(arr[j], arr[j + 1]);
					swap = true;
				}
			}
			if (!swap) break;
			ShowArray(arr, size);
		}
		ShowArray(arr, size);
	}
}

void CombSort(int32_t* arr, int32_t size, bool sort)
{
	int32_t step = size;
	bool swapped = true;
	if (sort)
	{
		while (step > 1 || swapped)
		{
			step = std::max(1, step * 4 / 5);
			swapped = false;
			for (int32_t i{}; i + step < size; ++i)
			{
				if (arr[i] > arr[i + step])
				{
					std::swap(arr[i], arr[i + step]);
					swapped = true;
				}
			}
			ShowArray(arr, size);
		}
	}
	else
	{
		while (step > 1 || swapped) {
			step = std::max(1, step * 4 / 5);
			swapped = false;
			for (int32_t i{}; i + step < size; ++i)
			{
				if (arr[i] < arr[i + step])
				{
					std::swap(arr[i], arr[i + step]);
					swapped = true;
				}
			}
			ShowArray(arr, size);
		}
	}
}
void CombSort(double* arr, int32_t size, bool sort)
{
	int32_t step = size;
	bool swapped = true;
	if (sort)
	{
		while (step > 1 || swapped)
		{
			step = std::max(1, step * 4 / 5);
			swapped = false;
			for (int32_t i{}; i + step < size; ++i)
			{
				if (arr[i] > arr[i + step])
				{
					std::swap(arr[i], arr[i + step]);
					swapped = true;
				}
			}
			ShowArray(arr, size);
		}
	}
	else
	{
		while (step > 1 || swapped) {
			step = std::max(1, step * 4 / 5);
			swapped = false;
			for (int32_t i{}; i + step < size; ++i)
			{
				if (arr[i] < arr[i + step])
				{
					std::swap(arr[i], arr[i + step]);
					swapped = true;
				}
			}
			ShowArray(arr, size);
		}
	}
}
void CombSort(char* arr, int32_t size, bool sort)
{
	int32_t step = size;
	bool swapped = true;
	if (sort)
	{
		while (step > 1 || swapped)
		{
			step = std::max(1, step * 4 / 5);
			swapped = false;
			for (int32_t i{}; i + step < size; ++i)
			{
				if (arr[i] > arr[i + step])
				{
					std::swap(arr[i], arr[i + step]);
					swapped = true;
				}
			}
			ShowArray(arr, size);
		}
	}
	else
	{
		while (step > 1 || swapped) {
			step = std::max(1, step * 4 / 5);
			swapped = false;
			for (int32_t i{}; i + step < size; ++i)
			{
				if (arr[i] < arr[i + step])
				{
					std::swap(arr[i], arr[i + step]);
					swapped = true;
				}
			}
			ShowArray(arr, size);
		}
	}
}
void CombSort(std::string* arr, int32_t size, bool sort)
{
	int32_t step = size;
	bool swapped = true;
	if (sort)
	{
		while (step > 1 || swapped)
		{
			step = std::max(1, step * 4 / 5);
			swapped = false;
			for (int32_t i{}; i + step < size; ++i)
			{
				if (arr[i] > arr[i + step])
				{
					std::swap(arr[i], arr[i + step]);
					swapped = true;
				}
			}
			ShowArray(arr, size);
		}
	}
	else
	{
		while (step > 1 || swapped) {
			step = std::max(1, step * 4 / 5);
			swapped = false;
			for (int32_t i{}; i + step < size; ++i)
			{
				if (arr[i] < arr[i + step])
				{
					std::swap(arr[i], arr[i + step]);
					swapped = true;
				}
			}
			ShowArray(arr, size);
		}
	}
}
void CombSort(Student* arr, int32_t size, bool sort)
{
	int32_t step = size;
	bool swapped = true;
	if (sort)
	{
		while (step > 1 || swapped)
		{
			step = std::max(1, step * 4 / 5);
			swapped = false;
			for (int32_t i{}; i + step < size; ++i)
			{
				if (arr[i].course > arr[i + step].course ||
					(arr[i].course == arr[i + step].course && arr[i].group > arr[i + step].group) ||
					(arr[i].course == arr[i + step].course && arr[i].group == arr[i + step].group && arr[i].name > arr[i + step].name))
				{
					std::swap(arr[i], arr[i + step]);
					swapped = true;
				}
			}
			ShowArray(arr, size);
		}
	}
	else
	{
		while (step > 1 || swapped) {
			step = std::max(1, step * 4 / 5);
			swapped = false;
			for (int32_t i{}; i + step < size; ++i)
			{
				if (arr[i].course < arr[i + step].course ||
					(arr[i].course == arr[i + step].course && arr[i].group < arr[i + step].group) ||
					(arr[i].course == arr[i + step].course && arr[i].group == arr[i + step].group && arr[i].name < arr[i + step].name))
				{
					std::swap(arr[i], arr[i + step]);
					swapped = true;
				}
			}
			ShowArray(arr, size);
		}
	}
}

void InsertionSort(int32_t* arr, int32_t size, bool sort) {
	ShowArray(arr, size);
	for (int32_t i{ 1 }; i < size; i++) {
		int32_t j{ i - 1 };
		if (sort) {
			while (j >= 0 && arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				--j;
				ShowArray(arr, size);
			}
		}
		else {
			while (j >= 0 && arr[j] < arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				--j;
				ShowArray(arr, size);
			}
		}
	}
}
void InsertionSort(double* arr, int32_t size, bool sort) {
	ShowArray(arr, size);
	for (int32_t i{ 1 }; i < size; i++) {
		int32_t j{ i - 1 };
		if (sort) {
			while (j >= 0 && arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				--j;
				ShowArray(arr, size);
			}
		}
		else {
			while (j >= 0 && arr[j] < arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				--j;
				ShowArray(arr, size);
			}
		}
	}
}
void InsertionSort(char* arr, int32_t size, bool sort) {
	ShowArray(arr, size);
	for (int32_t i{ 1 }; i < size; i++) {
		int32_t j{ i - 1 };
		if (sort) {
			while (j >= 0 && arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				--j;
				ShowArray(arr, size);
			}
		}
		else {
			while (j >= 0 && arr[j] < arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				--j;
				ShowArray(arr, size);
			}
		}
	}
}
void InsertionSort(std::string* arr, int32_t size, bool sort) {
	ShowArray(arr, size);
	for (int32_t i{ 1 }; i < size; i++) {
		int32_t j{ i - 1 };
		if (sort) {
			while (j >= 0 && arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				--j;
				ShowArray(arr, size);
			}
		}
		else {
			while (j >= 0 && arr[j] < arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				--j;
				ShowArray(arr, size);
			}
		}
	}
}
void InsertionSort(Student* arr, int32_t size, bool sort) {
	ShowArray(arr, size);
	for (int32_t i{ 1 }; i < size; i++) {
		int32_t j{ i - 1 };
		if (sort) {
			while ((j >= 0 && arr[j].course > arr[j + 1].course) ||
				(j >= 0 && arr[j].course == arr[j + 1].course && arr[j].group > arr[j + 1].group) ||
				(j >= 0 && arr[j].course == arr[j + 1].course && arr[j].group == arr[j + 1].group && arr[j].name > arr[j + 1].name))
			{
				std::swap(arr[j], arr[j + 1]);
				--j;
				ShowArray(arr, size);
			}
		}
		else {
			while ((j >= 0 && arr[j].course < arr[j + 1].course) ||
				(j >= 0 && arr[j].course == arr[j + 1].course && arr[j].group < arr[j + 1].group) ||
				(j >= 0 && arr[j].course == arr[j + 1].course && arr[j].group == arr[j + 1].group && arr[j].name < arr[j + 1].name))
			{
				std::swap(arr[j], arr[j + 1]);
				--j;
				ShowArray(arr, size);
			}
		}
	}
}

int32_t GetSmallOfBegin(int32_t* arr, int32_t i, int32_t size) {
	int32_t pos{ i };
	for (int32_t k{ i }; k < size; ++k) {
		if (arr[k] < arr[pos])
			pos = k;
	}
	return pos;
}
int32_t GetSmallOfBegin(double* arr, int32_t i, int32_t size) {
	int32_t pos{ i };
	for (int32_t k{ i }; k < size; ++k) {
		if (arr[k] < arr[pos])
			pos = k;
	}
	return pos;
}
int32_t GetSmallOfBegin(char* arr, int32_t i, int32_t size) {
	int32_t pos{ i };
	for (int32_t k{ i }; k < size; ++k) {
		if (arr[k] < arr[pos])
			pos = k;
	}
	return pos;
}
int32_t GetSmallOfBegin(std::string* arr, int32_t i, int32_t size) {
	int32_t pos{ i };
	for (int32_t k{ i }; k < size; ++k) {
		if (arr[k] < arr[pos])
			pos = k;
	}
	return pos;
}
int32_t GetSmallOfBegin(Student* arr, int32_t i, int32_t size) {
	int32_t pos{ i };
	for (int32_t k{ i }; k < size; ++k) {
		if (arr[k].course < arr[pos].course ||
			(arr[k].course == arr[pos].course && arr[k].group < arr[pos].group) ||
			(arr[k].course == arr[pos].course && arr[k].group == arr[pos].group && arr[k].name < arr[pos].name)) {
			pos = k;
		}
	}
	return pos;
}

int32_t GetSmallOfEnd(int32_t* arr, int32_t i, int32_t size) {
	int32_t pos{ i };
	for (int32_t k{}; k <= i; ++k) {
		if (arr[k] < arr[pos])
			pos = k;
	}
	return pos;
}
int32_t GetSmallOfEnd(double* arr, int32_t i, int32_t size) {
	int32_t pos{ i };
	for (int32_t k{}; k <= i; ++k) {
		if (arr[k] < arr[pos])
			pos = k;
	}
	return pos;
}
int32_t GetSmallOfEnd(char* arr, int32_t i, int32_t size) {
	int32_t pos{ i };
	for (int32_t k{}; k <= i; ++k) {
		if (arr[k] < arr[pos])
			pos = k;
	}
	return pos;
}
int32_t GetSmallOfEnd(std::string* arr, int32_t i, int32_t size) {
	int32_t pos{ i };
	for (int32_t k{}; k <= i; ++k) {
		if (arr[k] < arr[pos])
			pos = k;
	}
	return pos;
}
int32_t GetSmallOfEnd(Student* arr, int32_t i, int32_t size) {
	int32_t pos{ i };
	for (int32_t k{}; k <= i; ++k) {
		if (arr[k].course < arr[pos].course ||
			(arr[k].course == arr[pos].course && arr[k].group < arr[pos].group) ||
			(arr[k].course == arr[pos].course && arr[k].group == arr[pos].group && arr[k].name < arr[pos].name)) {
			pos = k;
		}
	}
	return pos;
}

int32_t Divide(int32_t* arr, int32_t start, int32_t sup_elem, int32_t size, bool sort) {
	int32_t i{ start };
	if (sort) {
		while (i < sup_elem) {
			if (arr[i] > arr[sup_elem] && i == sup_elem - 1) {
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else if (arr[i] > arr[sup_elem]) {
				std::swap(arr[sup_elem - 1], arr[sup_elem]);
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else {
				++i;
			}
		}
	}
	else {
		while (i < sup_elem) {
			if (arr[i] < arr[sup_elem] && i == sup_elem - 1) {
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else if (arr[i] < arr[sup_elem]) {
				std::swap(arr[sup_elem - 1], arr[sup_elem]);
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else {
				++i;
			}
		}
	}
	return sup_elem;
}
int32_t Divide(double* arr, int32_t start, int32_t sup_elem, int32_t size, bool sort) {
	int32_t i{ start };
	if (sort) {
		while (i < sup_elem) {
			if (arr[i] > arr[sup_elem] && i == sup_elem - 1) {
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else if (arr[i] > arr[sup_elem]) {
				std::swap(arr[sup_elem - 1], arr[sup_elem]);
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else {
				++i;
			}
		}
	}
	else {
		while (i < sup_elem) {
			if (arr[i] < arr[sup_elem] && i == sup_elem - 1) {
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else if (arr[i] < arr[sup_elem]) {
				std::swap(arr[sup_elem - 1], arr[sup_elem]);
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else {
				++i;
			}
		}
	}
	return sup_elem;
}
int32_t Divide(char* arr, int32_t start, int32_t sup_elem, int32_t size, bool sort) {
	int32_t i{ start };
	if (sort) {
		while (i < sup_elem) {
			if (arr[i] > arr[sup_elem] && i == sup_elem - 1) {
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else if (arr[i] > arr[sup_elem]) {
				std::swap(arr[sup_elem - 1], arr[sup_elem]);
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else {
				++i;
			}
		}
	}
	else {
		while (i < sup_elem) {
			if (arr[i] < arr[sup_elem] && i == sup_elem - 1) {
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else if (arr[i] < arr[sup_elem]) {
				std::swap(arr[sup_elem - 1], arr[sup_elem]);
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else {
				++i;
			}
		}
	}
	return sup_elem;
}
int32_t Divide(std::string* arr, int32_t start, int32_t sup_elem, int32_t size, bool sort) {
	int32_t i{ start };
	if (sort) {
		while (i < sup_elem) {
			if (arr[i] > arr[sup_elem] && i == sup_elem - 1) {
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else if (arr[i] > arr[sup_elem]) {
				std::swap(arr[sup_elem - 1], arr[sup_elem]);
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else {
				++i;
			}
		}
	}
	else {
		while (i < sup_elem) {
			if (arr[i] < arr[sup_elem] && i == sup_elem - 1) {
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else if (arr[i] < arr[sup_elem]) {
				std::swap(arr[sup_elem - 1], arr[sup_elem]);
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else {
				++i;
			}
		}
	}
	return sup_elem;
}
int32_t Divide(Student* arr, int32_t start, int32_t sup_elem, int32_t size, bool sort) {
	int32_t i{ start };
	if (sort)
	{
		while (i < sup_elem)
		{
			if (arr[i].course > arr[sup_elem].course && i == sup_elem - 1 ||
				(arr[i].course == arr[sup_elem].course && arr[i].group > arr[sup_elem].group && i == sup_elem - 1) ||
				(arr[i].course == arr[sup_elem].course && arr[i].group == arr[sup_elem].group && arr[i].name > arr[sup_elem].name && i == sup_elem - 1))
			{
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else if (arr[i].course > arr[sup_elem].course ||
				(arr[i].course == arr[sup_elem].course && arr[i].group > arr[sup_elem].group) ||
				(arr[i].course == arr[sup_elem].course && arr[i].group == arr[sup_elem].group && arr[i].name > arr[sup_elem].name))
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
	}
	else {
		while (i < sup_elem) {
			if (arr[i].course < arr[sup_elem].course && i == sup_elem - 1 ||
				(arr[i].course == arr[sup_elem].course && arr[i].group < arr[sup_elem].group && i == sup_elem - 1) ||
				(arr[i].course == arr[sup_elem].course && arr[i].group == arr[sup_elem].group && arr[i].name < arr[sup_elem].name && i == sup_elem - 1))
			{
				std::swap(arr[i], arr[sup_elem]);
				--sup_elem;
				ShowArray(arr, size);
			}
			else if (arr[i].course < arr[sup_elem].course ||
				(arr[i].course == arr[sup_elem].course && arr[i].group < arr[sup_elem].group) ||
				(arr[i].course == arr[sup_elem].course && arr[i].group == arr[sup_elem].group && arr[i].name < arr[sup_elem].name))
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
	}
	return sup_elem;
}

void Merge(int32_t* arr, int32_t start, int32_t end, int32_t mid, bool sort)
{
	int32_t* merge_arr{ new int32_t[end + 1] };
	int32_t i{ start };
	int32_t k{ start };
	int32_t j{ mid + 1 };
	if (sort) {
		while (i <= mid && j <= end)
		{
			if (arr[i] < arr[j])
			{
				merge_arr[k++] = arr[i++];
			}
			else
			{
				merge_arr[k++] = arr[j++];
			}
		}

		while (i <= mid)
		{
			merge_arr[k++] = arr[i++];
		}

		while (j <= end)
		{
			merge_arr[k++] = arr[j++];
		}

		for (i = start; i < k; ++i)
		{
			arr[i] = merge_arr[i];
		}
	}
	else
	{
		while (i <= mid && j <= end)
		{
			if (arr[i] > arr[j])
			{
				merge_arr[k++] = arr[i++];
			}
			else
			{
				merge_arr[k++] = arr[j++];
			}
		}

		while (i <= mid)
		{
			merge_arr[k++] = arr[i++];
		}

		while (j <= end)
		{
			merge_arr[k++] = arr[j++];
		}

		for (i = start; i < k; ++i)
		{
			arr[i] = merge_arr[i];
		}
	}
}
void Merge(double* arr, int32_t start, int32_t end, int32_t mid, bool sort)
{
	double* merge_arr{ new double[end + 1] };
	int32_t i{ start };
	int32_t k{ start };
	int32_t j{ mid + 1 };
	if (sort) {
		while (i <= mid && j <= end)
		{
			if (arr[i] < arr[j])
			{
				merge_arr[k++] = arr[i++];
			}
			else
			{
				merge_arr[k++] = arr[j++];
			}
		}

		while (i <= mid)
		{
			merge_arr[k++] = arr[i++];
		}

		while (j <= end)
		{
			merge_arr[k++] = arr[j++];
		}

		for (i = start; i < k; ++i)
		{
			arr[i] = merge_arr[i];
		}
	}
	else
	{
		while (i <= mid && j <= end)
		{
			if (arr[i] > arr[j])
			{
				merge_arr[k++] = arr[i++];
			}
			else
			{
				merge_arr[k++] = arr[j++];
			}
		}

		while (i <= mid)
		{
			merge_arr[k++] = arr[i++];
		}

		while (j <= end)
		{
			merge_arr[k++] = arr[j++];
		}

		for (i = start; i < k; ++i)
		{
			arr[i] = merge_arr[i];
		}
	}
}
void Merge(char* arr, int32_t start, int32_t end, int32_t mid, bool sort)
{
	char* merge_arr{ new char[end + 1] };
	int32_t i{ start };
	int32_t k{ start };
	int32_t j{ mid + 1 };
	if (sort) {
		while (i <= mid && j <= end)
		{
			if (arr[i] < arr[j])
			{
				merge_arr[k++] = arr[i++];
			}
			else
			{
				merge_arr[k++] = arr[j++];
			}
		}

		while (i <= mid)
		{
			merge_arr[k++] = arr[i++];
		}

		while (j <= end)
		{
			merge_arr[k++] = arr[j++];
		}

		for (i = start; i < k; ++i)
		{
			arr[i] = merge_arr[i];
		}
	}
	else
	{
		while (i <= mid && j <= end)
		{
			if (arr[i] > arr[j])
			{
				merge_arr[k++] = arr[i++];
			}
			else
			{
				merge_arr[k++] = arr[j++];
			}
		}

		while (i <= mid)
		{
			merge_arr[k++] = arr[i++];
		}

		while (j <= end)
		{
			merge_arr[k++] = arr[j++];
		}

		for (i = start; i < k; ++i)
		{
			arr[i] = merge_arr[i];
		}
	}
}
void Merge(std::string* arr, int32_t start, int32_t end, int32_t mid, bool sort)
{
	std::string* merge_arr{ new std::string[end + 1] };
	int32_t i{ start };
	int32_t k{ start };
	int32_t j{ mid + 1 };
	if (sort) {
		while (i <= mid && j <= end)
		{
			if (arr[i] < arr[j])
			{
				merge_arr[k++] = arr[i++];
			}
			else
			{
				merge_arr[k++] = arr[j++];
			}
		}

		while (i <= mid)
		{
			merge_arr[k++] = arr[i++];
		}

		while (j <= end)
		{
			merge_arr[k++] = arr[j++];
		}

		for (i = start; i < k; ++i)
		{
			arr[i] = merge_arr[i];
		}
	}
	else
	{
		while (i <= mid && j <= end)
		{
			if (arr[i] > arr[j])
			{
				merge_arr[k++] = arr[i++];
			}
			else
			{
				merge_arr[k++] = arr[j++];
			}
		}

		while (i <= mid)
		{
			merge_arr[k++] = arr[i++];
		}

		while (j <= end)
		{
			merge_arr[k++] = arr[j++];
		}

		for (i = start; i < k; ++i)
		{
			arr[i] = merge_arr[i];
		}
	}
}
void Merge(Student* arr, int32_t start, int32_t end, int32_t mid, bool sort)
{
	Student* merge_arr{ new Student[end + 1] };
	int32_t i{ start };
	int32_t k{ start };
	int32_t j{ mid + 1 };
	if (sort) {
		while (i <= mid && j <= end)
		{
			if (arr[i].course < arr[j].course ||
				(arr[i].course == arr[j].course && arr[i].group < arr[j].group) ||
				(arr[i].course == arr[j].course && arr[i].group == arr[j].group && arr[i].name < arr[j].name))
			{
				merge_arr[k++] = arr[i++];
			}
			else
			{
				merge_arr[k++] = arr[j++];
			}
		}

		while (i <= mid)
		{
			merge_arr[k++] = arr[i++];
		}

		while (j <= end)
		{
			merge_arr[k++] = arr[j++];
		}

		for (i = start; i < k; ++i)
		{
			arr[i] = merge_arr[i];
		}
	}
	else
	{
		while (i <= mid && j <= end)
		{
			if (arr[i].course > arr[j].course ||
				(arr[i].course == arr[j].course && arr[i].group > arr[j].group) ||
				(arr[i].course == arr[j].course && arr[i].group == arr[j].group && arr[i].name > arr[j].name))
			{
				merge_arr[k++] = arr[i++];
			}
			else
			{
				merge_arr[k++] = arr[j++];
			}
		}

		while (i <= mid)
		{
			merge_arr[k++] = arr[i++];
		}

		while (j <= end)
		{
			merge_arr[k++] = arr[j++];
		}

		for (i = start; i < k; ++i)
		{
			arr[i] = merge_arr[i];
		}
	}
}

void CocktailSort(int32_t* arr, int32_t size, bool sort)
{
	int32_t left{};
	int32_t right{ size };
	bool swap{ true };
	ShowArray(arr, size);
	if (sort) {
		while (swap) {
			swap = false;
			for (int32_t i{ left }; i < right - 1; ++i) {
				if (arr[i] > arr[i + 1]) {
					std::swap(arr[i], arr[i + 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			--right;
			for (int32_t i{ right }; i > left; --i) {
				if (arr[i] < arr[i - 1]) {
					std::swap(arr[i], arr[i - 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			++left;
		}
	}
	else {
		while (swap) {
			swap = false;
			for (int32_t i{ left }; i < right - 1; ++i) {
				if (arr[i] < arr[i + 1]) {
					std::swap(arr[i], arr[i + 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			--right;
			for (int32_t i{ right }; i > left; --i) {
				if (arr[i] > arr[i - 1]) {
					std::swap(arr[i], arr[i - 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			++left;
		}
	}
}
void CocktailSort(double* arr, int32_t size, bool sort) {
	int32_t left{};
	int32_t right{ size };
	bool swap{ true };
	ShowArray(arr, size);
	if (sort) {
		while (swap) {
			swap = false;
			for (int32_t i{ left }; i < right - 1; ++i) {
				if (arr[i] > arr[i + 1]) {
					std::swap(arr[i], arr[i + 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			--right;
			for (int32_t i{ right }; i > left; --i) {
				if (arr[i] < arr[i - 1]) {
					std::swap(arr[i], arr[i - 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			++left;
		}
	}
	else {
		while (swap) {
			swap = false;
			for (int32_t i{ left }; i < right - 1; ++i) {
				if (arr[i] < arr[i + 1]) {
					std::swap(arr[i], arr[i + 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			--right;
			for (int32_t i{ right }; i > left; --i) {
				if (arr[i] > arr[i - 1]) {
					std::swap(arr[i], arr[i - 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			++left;
		}
	}
}
void CocktailSort(char* arr, int32_t size, bool sort) {
	int32_t left{};
	int32_t right{ size };
	bool swap{ true };
	ShowArray(arr, size);
	if (sort) {
		while (swap) {
			swap = false;
			for (int32_t i{ left }; i < right - 1; ++i) {
				if (arr[i] > arr[i + 1]) {
					std::swap(arr[i], arr[i + 1]);
					swap = true;
				}
				ShowArray(arr, size);
			}
			--right;
			for (int32_t i{ right }; i > left; --i) {
				if (arr[i] < arr[i - 1]) {
					std::swap(arr[i], arr[i - 1]);
					swap = true;
				}
				ShowArray(arr, size);
			}
			++left;
		}
	}
	else {
		while (swap) {
			swap = false;
			for (int32_t i{ left }; i < right - 1; ++i) {
				if (arr[i] < arr[i + 1]) {
					std::swap(arr[i], arr[i + 1]);
					swap = true;
				}
				ShowArray(arr, size);
			}
			--right;
			for (int32_t i{ right }; i > left; --i) {
				if (arr[i] > arr[i - 1]) {
					std::swap(arr[i], arr[i - 1]);
					swap = true;
				}
				ShowArray(arr, size);
			}
			++left;
		}
	}
}
void CocktailSort(std::string* arr, int32_t size, bool sort) {
	int32_t left{};
	int32_t right{ size };
	bool swap{ true };
	ShowArray(arr, size);
	if (sort) {
		while (swap) {
			swap = false;
			for (int32_t i{ left }; i < right - 1; ++i) {
				if (arr[i] > arr[i + 1]) {
					std::swap(arr[i], arr[i + 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			--right;
			for (int32_t i{ right }; i > left; --i) {
				if (arr[i] < arr[i - 1]) {
					std::swap(arr[i], arr[i - 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			++left;
		}
	}
	else {
		while (swap) {
			swap = false;
			for (int32_t i{ left }; i < right - 1; ++i) {
				if (arr[i] < arr[i + 1]) {
					std::swap(arr[i], arr[i + 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			--right;
			for (int32_t i{ right }; i > left; --i) {
				if (arr[i] > arr[i - 1]) {
					std::swap(arr[i], arr[i - 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			++left;
		}
	}
}
void CocktailSort(Student* arr, int32_t size, bool sort) {
	int32_t left{};
	int32_t right{ size };
	bool swap{ true };
	ShowArray(arr, size);
	if (sort) {
		while (swap) {
			swap = false;
			for (int32_t i{ left }; i < right - 1; ++i) {
				if (arr[i].course > arr[i + 1].course ||
					(arr[i].course == arr[i + 1].course && arr[i].group > arr[i + 1].group) ||
					(arr[i].course == arr[i + 1].course && arr[i].group == arr[i + 1].group && arr[i].name > arr[i + 1].name)) {
					std::swap(arr[i], arr[i + 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			--right;
			for (int32_t i{ right }; i > left; --i) {
				if (arr[i].course < arr[i - 1].course ||
					(arr[i].course == arr[i - 1].course && arr[i].group < arr[i - 1].group) ||
					(arr[i].course == arr[i - 1].course && arr[i].group == arr[i - 1].group && arr[i].name < arr[i - 1].name)) {
					std::swap(arr[i], arr[i - 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			++left;
		}
	}
	else {
		while (swap) {
			swap = false;
			for (int32_t i{ left }; i < right - 1; ++i) {
				if (arr[i].course < arr[i + 1].course ||
					(arr[i].course == arr[i + 1].course && arr[i].group < arr[i + 1].group) ||
					(arr[i].course == arr[i + 1].course && arr[i].group == arr[i + 1].group && arr[i].name < arr[i + 1].name)) {
					std::swap(arr[i], arr[i + 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			--right;
			for (int32_t i{ right }; i > left; --i) {
				if (arr[i].course > arr[i - 1].course ||
					(arr[i].course == arr[i - 1].course && arr[i].group > arr[i - 1].group) ||
					(arr[i].course == arr[i - 1].course && arr[i].group == arr[i - 1].group && arr[i].name > arr[i - 1].name)) {
					std::swap(arr[i], arr[i - 1]);
					swap = true;
					ShowArray(arr, size);
				}
			}
			++left;
		}
	}
}

bool IsSorted(int32_t* arr, int32_t size)
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
bool IsSorted(double* arr, int32_t size)
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
bool IsSorted(char* arr, int32_t size)
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
bool IsSorted(std::string* arr, int32_t size)
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
bool IsSorted(Student* arr, int32_t size)
{
	for (int32_t i{ 1 }; i < size; ++i)
	{
		if (arr[i - 1].course > arr[i].course ||
			(arr[i - 1].course == arr[i].course && arr[i - 1].group > arr[i].group) ||
			(arr[i - 1].course == arr[i].course && arr[i - 1].group == arr[i].group && arr[i - 1].name > arr[i].name))
		{
			return false;
		}
	}
	return true;
}