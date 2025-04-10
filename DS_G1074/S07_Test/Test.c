#include "Shared.h"
Node* createNode(Student* info)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->info = info;
		node->prev = node->next = NULL;
	}
	return node;
}

Node* insertHeadList(Node* head, Student* stud)
{
	Node* node = createNode(stud);
	if (node != NULL)
	{
		node->next = head;
		return node;
	}
	return head;
}
void printSimpleList(Node* head)
{
	while (head)
	{
		printStudent(head->info);
		head = head->next;
	}
}