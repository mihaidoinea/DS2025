#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256
#define MAX_STUDENTS 10
void main()
{
	Node* headList = NULL;

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
			headList = insertTailList(headList, stud);
		}

		//1. check if all students have income greater than a parameter
		//int isTrue = 0;
		//float income = 1000.0f;
		//isTrue = checkIncome(headList, income);
		//printf("All students with income greater: %s\n", (isTrue == 1 ? "YES":"NO"));

		//2. return the position of the highest income in the list
		// with O(n) complexity
		//int position = 0;
		//calculatePosition(vector, &position);
		//printf("Position of the highest income: %d\n", position);

		//1. & 2.
		//split the list in two halfs of same lengths if even
		//return the two lists and display their content
		//the first half will be referenced by the initial head
		//the second half will be returned in a new head
	}
}