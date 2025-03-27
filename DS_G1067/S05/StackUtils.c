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
	return stack == NULL ? 1 : 0;
}
void pushStudent(Node** topStack, Student* stud)
{
	Node* node = createNode(stud);
	if (node != NULL)
	{
		if (emptyStack(*topStack))
			node->next = node->prev = node;
		else
		{
			//connect the node to the structure
			node->next = (*topStack);
			node->prev = (*topStack)->prev;
			//connect the structure to the node
			(*topStack)->prev->next = node; //last->next = first
			(*topStack)->prev = node;
		}
		*topStack = node;
	}
}
Student* popStudent(Node** stack)
{
	Student* info = NULL;
	if (!emptyStack(*stack))
	{
		info = (*stack)->info;
		Node* tmp = *stack;
		if (tmp->next == tmp)
			*stack = NULL;
		else
		{
			//second->prev = last
			(*stack)->next->prev = (*stack)->prev;
			//last->next = second
			(*stack)->prev->next = (*stack)->next;
			(*stack) = tmp->next;
			free(tmp);
		}
	}
	return info;
}
Student* peekStudent(Node* stack)
{
	Student* stud = NULL;
	if (!emptyStack(stack))
	{
		stud = stack->info;
	}
	return stud;
}