#include <stdio.h>

int main()
{
	char *chset = "It ain't over, till it is over";

	printf("whole : %s\n", chset);
	printf("1st : %c\n", *chset);
	printf("2nd : %c\n", *(++chset));
	printf("3rd : %c\n", chset[1]);
	printf("4th : %c\n", *(chset + 2));

	return 0;
}
