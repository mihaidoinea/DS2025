#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256
void main()
{
	Node* stack = NULL;

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char delimiter[] = { ',','\0' };
		char buffer[LINE_SIZE];
		char name[LINE_SIZE];
		float income;
		short group;
		char* token = NULL;
		while (fgets(buffer, LINE_SIZE, pFile))
		{
			token = strtok(buffer, delimiter);
			strcpy(name, token);
			//printf("Student: %s\n", name);

			token = strtok(NULL, delimiter);
			group = atoi(token);
			//printf("Group: %d\n", group);

			token = strtok(NULL, delimiter);
			income = (float)atof(token);
			//printf("Income: %.2f\n", income);

			Student* pStud = createStudent(name, group, income);
			
			pushStudentTailList(&stack, pStud);
			Student* stud = popStudentHeadList(&stack);
			printStudent(stud);
			//deleteStudent(stud);

		}

	}
}
