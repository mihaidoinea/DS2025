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
	struct _Node* prev;
};

typedef struct _Node	Node;
typedef struct _Node*	PNode;

Student* createStudent(const char*, short, float);
void deleteStudent(PStudent);
void printStudent(PStudent);

//simple linked lists functions
Node* insertHeadList(Node*, Student*);
void insertTailList(Node**, Student*);
void printSimpleList(Node*);
void deleteSimpleList(Node**);

//STACK functions
void pushStudent(Node**, Student*);
Student* popStudent(Node**);
Student* peekStudent(Node*);