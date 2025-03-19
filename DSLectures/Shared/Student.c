#include "Shared.h"

Student* createStudent(const char* name, int group, unsigned short ref)
{
	Student* result = NULL;
	result = (PStudent)malloc(sizeof(Student));
	if (result != NULL)
	{
		result->group = group;
		result->reference.extRef = ref;
		result->name = (char*)malloc(strlen(name) + 1);
		if (result->name != NULL)
		{
			strcpy_s(result->name, strlen(name) + 1, name);
		}
	}
	return result;
}
void printStudent(Student* stud)
{
	if (stud != NULL)
	{
		printf("Name: %s, group: %d\n", stud->name, stud->group);
		if (stud->reference.extRef >> 15 == 1)
		{
			short uid = stud->reference.extRef >> 8 & 127;
			printf("University ref: %d\n", uid);
			printf("External ref: %d\n", stud->reference.extRef & 255);
		}
		else
		{
			printf("Internal ref: %d\n", stud->reference.intRef);
		}
	}
	printf("\n");
}
void deleteStudent(Student* stud)
{
	if (stud != NULL)
	{
		if(stud->name != NULL)
			free(stud->name);
		free(stud);
	}
}