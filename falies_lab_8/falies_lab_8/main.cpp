#include "files.h"


int main() {
    int32_t size{};
    char* fileName = new char[100];
    char* secondFileName = new char[100];
    int32_t mode;
    InputMode(mode);

    if (mode == 1 || mode == 3)
    {
        InputFileName(fileName);
        std::ifstream fin(fileName);
        try
        {
            CheckInputFile(fin);
            size = CountSize(fin);
            double* arr = new double[size];
            InputArray(fin, arr, size);
            fin.close();
            bool sortType;
            InputSortType(sortType);
            if (mode == 1)
            {
                QuickSort(sortType, arr, 0, size - 1);
                std::cout << "QuickSort: ";
                OutputArray(arr, size);
                InsertionSort(sortType, arr, size);
                std::cout << "InsertionSort: ";
                OutputArray(arr, size);
                SelectionSort(sortType, arr, size);
                std::cout << "SelectionSort: ";
                OutputArray(arr, size);
                BubbleSort(sortType, arr, size);
                std::cout << "BubbleSort: ";
                OutputArray(arr, size);
                ChooseQSort(sortType, arr, size);
                std::cout << "QSort: ";
                OutputArray(arr, size);
                MergeSort(sortType, arr, 0, size - 1);
                std::cout << "MergeSort: ";
                OutputArray(arr, size);
            }
            else
            {
                InputSecondFileName(secondFileName);
                std::ofstream fout(secondFileName);
                CheckOutputFile(fout);
                QuickSort(sortType, arr, 0, size - 1);
                fout << "QuickSort: ";
                OutputArray(fout, arr, size);
                InsertionSort(sortType, arr, size);
                fout << "InsertionSort: ";
                OutputArray(fout, arr, size);
                SelectionSort(sortType, arr, size);
                fout << "SelectionSort: ";
                OutputArray(fout, arr, size);
                BubbleSort(sortType, arr, size);
                fout << "BubbleSort: ";
                OutputArray(fout, arr, size);
                ChooseQSort(sortType, arr, size);
                fout << "QSort: ";
                OutputArray(fout, arr, size);
                MergeSort(sortType, arr, 0, size - 1);
                fout << "MergeSort: ";
                OutputArray(fout, arr, size);
                fout.close();
                std::cout << "All done\n";
            }
        }
        catch (const char* msg) { std::cerr << msg; }
    }
    else if (mode == 2)
    {
        try
        {
            InputSize(size);
            double* arr = new double[size];
            InputArray(arr, size);
            bool sortType;
            InputSortType(sortType);
            InputSecondFileName(secondFileName);
            std::ofstream fout(secondFileName);
            try
            {
                CheckOutputFile(fout);
                QuickSort(sortType, arr, 0, size - 1);
                fout << "QuickSort: ";
                OutputArray(fout, arr, size);
                InsertionSort(sortType, arr, size);
                fout << "InsertionSort: ";
                OutputArray(fout, arr, size);
                SelectionSort(sortType, arr, size);
                fout << "SelectionSort: ";
                OutputArray(fout, arr, size);
                BubbleSort(sortType, arr, size);
                fout << "BubbleSort: ";
                OutputArray(fout, arr, size);
                ChooseQSort(sortType, arr, size);
                fout << "QSort: ";
                OutputArray(fout, arr, size);
                MergeSort(sortType, arr, 0, size - 1);
                fout << "MergeSort: ";
                OutputArray(fout, arr, size);
                fout.close();
            }
            catch (const char* msg) { std::cerr << msg; }
            std::cout << "All done\n";
        }
        catch (std::invalid_argument& e) { std::cout << e.what(); }
    }
    system("pause");
    return 0;
}