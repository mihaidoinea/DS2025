#include "Student.h"
Student* createStudent(const char* name, short group)
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
	}
	return newStudent;
}
