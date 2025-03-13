#include "Student.h"
void main()
{
	Student* stud = createStudent("Popescu Ioana", 1074, 1300.4f);
	Student* arrayStud[5];
	memset(arrayStud, 0, sizeof(arrayStud));

	arrayStud[0] = stud;
	arrayStud[1] = NULL;
	arrayStud[2] = createStudent("Ionescu Robert", 1073, 1200.3f);
	//arrayStud[3] = (Student*)malloc(sizeof(Student));

	for (int i = 0; i < sizeof(arrayStud) / sizeof(Student*); i++)
		deleteStudent(arrayStud[i]);


}