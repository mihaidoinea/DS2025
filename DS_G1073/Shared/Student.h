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

Student* createStudent(const char*, short, float);
void deleteStudent(PStudent);