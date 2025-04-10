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
			list = insertHeadList(list, stud);
		}
		//1. count the number of students that have the income below average
		//int noStudents = 0;
		//noStudents = belowAverage(list);
		//printf("No. of students below average: %d\n", noStudents);

		//2. compute the number of times the maximum value appears in the
		// list in O(n) complexity
		//int frequency = 0;
		//computeMaxFrequency(vector, &frequency);
		//printf("Maximum frequency: %.2f\n", frequency);

		//1. & 2.
		//move the node that contains a certain student given by his/her name
		//in front of the list and display the list
	}
}