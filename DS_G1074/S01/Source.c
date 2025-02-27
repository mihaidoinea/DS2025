#include "stdio.h"
void switchNumbers(int* a, int* b)
{
	printf("Switch stack before:\n");
	printf("&a = 0x%p, &b = 0x%p\n", &a, &b);
	printf("a = 0x%p, b = 0x%p\n\n", a, b);
	printf("*a = %d, *b = %d\n\n", *a, *b);

	int c = *a;
	*a = *b;
	*b = c;

	printf("Switch stack after:\n");
	printf("&a = 0x%p, &b = 0x%p\n", &a, &b);
	printf("a = 0x%p, b = 0x%p\n\n", a, b);
	printf("*a = %d, *b = %d\n\n", *a, *b);


}
void main()
{
	int x = 7;
	int y = 8;

	printf("Main stack before:\n");
	printf("&x = 0x%p, &y = 0x%p\n", &x, &y);
	printf("x = %d, y = %d\n\n", x, y);

	switchNumbers(&x, &y);

	printf("Main stack after:\n");
	printf("&x = 0x%p, &y = 0x%p\n", &x, &y);
	printf("x = %d, y = %d\n", x, y);
}