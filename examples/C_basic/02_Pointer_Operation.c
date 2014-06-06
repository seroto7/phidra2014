#include <stdio.h>

int main()
{
	int a = 100;
	int *b;

	b = &a;

	printf("(b)     point : %d\n", *b);
	printf("(b)     value : %p\n\n", b++);
	printf("(b + 1) point : %d\n", *b);
	printf("(b + 1) value : %p\n\n", b++);
	printf("(b + 2) point : %d\n", *b);
	printf("(b + 2) value : %p\n\n", b);

	return 0;
}
