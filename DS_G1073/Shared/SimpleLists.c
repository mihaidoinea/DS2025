#include "Shared.h"
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
void insertTailList(Node** head, Student* pStud)
{
	Node* node = createNode(pStud);
	if (node != NULL)
	{
		if (*head != NULL)
		{
			Node* tmp = *head;
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

Node* deleteSimpleList(Node* head)
{
	while (head != NULL)
	{
		Node* tmp = head;
		head = tmp->next;
		deleteStudent(tmp->info);
		free(tmp);
	}
	return NULL;
}

Node* insertHeadList(Node* head, Student* info)
{
	Node* node = NULL;
	node = createNode(info);
	if(node != NULL)
	{
		node->next = head;
		return node;
	}
	return head;
}

void printSimpleList(Node* head)
{
	while (head != NULL)
	{
		printStudent(head->info);
		head = head->next;
	}
}