#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#include "math.h"
#define LINE_SIZE 256
#define NO_STUDENTS 9
void main()
{
	Student* students[NO_STUDENTS];

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
			//printf("Student: %s\n", name);

			token = strtok(NULL, delimiter);
			group = atoi(token);
			//printf("Group: %d\n", group);

			token = strtok(NULL, delimiter);
			income = (float)atof(token);
			//printf("Income: %.2f\n", income);

			Student* pStud = createStudent(name, group, income);
			students[index++] = pStud;
		}
		int noRowsCols = (int)sqrt(NO_STUDENTS);
		Student*** sparseMatrix = loadMatrix(students, noRowsCols);

		SparseNode* listHead = NULL;
		convertToSparseList(sparseMatrix, noRowsCols, &listHead);

	}
}

void convertToSparseList(Student*** sparseMatrix,
	int noRowsCols, SparseNode** listHead)
{
	for(int i=0; i<noRowsCols; i++)
		for (int j = 0; j < noRowsCols; j++)
		{
			if (sparseMatrix[i][j] != NULL)
			{
				SparseNode* node = (SparseNode*)malloc(sizeof(SparseNode));
				node->info = sparseMatrix[i][j];
				node->row = i;
				node->column = j;
				node->next = (*listHead);
				*listHead = node;
			}
		}
}

Student*** loadMatrix(Student** students, int noRowsCols)
{
	Student*** matrix = NULL;
	matrix = (Student***)malloc(sizeof(Student**)* noRowsCols);
	for (int i = 0; i < noRowsCols; i++)
	{
		matrix[i] = (Student**)malloc(sizeof(Student*) * noRowsCols);
		memset(matrix[i], 0, sizeof(Student*) * noRowsCols);
		for (int j = 0; j < noRowsCols; j++)
			matrix[i][j] = students[i * noRowsCols + j];
	}
	return matrix;
}
