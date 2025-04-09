#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256

void main()
{
	SNode* list = NULL;

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
		
			insertList(&list, stud);
		}

		//1.
		//count the number of students from a certain group given as a parameter
		//int noStudents = 0;
		//int groupNo = 1066;
		//countStudents(list, &noStudents);
		//printf("No. of students: %d\n", noStudents);
		
		//2.
		//return the Student with the highest income
		//Student* stud = NULL;
		//findHighestIncome(list, &stud);
		//printStudent(stud);

		//1. & 2.
		//write the function to convert the list 
		//into a circular simple linked list and
		//display the content afterwards

	}
}