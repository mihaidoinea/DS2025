#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct _Student
{
	float income;
	short group;
	char* name;
};
typedef struct _Student Student;
typedef struct _Student* PStudent;

struct _Node
{
	Student* info;
	struct _Node* next;
	struct _Node* prev;
};

typedef struct _Node	Node;
typedef struct _Node*	PNode;

Student* createStudent(const char*, short, float);
void deleteStudent(Student*);
void printStudent(Student*);

//simple linked lists functions
void insertHeadList(Node**, Student*);
Node* insertTailList(Node*, Student*);
void deleteSimpleList(Node**);
void printSimpleList(Node*);

//STACK functions
void pushStudent(Node**, Student*);
Student* popStudent(Node**);
Student* peekStudent(Node*);

void convertArrayToSortedCircularDoublyLinkedList(Student**,Node**);
