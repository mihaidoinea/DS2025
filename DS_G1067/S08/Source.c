#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256
#define MAX_STUDENTS 10
void main()
{
	HashTable hashTable = {.buckets = NULL, .size=0};

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

			putStudentByKey(&hashTable, stud);

			Student* value = getStudentByKey(hashTable, stud->name);

			printStudent(value);
		}
	}
}