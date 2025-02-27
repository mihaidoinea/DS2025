#include "Student.h"
void main()
{
	printf("Hello G1066 ...\n");
	PStudent stud = createStudent("Popescu Maria", 1066);
	printf("Student %s\n", stud->name);
}