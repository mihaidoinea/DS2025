#include "Student.h"
void main()
{
	Student* stud = NULL;
	stud = createStudent("Popescu Maria", 1072, 1900.3);
	printf("Student: %s, group: %d, income: %.2f\n",
		stud->name, stud->group, stud->income);
	

	Student* arrayStud[5];
	arrayStud[0] = stud;

	deleteStudent(stud);
}