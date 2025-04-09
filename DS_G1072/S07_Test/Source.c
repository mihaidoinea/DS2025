#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#include "math.h"
#define LINE_SIZE 256
#define NO_STUDENTS 9
void main()
{
	Node* list = NULL;

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char delimiter[] = { ',','\0' };
		char buffer[LINE_SIZE];
		char name[LINE_SIZE];
		float income;
		short group;
		char* token = NULL;
		int index = 0;
		while (fgets(buffer, LINE_SIZE, pFile))
		{
			token = strtok(buffer, delimiter);
			strcpy(name, token);

			token = strtok(NULL, delimiter);
			group = atoi(token);

			token = strtok(NULL, delimiter);
			income = (float)atof(token);

			Student* pStud = createStudent(name, group, income);
			insertStudent(&list, pStud);
		}

		//1. compute the average income for all students present in the list
		//float incomeAvg = 0.0;
		//computeAverage(list, &incomeAvg);
		//printf("Average value: %.2f\n", incomeAvg);
		
		//2. display the students with income above a certain threshold
		//double threshold = 1000.2;
		//displayStudents(list, threshold);
	
		//1 & 2
		//char* studentName = "Popescu Maria";
		//deleteStudentByName(&list, studentName);
		//displayStudents(list, 0.0);
	}
}