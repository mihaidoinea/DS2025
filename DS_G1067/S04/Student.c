#include "Structures.h"

Student* createStudent(const char* name,
	short group, float income)
{
	Student* newStud = NULL;
	newStud = (Student*)malloc(1 * sizeof(Student)); // noEl * sizeof(El)
	if (newStud != NULL)
	{
		newStud->name = NULL;
		newStud->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
		if (newStud->name != NULL)
		{
			strcpy_s(newStud->name, strlen(name) + 1, name);
		}
		newStud->group = group;
		newStud->income = income;
	}
	return newStud;
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