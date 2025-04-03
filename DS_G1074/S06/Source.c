#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256
#define MAX_STUDENTS 10
void main()
{
	Student* students[MAX_STUDENTS];
	memset(students, 0, sizeof(students));

	Node* list = NULL;

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char delimiter[] = { ',','\0' };
		char name[LINE_SIZE], buffer[LINE_SIZE];
		float income; int group;
		char* token;
		int noStud = 0, index =0;
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

		convertToSortedDoublyLinkedList(students, &list);
		//list = convertToSortedDoublyLinkedList(students);
		Node* tmp = list;
		do {
			printStudent(tmp->info);
			tmp = tmp->next;
		} while (tmp != list);
	}
}

Node* createNode(Student* info)
{
	Node* node = (Node*)malloc(sizeof(Node));
	if (node != NULL)
	{
		node->info = info;
		node->prev = node->next = NULL;
	}
	return node;
}

void convertToSortedDoublyLinkedList(Student** students, Node** head)
{
	for (int i = 0; i < MAX_STUDENTS; i++)
		if (students[i] != NULL)
		{
			Node* node = createNode(students[i]);
			if (node != NULL)
			{
				//an empty circular dobly linked list
				if (*head == NULL)
				{
					node->prev = node->next = node;
					*head = node;
				}
				else
				{
					Node* ref = *head;
					if (node->info->income < ref->info->income)
					{
						node->next = ref;
						node->prev = ref->prev;
						ref->prev->next = node;
						ref->prev = node;
						*head = node;
					}
					else
					{
						do
						{
							ref = ref->next;
						} while (ref != *head &&
							node->info->income > ref->info->income);

						//connect the node to the structure
						node->next = ref;
						node->prev = ref->prev;
						ref->prev->next = node;
						ref->prev = node;
					}
				}
			}
		}
}


