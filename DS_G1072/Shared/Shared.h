#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct _Student
{
	short group;
	char* name;
	float income;
};
typedef struct _Student		Student;
typedef struct _Student*	PStudent;

struct _Node
{
	Student* info;
	struct _Node* next;
};
typedef struct _Node	Node;
typedef struct _Node*	PNode;

Student* createStudent(const char*, short, float);
void deleteStudent(PStudent);
void printStudent(PStudent);
void insertHeadList(Node**, Student*);
//void insertHeadList(PNode*, pStud);