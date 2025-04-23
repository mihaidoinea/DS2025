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

struct _Node {
	Student* info;
	struct _Node* next;
};
typedef struct _Node Node;

typedef struct HTable
{
	Student** items;
	int size;
}HashTable;

void resizeHT(HashTable*);
void putHashTable(HashTable*, Student*);
void displayStudents(HashTable);


//Priority Queue definitions
#define PQUEUE_SIZE 7
typedef struct PQueue
{
	Student** items;
	int size;
	int position;
}PriorityQueue;

void enqueue(struct PQueue*, Student*);