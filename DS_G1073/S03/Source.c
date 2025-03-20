#define _CRT_SECURE_NO_WARNINGS
#include "Shared.h"
#define LINE_SIZE 256

void main()
{
	//list definition
	Node* headList = NULL;

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
			//printStudent(stud);

			//insert element into the array
			//insertArrayStud(&students, stud, &noStudents);

			//insert element into a simple linked list
			insertTailList(&headList, stud);
			//headList = insertHeadList(headList, stud);
			//deleteStudent(stud);
		}

		printSimpleList(headList);

		//headList = deleteSimpleList(headList);

		/*for (int i = 0; i < noStudents; i++)
		{
			printStudent(students[i]);
			deleteStudent(students[i]);
		}*/
	}
}