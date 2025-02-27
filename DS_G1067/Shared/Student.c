#include "Student.h"

Student* createStudent(const char* name, short group)
{
	Student* newStud = NULL;
	newStud = (Student*)malloc(sizeof(Student));
	if (newStud != NULL)
	{
		newStud->name = (char*)malloc(strlen(name) + 1);
		if (newStud->name != NULL)
		{
			strcpy_s(newStud->name, strlen(name) + 1, name);
		}
		newStud->group = group;
	}
	return newStud;
}