#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256

void putStudent(Node**, Student*);
Student* getStudent(Node**);

void main()
{
	Node* simplyCircularLinkedTailQueue = NULL;

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char delimiter[] = { ',','\0' };
		char* token = NULL;
		unsigned short reference = 0, group = 0;
		char name[LINE_SIZE], buffer[LINE_SIZE];

		while (fgets(buffer, LINE_SIZE, pFile))
		{
			token = strtok(buffer, delimiter);
			strcpy(name, token);

			token = strtok(NULL, delimiter);
			group = atoi(token);

			token = strtok(NULL, delimiter);
			reference = atoi(token);

			Student* stud = createStudent(name, group, reference);
			//printStudent(stud);
			//deleteStudent(stud);
			putStudent(&simplyCircularLinkedTailQueue, stud);

		}

		Student* stud = NULL;
		while ((stud = getStudent(&simplyCircularLinkedTailQueue)) != NULL)
		{
			printStudent(stud);
			deleteStudent(stud);
		}
	}
}