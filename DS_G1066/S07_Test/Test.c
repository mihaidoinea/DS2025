#include "Shared.h"
void insertStud(Student*** studs, Student* stud, int* noStud)
{
	int newSize = (*noStud) + 1;
	Student** buffer = (Student**)malloc(newSize * sizeof(Student*));
	if (buffer != NULL)
	{
		for (register int i = 0; i < (*noStud); i++)
		{
			buffer[i] = (*studs)[i];
		}
		buffer[newSize - 1] = stud;
		free(*studs);
		*studs = buffer;
	}
}