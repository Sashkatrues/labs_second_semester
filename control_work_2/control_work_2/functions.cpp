#include "header.h"


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

int32_t CountStudents(const char* filename) 
{
    std::ifstream fin(filename);
    CheckInputFile(fin);
    int32_t count{};
    std::string line;
    while (fin.getline(line)) count++;
    fin.close();
    return count;
}

void InputStudentsFromFile(const char* filename, Student* students, int32_t size) 
{
    std::ifstream fin(filename);
    char buffer[100];
    int32_t i{};

    while (fin.getline(students[i].name, 30, ';')) 
    {
        fin >> students[i].group;
        fin.ignore();
        fin >> students[i].grade;
        fin.ignore();
        ++i;
    }
}

void OutputStudents(const Student* students, int32_t size) {
    for (int32_t i{}; i < size; ++i) 
    {
        std::cout << students[i].name << " |Group : " << students[i].group
            << " |Grade : " << students[i].grade << "\n";
    }
}

void OutputStudentsFile(const char* filename, const Student* students, int32_t size)
{
    std::ofstream fout(filename);
    for (int32_t i{}; i < size; ++i)
    {
       fout << students[i].name << " |Group : " << students[i].group
            << " |Grade : " << students[i].grade << "\n";
    }
    fout.close();
}

void SortByName(Student* students, int32_t size) 
{
    for (int32_t i{}; i < size - 1; ++i)
    {
        for (int32_t j{ i + 1 }; j < size; ++j)
        {
            if (strcmp(students[i].name, students[j].name) > 0)
            {
                std::swap(students[i], students[j]);
            }
        }
    }
}

void SortByGroupAndName(Student* students, int32_t size) 
{
    for (int32_t i{}; i < size - 1; ++i)
    {
        for (int32_t j{ i + 1 }; j < size; ++j)
        {
            if (students[i].group > students[j].group || (students[i].group == students[j].group && strcmp(students[i].name, students[j].name) > 0))
            {
                std::swap(students[i], students[j]);
            }
        }
    }
}

int32_t FindBySurname(const Student* students, int32_t size, const char* surname) 
{
    for (int32_t i{}; i < size; ++i) 
    {
        if (std::strstr(students[i].name, surname) == students[i].name) 
        {
            return i;
        }
    }
    return -1;
}

void SortStudentsByGrage(Student* students, int32_t size)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int32_t i{}; i < size - 1; ++i)
        {
            if (students[i].grade < students[i + 1].grade)
            {
                std::swap(students[i], students[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}