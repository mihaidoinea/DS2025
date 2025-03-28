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
void insertTailList(Node** pHead, Student* pStud)
{
	Node* node = createNode(pStud);
	if (node != NULL)
	{
		if (*pHead == NULL)
			*pHead = node;
		else
		{
			Node* tmp = *pHead;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = node;
		}
	}
}
void printSimpleList(Node* pHead)
{
	if (pHead != NULL)
	{
		while (pHead != NULL)
		{
			printStudent(pHead->info);
			pHead = pHead->next;
		}
	}
	else
		printf("Lista nu contine elemente\n");
}

void deleteStudByName(Node** pHead, const char* key)
{
	if (*pHead != NULL)
	{
		Node* tmp = *pHead;
		if (strcmp(tmp->info->name, key) == 0)
		{
			*pHead = tmp->next;
			deleteStudent(tmp->info);
			free(tmp);
		}
		else
		{
			while (tmp->next != NULL 
				&& strcmp(tmp->next->info->name, key)!=0)
			{
				tmp = tmp->next;
			}
			Node* aux = tmp->next;
			tmp->next = aux->next;
			deleteStudent(aux->info);
			free(aux);
		}
	}
}