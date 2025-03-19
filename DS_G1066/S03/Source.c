#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#define LINE_SIZE 256
void insertStud(Student*** studs, Student* stud, int* noStud)
{
	int newSize = (*noStud) + 1;
	Student** buffer = (Student**)malloc(newSize * sizeof(Student*));
	if (buffer != NULL)
	{
		for (register int i = 0; i < (*noStud); i++)
		{
			buffer[i] = (*studs)[i];
		}
		buffer[newSize - 1] = stud;
		free(*studs);
		*studs = buffer;
	}
}

void main()
{
	Student** students = NULL;
	//1. a pointer to another pointer to Student
	//2. an array of pointers to Student
	//3. a matrix of elements of type Student
	int noStudents = 0;
	FILE* pFile = fopen("Data.txt", "r");
	if (pFile != NULL)
	{
		char buffer[LINE_SIZE], name[LINE_SIZE];
		char* token; float income; int group;
		
		char delimiter[] = {',','\0'};
		//delimiter[0] = '1';
		//char const* const del = ",";
		//del = delimiter;
		//del[0] = '2';
		//delimiter = del;
		while (fgets(buffer, LINE_SIZE, pFile))
		{
			printf("Line: %s\n", buffer);
			token = strtok(buffer, delimiter);
			strcpy(name, token);

			token = strtok(NULL, delimiter);
			group = atoi(token);

			token = strtok(NULL, delimiter);
			income = (float)atof(token);
			
			Student* stud = createStudent(name, group, income);

			insertStud(&students, stud, &noStudents);

		}

		for (register int i = 0; i < noStudents; i++)
		{
			//printStudent(students[i]);
			deleteStudent(students[i]);
		}

	}
}

