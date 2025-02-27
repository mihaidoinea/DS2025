#include "stdio.h"
#include "Student.h"
void main()
{
	printf("Hello G1067 ....\n");
	Student* s1 = createStudent("Popescu Maria", 1067);
	printf("Student: %s\n", s1->name);
}