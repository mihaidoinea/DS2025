#include "stdio.h"
#include "string.h"
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
	
	Letter* ptr = (Letter*) & name2[0];
	ptr->sign = 1;

	printf("Name: %s\n", name2);

	for (register size_t i = 0; i < strlen(name2); i++)
	{
		printf("%c \t", name2[i]);
		Letter* pletter = (Letter*) & name2[i];
		pletter->sign = ~pletter->sign;
		printf("%c\n", name2[i]);
	}


}