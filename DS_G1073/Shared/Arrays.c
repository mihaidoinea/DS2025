#include "Shared.h"
void insertArrayStud(Student*** students, Student* stud, int* noStudents)
{
	Student** buffer = NULL;
	(*noStudents)++;
	buffer = (Student**)malloc((*noStudents) * sizeof(Student*));
	if (buffer != NULL)
	{
		memset(buffer, 0, (*noStudents) * sizeof(Student*));

		for (register int i = 0; i < (*noStudents) - 1; i++)
		{
			buffer[i] = (*students)[i];
		}
		buffer[(*noStudents) - 1] = stud;
		if (*students != NULL)
		{
			free(*students);
		}
		*students = buffer;
	}
}