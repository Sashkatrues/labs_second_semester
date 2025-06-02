#include "students.h"


int main() {
    int32_t size{};
    try
    {
        InputSize(size);

        Student* students = new Student[size];

        for (int32_t i{}; i < size; ++i) {
            std::cout << "Student " << i + 1 << '\n';
            InputName(students, i);
            InputSurname(students, i);
            InputCourse(students, i);
            InputGroup(students, i);
            InputMarks(students, i);
        }

        SortStudents(students, size);

        std::cout << "Sort students:\n";
        PrintStudents(students, size);
        for (int32_t i{}; i < size; ++i) {
            delete students[i].name;
            delete students[i].surname;
        }
        delete students;
    }
    catch (std::invalid_argument& e) { std::cout << e.what(); }

    system("pause");
    return 0;
}