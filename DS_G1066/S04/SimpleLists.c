#include "Structures.h"
Node* createNode(Student* stud)
{
	Node* node = NULL;
	node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->info = stud;
		node->next = NULL;
	}
	return node;
}
void insertTailList(Node** pHead, Student* pStud)
{
	Node* node = createNode(pStud);
	if (node != NULL)
	{
		if (*pHead == NULL)
			*pHead = node;
		else
		{
			Node* tmp = *pHead;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = node;
		}
	}
}
void printSimpleList(Node* head)
{

}