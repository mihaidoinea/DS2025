#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#define LINE_SIZE 256

void insertStud(Student*** studs, Student* stud, int* noStud)
{
	int newSize = *noStud + 1;
	Student** buffer = (Student**)malloc(newSize*sizeof(Student*));
	if (buffer != NULL)
	{
		for (register int i = 0; i < *noStud; i++)
			buffer[i] = (*studs)[i];
		buffer[newSize - 1] = stud;
		(*noStud)++;
		free(*studs);
		(*studs) = buffer;
	}
}
void main()
{
	Student** students = NULL;
	//1.a pointer to another pointer to Student
	//2.an array of pointers to Student
	//3.a matrix of elements of type Student

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char delimiter[] = {',','\0'};
		/*char* const pdel = delimiter;
		pdel = NULL;
		delimiter = NULL;
		delimiter[2] = '2';*/
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

			insertStud(&students, stud, &noStud);

		}
	}
}

