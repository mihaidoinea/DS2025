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