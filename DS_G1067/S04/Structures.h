#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//typedef struct _Student
//{
//	char* name;
//} Student, *PStudent;
struct _Student
{
	float income;
	short group;
	char* name;
};
typedef struct _Student Student;
typedef struct _Student* PStudent;

Student* createStudent(const char*, short, float);
void deleteStudent(Student*);