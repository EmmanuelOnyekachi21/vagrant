#include <stdio.h>
/* Array of functio pointer */
int add(int a, int b)
{
	return (a + b);
}

int subtract(int a, int b)
{
	return (a - b);
}

int multiply(int a, int b)
{
	return (a * b);
}

int main()
{
	int (*operation[])(int, int) = {add, subtract, multiply};
	int result1 = operation[0](10, 5);
	int result2 = operation[1](10, 5);
	int result3 = operation[2](10, 5);

	printf("Addition result: %d\n", result1);
	printf("Subtraction result: %d\n", result2);
	printf("Multiplication result: %d\n", result3);

	return (0);
}
