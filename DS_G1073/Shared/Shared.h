#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct _Student
{
	short group;
	float income;
	char* name;
};
typedef struct _Student Student;
typedef struct _Student* PStudent;

//useful information
Student* createStudent(const char*, short, float);
void deleteStudent(PStudent);
void printStudent(PStudent);

//array functions
void insertArrayStud(Student*** students, Student* stud, int* noStudents);