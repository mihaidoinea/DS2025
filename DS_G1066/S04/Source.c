#define _CRT_SECURE_NO_WARNINGS
#include "Structures.h"
#define LINE_SIZE 256

void main()
{
	Node* pHeadList = NULL;

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char buffer[LINE_SIZE], name[LINE_SIZE];
		char* token; float income; int group;

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

			insertTailList(&pHeadList, stud);

		}

		printSimpleList(pHeadList);

		deleteStudByName(&pHeadList, "Popa Robert");

		printSimpleList(pHeadList);
	}
}

