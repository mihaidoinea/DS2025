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
void pushStudentTailList(Node**, Student*);
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
Student* popStudentTailList(Node**);