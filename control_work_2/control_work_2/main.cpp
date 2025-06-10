#include "header.h"

int main() 
{
    const char* filename = "students.txt";
    Student* students = nullptr;
    int32_t size{};
    try 
    {
        size = CountStudents(filename);
        students = new Student[size];
        InputStudentsFromFile(filename, students, size);
    }
    catch (const char* msg) { std::cerr << msg; }

    int32_t choice{};
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Sort by surname\n";
        std::cout << "2. found by surname\n";
        std::cout << "3. Sort by group and name\n";
        std::cout << "4. Sort by average grade\n";
        std::cout << "0. Exit\n";
        std::cin >> choice;

        try 
        {
            switch (choice) 
            {
                case 1:
                    SortByName(students, size);
                    OutputStudentsFile(filename, students, size);
                    break;
                case 2: 
                    char surname[30];
                    std::cout << "Input surname: ";
                    std::cin >> surname;
                    int32_t index = FindBySurname(students, size, surname);
                    if (index >= 0)
                        std::cout << "Found: " << students[index].name
                        << ", Group " << students[index].group
                        << ", Grage " << students[index].grade << "\n";
                    else
                        std::cout << "Student no found.\n";
                    break;
                case 3:
                    SortByGroupAndName(students, size);
                    OutputStudents(students, size);
                    break;
                case 4:
                    break;
                case 0:
                    std::cout << "Exit.\n";
                    break;
                default:
                    throw std::invalid_argument("Impossible to complete. Wrong choice\n");
            }
        }
        catch (std::invalid_argument& e) { std::cout << e.what(); }

    } while (choice != 0);

    delete[] students;
    return 0;
}