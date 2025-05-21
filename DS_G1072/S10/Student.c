#include "Shared.h"

Student* createStudent(const char* name, short group, float income, short id)
{
	//var definition
	PStudent stud = NULL;
	//allocate memory
	stud = (Student*)malloc(sizeof(Student));
	if (stud != NULL)
	{
		//init struct attributes
		stud->id = id;
		stud->group = group;
		stud->income = income;
		stud->name = (char*)malloc(strlen(name) + 1);
		if (stud->name != NULL)
		{
			strcpy_s(stud->name, strlen(name) + 1, name);
		}
	}
	//return value
	return stud;
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
void printStudent(PStudent pStud)
{
	if (pStud != NULL)
	{
		printf("ID: %d, ", pStud->id);
		if (pStud->name != NULL)
			printf("Name: %s, ", pStud->name);
		printf("Group: %d, ", pStud->group);
		printf("Income: %.2f\n", pStud->income);
	}
}