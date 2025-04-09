#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256
#define MAX_STUDENTS 10
void main()
{
	Node* list = NULL;
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
			putNode(&list, stud);
		}

		//1. compute the average income per group
		//float incomeAvg = 0.0;
		//int groupNo = 1066;
		//incomeAvg = computeAverage(list, groupNo);
		//printf("Average value: %.2f\n", incomeAvg);

		//2.
		//return the Student with the highest income
		//Student* stud = NULL;
		//findHighestIncome(list, &stud);
		//printStudent(stud);

		//1. & 2.
		//Display all the nodes in the queue 
		//by keeping the queue structure intact

	}
}

