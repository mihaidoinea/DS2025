#include "Student.h"
void main()
{
	printf("Hello G1066 ...\n");
	PStudent stud = createStudent("Popescu Maria", 1066, 1000.4f);
	printf("Student: %s, group: %d, income: %.2f\n", 
		stud->name, stud->group, stud->income);
	deleteStudent(stud);
}