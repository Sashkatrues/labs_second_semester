
/*Ничего не работает*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdlib>

void SumMaxMin(int32_t*, int32_t);
void Sort(int32_t*, char*, int32_t);

int main() {
    int32_t size;
    std::cout << "Input count of strings: ";
    std::cin >> size;
    std::cin.ignore();

    char line[100];
    char* word = new char[100]();
    int32_t number{};
    char* arrayWords = new char[size];
    int32_t* arrayNumber = new int32_t[size];
    int32_t c{};
    for (int32_t i{}; i < size; ++i) {
        std::cout << "Input string\n";
        std::cin.getline(line, 100);
        char* token = strtok(line, " ");
        strcpy(word, token);
        for(c; c < strlen(word); ++c)
        {
            arrayWords[c] = word[c];
        }
        arrayNumber[i] = atoi(strtok(NULL, " "));
    }

    Sort(arrayNumber, arrayWords, size);

    std::cout << "sort strings:\n";
    for (int32_t i = 0; i < size; ++i) {
        std::cout << arrayWords[i] << " " << arrayNumber[i] << '\n';
    }

    SumMaxMin(arrayNumber, size);
    system("pause");
    return 0;
}


void Sort(int32_t* arrayNumber, char* arrayWords, int32_t size)
{
    int32_t temp{};
    char* tempWord = new char[100]();

    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arrayNumber[i] > arrayNumber[j]) {
                temp = arrayNumber[i];
                arrayNumber[i] = arrayNumber[j];
                arrayNumber[j] = temp;
                /*for (int32_t c{}; c < ; ++c)
                {
                    for (int32_t b{}; b <  ; ++b)
                    {
                        tempWord[c] = arrayWords[c];
                        arrayWords[c] = arrayWords[b];
                        arrayWords[b] = tempWord[c];
                    }
                }*/
            }
        }
    }
}

void SumMaxMin(int32_t* arrayNumber, int32_t size)
{
    int32_t sum{};
    int32_t maxNum = arrayNumber[0];
    int32_t minNum = arrayNumber[0];

    for (int32_t i{}; i < size; ++i) {
        sum += arrayNumber[i];
        if (arrayNumber[i] > maxNum)
        {
            maxNum = arrayNumber[i];
        }
        if (arrayNumber[i] < minNum)
        {
            minNum = arrayNumber[i];
        }
    }
    std::cout << "Sum: " << sum << '\n';
    std::cout << "Min: " << minNum << '\n';
    std::cout << "Max: " << maxNum << '\n';
}