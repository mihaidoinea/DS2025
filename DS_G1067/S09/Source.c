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

			enqueue(&pQueue, stud);

			printf("\n---------NEXT ITERATION-------------\n");
			for (int i = 0; i < pQueue.currentIndex; i++)
				printStudent(pQueue.items[i]);
		}
	}
}