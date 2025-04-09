#include "Shared.h"
Node* createNode(Student* info)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->info = info;
		node->next = node->prev = NULL;
	}
	return node;
}
void putNode(Node** pHead, Student* pStud)
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