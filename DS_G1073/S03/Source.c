#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#define LINE_SIZE 256

void insertStud(Student*** students, Student* stud, int* noStudents)
{
	Student** buffer = NULL;
	(*noStudents)++;
	buffer = (Student**)malloc((*noStudents) * sizeof(Student*));
	if (buffer != NULL)
	{
		memset(buffer, 0, (*noStudents) * sizeof(Student*));

		for (register int i = 0; i < (*noStudents) - 1; i++)
		{
			buffer[i] = (*students)[i];
		}
		buffer[(*noStudents) - 1] = stud;
		if (*students != NULL)
		{
			free(*students);
		}
		*students = buffer;
	}
}

void main()
{
	Student ** students = NULL;
	//pointer to pointer to Student - 1 el.
	//array of pointers to Student
	//matrix of elements of type Student
	int noStudents = 0;

	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char delimiter[] = {',','\0'};
		char* token = NULL;
		float income = 0; int group = 0;
		char name[LINE_SIZE];
		char buffer[LINE_SIZE];

		while (fgets(buffer, LINE_SIZE, pFile))
		{
			token = strtok(buffer, delimiter);
			strcpy(name, token);

			token = strtok(NULL, delimiter);
			group = atoi(token);

			token = strtok(NULL, delimiter);
			income = (float)atof(token);

			Student* stud = createStudent(name, group, income);
			printStudent(stud);

			//insert element into the array
			insertStud(&students, stud, &noStudents);

			//deleteStudent(stud);
		}
		for (int i = 0; i < noStudents; i++)
		{
			printStudent(students[i]);
			deleteStudent(students[i]);
		}
	}
}