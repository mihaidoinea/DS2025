#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256
#define MAX_STUDENTS 10
void main()
{
	Student* students[MAX_STUDENTS];
	memset(students, 0, sizeof(students));

	Node* headList = NULL;

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char delimiter[] = { ',','\0' };
		char buffer[LINE_SIZE], name[LINE_SIZE];
		char* token; float income; int group;
		int index = 0;

		while (fgets(buffer, LINE_SIZE, pFile))
		{
			token = strtok(buffer, delimiter);
			strcpy(name, token);

			token = strtok(NULL, delimiter);
			group = atoi(token);

			token = strtok(NULL, delimiter);
			income = (float)atof(token);

			Student* stud = createStudent(name, group, income);
			students[index++] = stud;
		}

		convertArrayToSortedCircularDoublyLinkedList(students, &headList);
		//headList = convertArrayToSortedCircularDoublyLinkedList(students);
		Node* iterator = headList;
		do
		{
			printStudent(iterator->info);
			iterator = iterator->next;
		} while (iterator != headList);
	}
}

Node* createNode(Student* info)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->info = info;
		node->next = node->prev = NULL;
	}
	return node;
}

void convertArrayToSortedCircularDoublyLinkedList(Student** students,
	Node** headList)
{
	for(int index=0; index<MAX_STUDENTS; index++)
		if (students[index] != NULL)
		{
			Node* node = createNode(students[index]);
			if (*headList == NULL)
			{
				node->next = node->prev = node;
				*headList = node;
			}
			else
			{
				Node* ref = *headList;
				//insert at the begining of the list
				if (node->info->income < ref->info->income)
				{
					node->next = ref;
					node->prev = ref->prev;
					ref->prev->next = node;
					ref->prev = node;
					*headList = node;
				}
				else
				{
					do
					{
						ref = ref->next;
					} while (ref != *headList && 
						node->info->income > ref->info->income);

					node->next = ref;
					node->prev = ref->prev;
					ref->prev->next = node;
					ref->prev = node;
				}
			}
		}
}




