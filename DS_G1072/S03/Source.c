#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256
void main()
{
	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char delimiter[] = { ',' };
		char line[LINE_SIZE];
		char name[LINE_SIZE];
		float income;
		short group;
		char* token = NULL;
		while (fgets(line, LINE_SIZE, pFile))
		{
			token = strtok(line, delimiter);
			strcpy(name, token);
			printf("Student: %s\n", name);

			token = strtok(NULL, delimiter);
			group = atoi(token);
			printf("Group: %d\n", group);
			
			token = strtok(NULL, delimiter);
			income = (float)atof(token);
			printf("Income: %.2f\n", income);
		}
	}
}
