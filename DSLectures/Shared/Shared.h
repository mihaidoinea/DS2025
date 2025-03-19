#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef union Reference
{
	unsigned char intRef;
	unsigned short extRef;
} Reference;
struct _Student
{
	Reference reference;
	char* name;
	unsigned int group;
};
typedef struct _Student Student;
typedef struct _Student* PStudent;
typedef struct _BitReference
{
	short ref : 8;
	short uniId : 7;
	short type : 1;
} BitReference;

Student* createStudent(const char*, int, unsigned short);
void printStudent(Student* stud);
void deleteStudent(Student* stud);