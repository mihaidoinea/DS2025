#include "Structures.h"
Student* createStudent(const char* name, short group, float income)
{
	Student* newStudent = NULL;
	newStudent = (Student*)malloc(sizeof(Student));
	if (newStudent != NULL)
	{
		newStudent->name = (char*)malloc(strlen(name) + 1);
		if (newStudent->name != NULL)
		{
			strcpy_s(newStudent->name, strlen(name) + 1, name);
		}
		newStudent->group = group;
		newStudent->income = income;
	}
	return newStudent;
}
void deleteStudent(PStudent pStud)
{
	if (pStud != NULL)
	{
		if (pStud->name != NULL)
			free(pStud->name);
		free(pStud);
	}
}
