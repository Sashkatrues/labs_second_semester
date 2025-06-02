#ifndef STUDENTS
#define STUDENTS


#include <iostream>
#include <iomanip>
#include <cstring>


struct Student {
    char* name = new char[50];
    char* surname = new char[50];
    int32_t course;
    int32_t group;
    double marks[5];
};


void InputSize(int32_t&);
void InputName(Student*, int32_t);
void InputSurname(Student*, int32_t);
void InputCourse(Student*, int32_t);
void InputGroup(Student*, int32_t);
void InputMarks(Student*, int32_t);
double GetAverageMark(const Student&);
void SortStudents(Student*, int32_t);
void PrintStudents(const Student*, int32_t);


#endif