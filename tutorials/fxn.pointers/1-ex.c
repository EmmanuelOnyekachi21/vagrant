#include <stdio.h>
/* Function pointer as a function parameter */
int add(int a, int b)
{
	return (a + b);
}

int subtract(int a, int b)
{
	return (a - b);
}

int operate(int (*operation)(int, int), int x, int y)
{
	return (operation(x, y));
}

int main()
{
	int result1 = operate(add, 10, 8);
	int result2 = operate(subtract, 10, 8);
	printf("Addition result: %d\n", result1);
	printf("Subtraction result: %d\n", result2);
	return (0);
}
