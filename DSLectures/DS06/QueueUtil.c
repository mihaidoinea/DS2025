#include "Shared.h"

void putStudent(Node** tail, Student* stud)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->info = stud;
		if (*tail == NULL)
			node->next = node;
		else
		{
			node->next = (*tail)->next;
			(*tail)->next = node;
		}
		*tail = node;
	}
}

Student* getStudent(Node** tail)
{
	Student* result = NULL;
	if ((*tail) != NULL)
	{
		result = (*tail)->next->info;
		Node* tmp = (*tail)->next;
		if (tmp->next == tmp)
			*tail = NULL;
		else
			(*tail)->next = tmp->next;
		free(tmp);
	}
	return result;
}