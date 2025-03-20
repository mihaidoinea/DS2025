#include "Structures.h"
Node* createNode(Student* pStud)
{
	Node* node = NULL;
	node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->next = NULL;
		node->info = pStud;
	}
	return node;
}
void insertHeadList(Node** pHead, Student* pStud)
{
	Node* node = createNode(pStud);
	if (node != NULL)
	{
		node->next = *pHead;
		*pHead = node;
	}	
}
Node* insertTailList(Node*, Student*);
void deleteSimpleList(Node**);
void printSimpleList(Node* head)
{
	while (head != NULL)
	{
		printSt
	}
}