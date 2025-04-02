#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256

void main()
{
	Student** students = NULL;
	int noStudents = 0;

	Node* head = NULL;

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char delimiter[] = { ',','\0' };
		char* token = NULL;
		float income = 0; int group = 0;
		char name[LINE_SIZE];
		char buffer[LINE_SIZE];

		while (fgets(buffer, LINE_SIZE, pFile))
		{
			token = strtok(buffer, delimiter);
			strcpy(name, token);

			token = strtok(NULL, delimiter);
			group = atoi(token);

			token = strtok(NULL, delimiter);
			income = (float)atof(token);

			Student* stud = createStudent(name, group, income);

			insertStudentsSortedByIncome(&head, stud);
			
		}
		int a = 2;
	}
}

Node* createNode(Student* info)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->info = info;
	node->next = node->prev = NULL;
	return node;
}

void insertStudentsSortedByIncome(Node** head, Student* stud)
{
	Node* node = createNode(stud);
	if (*head == NULL)
	{
		node->next = node->prev = node;
		*head = node;
	}
	else
	{
		Node* ref = *head;
		//insertion at the begining 
		if (node->info->income < ref->info->income)
		{
			node->next = ref;
			node->prev = ref->prev;
			ref->prev->next = node;
			ref->prev = node;
			*head = node;
		}
		else //insertion in the middle
		{
			do
			{
				//process the node
				ref = ref->next;
			} while (ref->next != *head && node->info->income > ref->info->income);
			//insert after the last
			if (ref->next == *head && node->info->income > ref->info->income)
			{
				node->prev = ref;
				node->next = ref->next;
				ref->next->prev = node;
				ref->next = node;
			}
			else //insert before node ref
			{
				node->next = ref;
				node->prev = ref->prev;
				ref->prev->next = node;
				ref->prev = node;
			}
		}
	}
}