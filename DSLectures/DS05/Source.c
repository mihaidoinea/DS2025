#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256
int suma(int x, int y) {
	int z = 0, r = 2;
	z = x + y + r;
	return z;
}

void main()
{
	int result = suma(3, 8);
	/*FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char delimiter[] = { ',','\0' };
		char* token = NULL;
		unsigned short reference = 0, group = 0;
		char name[LINE_SIZE], buffer[LINE_SIZE];

		while (fgets(buffer, LINE_SIZE, pFile))
		{
			token = strtok(buffer, delimiter);
			strcpy(name, token);

			token = strtok(NULL, delimiter);
			group = atoi(token);

			token = strtok(NULL, delimiter);
			reference = atoi(token);

			Student* stud = createStudent(name, group, reference);
			printStudent(stud);
			deleteStudent(stud);
		}
	}*/
}