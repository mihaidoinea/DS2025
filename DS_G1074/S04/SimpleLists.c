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

Node* insertHeadList(Node* head, Student* stud)
{
	Node* node = NULL;
	node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->info = stud;
		//node->next = NULL;
		node->next = head;
		return node;
	}
	return head;
}

void insertTailList(Node** head, Student* stud)
{
	Node* node = createNode(stud);
	if (node != NULL)
	{
		if (*head != NULL)
		{
			Node* tmp = *head;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = node;
		}
		else
		{
			*head = node;
		}
	}
}
void printSimpleList(Node* head)
{
	while (head)
	{
		printStudent(head->info);
		head = head->next;
	}
}
void deleteSimpleList(Node** head)
{
	while (*head)
	{
		Node* tmp = *head;
		*head = tmp->next;
		deleteStudent(tmp->info);
		free(tmp);
	}
}
