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
	struct _Node* prev;
};
typedef struct _Node	Node;
typedef struct _Node*	PNode;

Student* createStudent(const char*, short, float);
void deleteStudent(PStudent);
void printStudent(PStudent);
void insertHeadList(Node**, Student*);
//void insertHeadList(PNode*, pStud);
void printList(PNode);

//stack functions
void pushStudentTailList(Node**, Student*);
void pushStudentHeadList(Node**, Student*);
Student* popStudentTailList(Node**);
Student* popStudentHeadList(Node**);
void deleteStack(Node**);

//sparse matrix (square) of pointers to Student
//node article for a sparse list
typedef struct _SparseNode
{
	int row;
	int column;
	Student* info;
	struct _SparseNode* next;
} SparseNode;


//I: a passed by value array of pointers to Student (Student**)
//I: the number of elements
//O: the function returns a matrix of pointers to Student
Student*** loadMatrix(Student**, int);
void convertToSparseList(Student***, int, SparseNode**);
