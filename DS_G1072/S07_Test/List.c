#include "Shared.h"
Node* createNode(Student* info)
{
	Node* node = NULL;
	node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->info = info;
		node->next = node->prev = NULL;
	}
	return node;
}

void insertStudent(Node** head, Student* pStud)
{
	Node* node = createNode(pStud);
	if (node != NULL)
	{
		if (*head == NULL)
		{
			node->next = node->prev = node;
		}
		else
		{
			node->next = *head;
			node->prev = (*head)->prev;
			node->prev->next = node;
			node->next->prev = node;
		}
		*head = node;
	}
}