#include "stdio.h"
#include "Student.h"
void main()
{
	printf("Hello G1067 ....\n");
	Student* s1 = createStudent("Popescu Maria", 1067, 1300.5);
	printf("Size of student: %d\n", sizeof(Student));
	printf("Student: %s\n", s1->name);
	deleteStudent(s1);
}