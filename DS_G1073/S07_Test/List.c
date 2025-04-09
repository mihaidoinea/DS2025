#include "Shared.h"

SNode* createNode(Student* info)
{
	SNode* node = (SNode*)malloc(sizeof(SNode));
	if (node != NULL)
	{
		node->info = info;
		node->next = NULL;
	}
	return node;
}

void insertList(SNode** head, Student* pStud)
{
	SNode* node = createNode(pStud);
	if (node != NULL)
	{
		if (*head != NULL)
		{
			SNode* tmp = *head;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = node;
		}
		else
		{
			*head = node;
		}
	}
}