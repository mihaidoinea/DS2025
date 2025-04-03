#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256
#define MAX_STUDENTS 10
void main()
{
	Student* students[MAX_STUDENTS];
	memset(students, 0, sizeof(students));

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char buffer[LINE_SIZE], name[LINE_SIZE];
		char* token; float income; int group;
		int index = 0;

		char delimiter[] = { ',','\0' };
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
		Node* listHead = NULL;
		convertArrayToCircularSortedDoublyLinkedList(students, &listHead);
		//listHead = convertArrayToCircularSortedDoublyLinkedList(students);

		Node* iterator = listHead;
		do
		{
			printStudent(iterator->info);
			iterator = iterator->next;
		} while (iterator != listHead);
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

void convertArrayToCircularSortedDoublyLinkedList(Student** students, Node** head) {
	
	Node* node = NULL;
	for (int i = 0; i < MAX_STUDENTS; i++)
	{
		if (students[i] != NULL)
		{
			node = createNode(students[i]);
			if (node != NULL)
			{
				if (*head == NULL)
				{
					node->next = node->prev = node;
					*head = node;
				}
				else
				{
					Node* ref = *head;
					if (ref->info->income > node->info->income)
						*head = node;
					else
					{
						do
						{
							ref = ref->next;
						} while (ref != *head && node->info->income > ref->info->income);
					}
					node->next = ref;
					node->prev = ref->prev;
					ref->prev->next = node;
					ref->prev = node;
				}
			}
		}
	}
}

