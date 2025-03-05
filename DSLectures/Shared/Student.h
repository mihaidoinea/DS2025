#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct _Student
{
	char* name;
	int group;
};
typedef struct _Student Student;
typedef struct _Student* PStudent;

Student* createStudent(const char*, int);