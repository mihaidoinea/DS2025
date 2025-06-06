#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256
#define MAX_STUDENTS 10

void main()
{
	PQueue pQueue = { .items = NULL, .size = 0, .currentIndex = -1 };

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

			enqueue(&pQueue, stud);

			printf("\n-------------------NEXT ITERATION---------------\n");
			for (int i = 0; i < pQueue.currentIndex; i++)
			{
				printStudent(pQueue.items[i]);
			}
		}

		printf("\n-----------------DEQUEING DATA STRUCTURES---------------\n");
		Student* value = NULL;
		while ((value = dequeue(&pQueue)) != NULL)
		{
			printStudent(value);
		}
	}
}