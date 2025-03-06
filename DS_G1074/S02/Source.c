#include "Student.h"
void main()
{
	Student* stud = NULL;
	stud = createStudent("Popescu Maria", 1074, 1200.4f);
	printf("Student: %s, group: %d, income: %.2f\n",
		stud->name, stud->group, stud->income);
	deleteStudent(stud);
}