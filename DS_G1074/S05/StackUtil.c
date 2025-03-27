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
int emptyStack(Node* head)
{
	return head == NULL ? 1 : 0;
}
void pushStudent(Node** head, Student* stud)
{
	Node* node = createNode(stud);
	if (node != NULL)
	{
		if (emptyStack(*head))
		{
			node->next = node->prev = node;
		}
		else
		{
			//first connect the node to the structure
			node->next = *head;
			node->prev = (*head)->prev;
			//connect the structure to the node
			(*head)->prev->next = node;
			(*head)->prev = node;
		}
		*head = node;
	}
}
Student* popStudent(Node** head)
{
	Student* stud = NULL;
	if (!emptyStack(*head))
	{
		stud = (*head)->info;
		Node* tmp = *head;
		if (tmp->next == tmp)
			*head = NULL;
		else
		{
			//prev of second = last
			//second->prev = last
			tmp->next->prev = tmp->prev;
			//next of last = second
			//last->next = second
			tmp->prev->next = tmp->next;
			*head = tmp->next;
		}
		free(tmp);
	}
	return stud;
}
Student* peekStudent(Node* head)
{
	Student* stud = NULL;
	if (!emptyStack(head))
	{
		stud = head->info;
	}
	return stud;
}