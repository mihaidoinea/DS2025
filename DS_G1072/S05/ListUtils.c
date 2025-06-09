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

void pushStudentTailList(Node** head, Student* pStud)
{
	Node* node = createNode(pStud);
	if (node != NULL)
	{
		if (*head == NULL)
		{
			node->next = node->prev = node;
			*head = node;
		}
		else
		{
			node->next = *head;
			node->prev = (*head)->prev;
			node->next->prev = node;
			node->prev->next = node;
		}
	}
}

void pushStudentHeadList(Node** head, Student* pStud)
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
Student* popStudentHeadList(Node** head)
{
	Student* student = NULL;
	if (*head != NULL)
	{
		student = (*head)->info;
		Node* tmp = *head;
		//connecting second(tmp->next) and last(tmp->prev) 
		//between each other
		if ((*head)->next != (*head))
		{
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			*head = tmp->next;
		}
		else
			*head = NULL;
		free(tmp);
		
	}
	return student;
}

void deleteStack(Node** head)
{
	Student* stud = NULL;
	while((stud = popStudentHeadList(head)) != NULL)
	{
		printStudent(stud);
		deleteStudent(stud);
	}
}