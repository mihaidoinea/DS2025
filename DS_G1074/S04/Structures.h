#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct _Student
{
	char* name;
	float income;
	short group;
};
typedef struct _Student		Student;
typedef struct _Student*	PStudent;

//definition of a SLL
struct _Node
{
	Student* info;
	struct _Node* next;
};

typedef struct _Node	Node;
typedef struct _Node*	PNode;

Student* createStudent(const char*, short, float);
void deleteStudent(PStudent);

//simple linked lists functions
Node* insertHeadList(Node*, Student*);