#include <stdio.h>

int main()
{
	int a = 100;
	int *b;

	b = &a;

	printf("a value : %d\n", a);
	printf("b value : %p\n", b);
	printf("a addrs : %p\n", &a);
	printf("b point : %d\n", *b);
	printf("b addrs : %p\n", &b);

	return 0;
}
