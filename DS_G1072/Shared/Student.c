#include "Shared.h"

Student* createStudent(const char* name, short group, float income)
{
	Student* stud = NULL;
	stud = (Student*)malloc(sizeof(Student));
	if (stud != NULL)
	{
		stud->group = group;
		stud->income = income;
		stud->name = (char*)malloc(strlen(name) + 1);
		if (stud->name != NULL)
		{
			strcpy_s(stud->name, strlen(name) + 1, name);
		}
	}
	return stud;
}

void printStudent(PStudent pStud)
{
	if (pStud != NULL)
	{
		if (pStud->name != NULL)
			printf("Name: %s, ", pStud->name);
		printf("group: %d, income: %.2f\n", pStud->group, pStud->income);
	}
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