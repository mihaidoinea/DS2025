#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256

void main()
{

	PQueue pQueue = { .items = NULL, .size = 0, .currentPosition = -1 };

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

			enqueue(&pQueue, stud);
		
			printf("\n-----------NEXT ITERATION----------------\n");

			for (int i = 0; i < pQueue.currentPosition; i++)
			{
				printStudent(pQueue.items[i]);
			}
		}
		printf("\n-----------FINAL----------------\n");
		Student* stud = NULL;
		while((stud = dequeue(&pQueue))!= NULL)
		{
			printStudent(stud);
		}
	}
}