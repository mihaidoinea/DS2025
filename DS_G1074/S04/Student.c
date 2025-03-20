#include "Structures.h"
Student* createStudent(const char* name, short group, float income)
{
	//declare a variable
	Student* stud = NULL;

	//allocate memory
	stud = (Student*)malloc(1 * sizeof(Student));
	if (stud != NULL)
	{
		//initialize attributes
		stud->group = group;
		stud->income = income;
		stud->name = NULL;
		stud->name = (char*)malloc((strlen(name) + 1) * sizeof(char));
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
		if (pStud->name != NULL)
			printf("Name: %s, ", pStud->name);
		printf("group: %d, income: %.2f\n", 
			pStud->group, pStud->income);
	}
}
