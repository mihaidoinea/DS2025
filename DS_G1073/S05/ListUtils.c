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
int emptyStack(Node* stack)
{
	if (stack == NULL)
		return 1;
	else 
		return 0;
}
void pushStudentHeadList(Node** head, Student* stud)
{
	Node* node = createNode(stud);
	if (node != NULL)
	{
		if (!emptyStack(*head))
		{
			node->next = *head;
			node->prev = (*head)->prev; //last
			(*head)->prev->next = node;
			(*head)->prev = node;
		}
		else
		{
			node->prev = node->next = node;
		}
		*head = node;
	}
}
Student* popStudentHeadList(Node** head)
{
	Student* stud = NULL;
	if (!emptyStack(*head))
	{
		stud = (*head)->info;
		Node* tmp = (*head);
		if (tmp->next == tmp && tmp->prev == tmp)
		{
			free(tmp);
			*head = NULL;
		}
		else
		{
			//tmp->next == second
			//tmp->prev == last
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			*head = tmp->next;
			free(tmp);
		}
	}
	return stud;
}


void displayStack(Node** head)
{
	Node* tmpStack = NULL;
	Student* stud = NULL;
	while (stud = popStudentHeadList(head))
	{
		printStudent(stud);
		pushStudentHeadList(&tmpStack, stud);
	}
	while (stud = popStudentHeadList(&tmpStack))
	{
		pushStudentHeadList(head, stud);
	}
}
void pushStudentTailList(Node** head, Student* stud)
{
	Node* node = createNode(stud);
	if (node != NULL)
	{
		if (!emptyStack(*head))
		{
			node->next = *head;
			node->prev = (*head)->prev; //last
			(*head)->prev->next = node;
			(*head)->prev = node;
		}
		else
		{
			node->prev = node->next = node;
			*head = node;
		}
	}
}
Student* popStudentTailList(Node** head)
{
	Student* stud = NULL;
	if (!emptyStack(*head))
	{
		stud = (*head)->info;
		Node* tmp = (*head)->prev;
		if (tmp->next == tmp && tmp->prev == tmp)
		{
			free(tmp);
			*head = NULL;
		}
		else
		{
			//tmp->next == first
			//tmp->prev == the one before last
			tmp->next->prev = tmp->prev;
			tmp->prev->next = tmp->next;
			free(tmp);
		}
	}
	return stud;
}