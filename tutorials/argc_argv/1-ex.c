#include <stdio.h>

void unused_variable_example(int  x)
{
	/* Using __attribute__((unused)) */
	int __attribute__((unused)) y = x;
}

void unused_parameter_example(int a, int b)
{
	/* Casting to (void) */
	(void)a;
	(void)b;
}

int main()
{
	unused_variable_example(42);
	unused_parameter_example(1, 2);

	return (0);
}
