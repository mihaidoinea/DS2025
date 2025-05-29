#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256
#define MAX_STUDENTS 10
void main()
{
	HashTable hashTable = {.buckets=NULL, .size = 0};

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char buffer[LINE_SIZE], name[LINE_SIZE];
		char* token; float income; int group;
		int noStuds = 0;

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

			putStudentByKey(&hashTable, stud);

			Student* value = getStudentByKey(hashTable, stud->name);
			printStudent(value);
		}

		//increaseSalaryByKey(hashTable, 14.4f, "popa George");
		//deleteStudentByKey(hashTable, "Popescu Maria");

		printHashTable(hashTable);

		//resize the current hashtable (double the size) if loading factor > 0.2
		resizeHashTableIfLoadingFactorHigher(hashTable, 0.2);

		printHashTable(hashTable);
	}
}

