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