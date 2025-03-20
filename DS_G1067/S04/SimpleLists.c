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
Node* insertTailList(Node* head, Student* pStud)
{
	Node* node = createNode(pStud);
	if (head == NULL)
		return node;
	else
	{
		Node* tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
		return head;
	}
}
void printSimpleList(Node* head)
{
	while (head != NULL)
	{
		printStudent(head->info);
		head = head->next;
	}
}

void deleteSimpleList(Node** pHead)
{
	while (*pHead)
	{
		Node* tmp = *pHead;
		(*pHead) = tmp->next;

		deleteStudent(tmp->info);
		free(tmp);
	}
}