#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256

void main()
{
	Node* headStack = NULL;

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char delimiter[] = { ',','\0' };
		char name[LINE_SIZE], buffer[LINE_SIZE];
		float income; int group;
		char* token;
		int noStud = 0;
		while (fgets(buffer, LINE_SIZE, pFile))
		{
			token = strtok(buffer, delimiter);
			strcpy(name, token);

			token = strtok(NULL, delimiter);
			group = atoi(token);

			token = strtok(NULL, delimiter);
			income = (float)atof(token);

			Student* stud = createStudent(name, group, income);
		
			pushStudent(&headStack, stud);
			Student* tmp = peekStudent(headStack);
			printStudent(tmp);
		}

		//stack deletion
		Student* stud = NULL;
		while (stud = popStudent(&headStack))
		{
			printStudent(stud);
			deleteStudent(stud);
		}
		
	}
}

