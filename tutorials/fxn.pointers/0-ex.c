#include <stdio.h>
/* BAsic fxn poiter declaration */

int add(int a, int b)
{
	return (a + b);
}
int main()
{
	int (*ptr)(int, int);
	ptr = add;
	int result = ptr(3, 4);
	printf("Result: %d\n", result);
	return (0);
}
