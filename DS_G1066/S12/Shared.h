#pragma once
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
struct _Student
{
	short id;
	short group;
	float income;
	char* name;
};
typedef struct _Student Student;
typedef struct _Student* PStudent;

struct _SNode
{
	Student* info;
	struct _SNode* next;
};

typedef struct _SNode	SNode;
typedef struct _SNode*	PSNode;

struct _Node
{
	Student* info;
	struct _Node* next;
	struct _Node* prev;
};

typedef struct _Node	Node;
typedef struct _Node*	PNode;

//useful information
Student* createStudent(const char*, short, float, short);
void deleteStudent(PStudent);
void printStudent(PStudent);

//array functions
void insertArrayStud(Student*** students, Student* stud, int* noStudents);

//simple lists function
void insertTailList(Node**, Student*);
Node* insertHeadList(Node*, Student*);
Node* deleteSimpleList(Node*);
void printSimpleList(Node*);

//stack functions
void pushStudentHeadList(Node**, Student*);
void pushStudentTailList(Node**, Student*);
Student* popStudentHeadList(Node**);
Student* popStudentTailList(Node**);
void displayStack(Node**);

//double linked lists
void insertStudentsSortedByIncome(Node**, Student*);

//test functions
void insertList(SNode**, Student*);

//HashTable definitions
#define HASH_SIZE 26
typedef struct HashTable
{
	SNode** buckets;
	int size;
} HashTable;

void putStudent(HashTable*, Student*);
Student* getStudent(HashTable, const char*);
void deleteStud(HashTable, const char*);
void printHashTable(HashTable);

//PriorityQueue definitions
#define PQUEUE_SIZE 13
typedef struct PQueue
{
	Student** items;
	int size;
	int currentPosition;
}PQueue;

void enqueue(PQueue*, Student*);
Student* dequeue(PQueue*);

//Binary Search Tree definitions
typedef struct BST
{
	Student* data;
	char bFactor;
	struct BST* left;
	struct BST* right;
}BinarySearchTree, *PBinarySearchTree;

void upsert(BinarySearchTree**, Student*);
void preOrder(BinarySearchTree*);
void inOrder(BinarySearchTree*);
void postOrder(BinarySearchTree*);
void deleteNodeByKey(BinarySearchTree**, unsigned short);

//Graph definitions
typedef struct Vertex
{
	Student* info;
	struct Neighbour* adjacencyList;
	struct Vertex* next;
	short vetex_id;
}Vertex;

typedef struct Neighbour
{
	struct Vertex* mainVertex;
	struct Neighbour* next;
}Neighbour;

void insertVertex(Vertex**, Student*,short);
void addEdge(Vertex*, int, int);
void convertAdjacencyListToMatrix(Vertex*, short, int***);
void graphTraversal(int** matrix, short noVertices, short startVertex);