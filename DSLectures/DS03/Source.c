#include "stdio.h"
typedef struct _Letter
{
	short : 5;
	short sign : 1;
	short : 2;
}Letter;
void main()
{
	char* name1 = "Popescu";
	char name2[] = "Popescu";
	name1 = name2;
	printf("Name: %s\n", name2);
	
	Letter* ptr = &name2[0];
	ptr->sign = 1;

	printf("Name: %s\n", name2);


}