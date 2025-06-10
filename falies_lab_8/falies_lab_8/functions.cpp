#include "files.h"


void CheckInputFile(std::ifstream& fin)
{
    if (!fin.good())
    {
        throw "file doesn't exist\n";
    }
    if (!fin)
    {
        throw "input file error\n";
    }
    if (fin.peek() == EOF)
    {
        throw "file is empty\n";
    }
}


void CheckOutputFile(std::ofstream& fout)
{
    if (!fout.good())
    {
        throw "file doesn't exist\n";
    }
    if (!fout)
    {
        throw "output file error\n";
    }
}


void InputArray(std::ifstream& fin, double* arr, int32_t size)
{
    fin.clear();
    fin.seekg(0);
    for (int32_t i{}; i < size; ++i)
    {
        fin >> arr[i];
    }
}


int32_t InputArray(double* arr, int32_t size)
{
    std::cout << "Input elements of array:\n";
    for (int i{}; i < size; ++i) {
        std::cin >> arr[i];
    }
    return size;
}


void InputSize(int32_t& size)
{
    std::cout << "Input size of array\n";
    std::cin >> size;
    if (size <= 0)
    {
        throw std::invalid_argument("Impossible to complete. Wrong size\n");
    }
}


void InputFileName(char* filename)
{
    std::cout << "Input file name: ";
    std::cin >> filename;
}


int32_t CountSize(std::ifstream& fin)
{
    double num{};
    int32_t count{};
    while (fin >> num)
    {
        ++count;
    }
    return count;
}


void InputMode(int32_t& mode)
{
    std::cout << "Choose: 1 - from file, to consol; 2 - from consol, to file; 3 - from file, to file\n";
    std::cin >> mode;
}


void InputSortType(bool& sortType)
{
    std::cout << "Choose sort: 1 - grows; 0 - decrase\n";
    std::cin >> sortType;
}


void OutputArray(double* arr, int32_t size)
{
    std::cout << "Sort array:\n";
    for (int32_t i{}; i < size; ++i)
    {
        std::cout << std::fixed << std::setprecision(6) << arr[i] << " ";
    }
    std::cout << '\n';

}


void OutputArray(std::ostream& fout, double* arr, int32_t size)
{
    for (int32_t i{}; i < size; ++i)
    {
        fout << std::fixed << std::setprecision(6) << arr[i] << " ";
    }
    fout << '\n';
}


void InputSecondFileName(char* secondFileName)
{
    std::cout << "Input file name for saving: ";
    std::cin >> secondFileName;
}


void Merge(bool sortType, double* arr, int32_t start, int32_t end, int32_t mid)
{
    double* merge_array{ new double[end + 1] };
    int32_t i{ start };
    int32_t k{ start };
    int32_t j{ mid + 1 };
    if (sortType) {
        while (i <= mid && j <= end)
        {
            if (arr[i] < arr[j])
            {
                merge_array[k] = arr[i];
                ++k;
                ++i;
            }
            else
            {
                merge_array[k] = arr[j];
                ++k;
                ++j;
            }
        }

        while (i <= mid)
        {
            merge_array[k] = arr[i];
            ++k;
            ++i;
        }

        while (j <= end)
        {
            merge_array[k] = arr[j];
            ++k;
            ++j;
        }

        for (i = start; i < k; i++)
        {
            arr[i] = merge_array[i];
        }
    }
    else
    {
        while (i <= mid && j <= end)
        {
            if (arr[i] > arr[j])
            {
                merge_array[k] = arr[i];
                ++k;
                ++i;
            }
            else
            {
                merge_array[k] = arr[j];
                ++k;
                ++j;
            }
        }

        while (i <= mid)
        {
            merge_array[k] = arr[i];
            ++k;
            ++i;
        }

        while (j <= end)
        {
            merge_array[k] = arr[j];
            ++k;
            ++j;
        }

        for (i = start; i < k; i++)
        {
            arr[i] = merge_array[i];
        }
    }
}


void MergeSort(bool sortType, double* arr, int32_t start, int32_t end)
{
    int32_t mid{};
    if (start < end)
    {

        mid = (start + end) / 2;
        MergeSort(sortType, arr, start, mid);
        MergeSort(sortType, arr, mid + 1, end);
        Merge(sortType, arr, start, end, mid);
    }
}


int32_t CountDigit(double num)
{
    int32_t count{};
    double fractionPart{ num - static_cast<int32_t>(num) };
    int32_t tempFraction{ static_cast<int32_t> (fractionPart * pow(10,7)) };
    int32_t digit{};
    int32_t reverse{};
    while (tempFraction)
    {
        digit = tempFraction % 10;
        tempFraction /= 10;
        reverse = reverse * 10 + digit;
    }
    while (reverse)
    {
        reverse /= 10;
        ++count;
    }
    return count;
}


int32_t CompareGrows(const void* a, const void* b)
{
    return (CountDigit(*((double*)a)) - CountDigit(*((double*)b)));
}


int32_t Compare(const void* a, const void* b)
{
    return (CountDigit(*((double*)b)) - CountDigit(*((double*)a)));
}


void ChooseQSort(bool sortType, double* arr, int32_t size)
{
    if (sortType)
    {
        qsort(arr, size, sizeof(double), CompareGrows);
    }
    else
    {
        qsort(arr, size, sizeof(double), Compare);
    }

}


void QuickSort(bool sortType, double* arr, int32_t left, int32_t right) {
    int32_t i{ left };
    int32_t j{ right };
    double pivot{ arr[(left + right) / 2] };

    if (sortType)
    {
        while (i <= j)
        {
            while (arr[i] < pivot)
            {
                ++i;
            }
            while (arr[j] > pivot)
            {
                --j;
            }
            if (i <= j) {
                std::swap(arr[i], arr[j]);
                ++i;
                --j;
            }
        }

        if (left < j)
        {
            QuickSort(sortType, arr, left, j);
        }
        if (i < right)
        {
            QuickSort(sortType, arr, i, right);
        }
    }
    else
    {
        while (i <= j)
        {
            while (arr[i] > pivot)
            {
                ++i;
            }
            while (arr[j] < pivot)
            {
                --j;
            }
            if (i <= j) {
                std::swap(arr[i], arr[j]);
                ++i;
                --j;
            }
        }

        if (left < j)
        {
            QuickSort(sortType, arr, left, j);
        }
        if (i < right)
        {
            QuickSort(sortType, arr, i, right);
        }
    }
}


//вставками
void InsertionSort(bool sortType, double* arr, int32_t size)
{
    if (sortType)
    {
        for (int32_t i{ 1 }; i < size; i++)
        {
            double key = arr[i];
            int32_t j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
    else
    {
        for (int32_t i{ 1 }; i < size; i++)
        {
            double key = arr[i];
            int32_t j = i - 1;
            while (j >= 0 && arr[j] < key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }
    }
}


//выбором
void SelectionSort(bool sortType, double* arr, int32_t size) {
    if (sortType)
    {
        for (int32_t i{}; i < size - 1; ++i)
        {
            int32_t minIndex = i;
            for (int32_t j{ i + 1 }; j < size; ++j)
            {
                if (arr[j] < arr[minIndex])
                {
                    minIndex = j;
                }
            }
            std::swap(arr[i], arr[minIndex]);
        }
    }
    else
    {
        for (int32_t i{}; i < size - 1; ++i)
        {
            int32_t maxIndex = i;
            for (int32_t j{ i + 1 }; j < size; ++j)
            {
                if (arr[j] > arr[maxIndex]) maxIndex = j;
            }
            std::swap(arr[i], arr[maxIndex]);
        }
    }
}


void BubbleSort(bool sortType, double* arr, int32_t size)
{
    bool swapped;
    if (sortType)
    {
        do
        {
            swapped = false;
            for (int32_t i{}; i < size - 1; ++i)
            {
                if (arr[i] > arr[i + 1])
                {
                    std::swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }
        } while (swapped);
    }
    else
    {
        do
        {
            swapped = false;
            for (int32_t i{}; i < size - 1; ++i)
            {
                if (arr[i] < arr[i + 1])
                {
                    std::swap(arr[i], arr[i + 1]);
                    swapped = true;
                }
            }
        } while (swapped);
    }
}