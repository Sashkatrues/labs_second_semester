#ifndef HEADER
#define HEADER


#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <map>


struct Student
{
	char name[30];
	int group;
	double grade;
};


void CheckInputFile(std::ifstream& fin);
int32_t CountStudents(const char* filename);
void InputStudentsFromFile(const char* filename, Student* students, int32_t size);
void OutputStudents(const Student* students, int32_t size);
void OutputStudentsFile(const char* filename, const Student* students, int32_t size);
void SortByName(Student* students, int32_t size);
void SortByGroupAndName(Student* students, int32_t size);
int32_t FindBySurname(const Student* students, int32_t size, const char* surname);
void SortStudentsByGrage(Student* students, int32_t size);


#endif