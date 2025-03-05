#include "Student.h"

Student* createStudent(const char* name, int group)
{
	Student* result = NULL;
	result = (PStudent)malloc(sizeof(Student));
	if (result != NULL)
	{
		result->group = group;
		result->name = (char*)malloc(strlen(name) + 1);
		if (result->name != NULL)
		{
			strcpy_s(result->name, strlen(name) + 1, name);
		}
	}
	return result;
}