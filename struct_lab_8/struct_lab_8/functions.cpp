#include "students.h"


void InputSize(int32_t& size)
{
    std::cout << "Input size of students: ";
    std::cin >> size;
    if (std::cin.fail() || size <= 0)
    {
        throw std::invalid_argument("Impossible to complete. Wrong size\n");
    }
}


void InputName(Student* students, int32_t i)
{
    std::cout << "Input name: ";
    std::cin >> students[i].name;
}


void InputSurname(Student* students, int32_t i)
{
    std::cout << "Input surname: ";
    std::cin >> students[i].surname;
}


void InputCourse(Student* students, int32_t i)
{
    std::cout << "Input course: ";
    std::cin >> students[i].course;
    if (std::cin.fail())
    {
        throw std::invalid_argument("Impossible to complete. Wrong course\n");
    }

}


void InputGroup(Student* students, int32_t i)
{
    std::cout << "Input group: ";
    std::cin >> students[i].group;
    if (std::cin.fail())
    {
        throw std::invalid_argument("Impossible to complete. Wrong group\n");
    }
}


void InputMarks(Student* students, int32_t i)
{
    std::cout << "Input 5 marks: ";
    for (int32_t j{}; j < 5; ++j)
    {
        std::cin >> students[i].marks[j];
        if (std::cin.fail() || students[i].marks[j] < 0 || students[i].marks[j] > 10)
        {
            throw std::invalid_argument("Impossible to complete. Wrong mark\n");
        }
    }

}


void SortStudents(Student* students, int32_t size)
{
    bool swapped;
    do
    {
        swapped = false;
        for (int32_t i{}; i < size - 1; ++i)
        {
            if (GetAverageMark(students[i]) < GetAverageMark(students[i + 1]))
            {
                std::swap(students[i], students[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}


double GetAverageMark(const Student& student)
{
    double sum{};
    for (int32_t i{}; i < 5; ++i) {
        sum += student.marks[i];
    }
    return sum / 5.0;
}


void PrintStudents(const Student* students, int32_t size)
{
    bool type{};
    std::cout << "Choose type of sort: 1 - grows, 0 - decrase\n";
    std::cin >> type;
    std::cout << std::left << std::setw(15) << "Name"
        << std::setw(15) << "Surname"
        << std::setw(15) << "Course"
        << std::setw(15) << "Group"
        << std::setw(15) << "Average mark" << '\n';
    if (!type)
    {
        for (int32_t i{}; i < size; ++i)
        {
            std::cout << std::left << std::setw(15) << students[i].name
                << std::setw(15) << students[i].surname
                << std::setw(15) << students[i].course
                << std::setw(15) << students[i].group
                << std::setw(15) << GetAverageMark(students[i]) << '\n';
        }
    }
    else
    {
        for (int32_t i{ size - 1 }; i >= 0; --i)
        {
            std::cout << std::left << std::setw(15) << students[i].name
                << std::setw(15) << students[i].surname
                << std::setw(15) << students[i].course
                << std::setw(15) << students[i].group
                << std::setw(15) << GetAverageMark(students[i]) << '\n';
        }
    }
}