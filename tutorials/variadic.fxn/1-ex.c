#include <stdio.h>
#include <stdarg.h>

/**
 * sum - calcuates the sum of a variable number of a variable number of integers.
 */

int sum(int count, ...)
{
	va_list args;
	va_start(args, count);
	int result = 0;

	for (int i = 0; i < count; i++)
	{
		int num = va_arg(args, int);
		result += num;
	}

	va_end(args);

	return (result);
}

int main()
{
	int total1 = sum(3, 10, 20, 30);
	int total2 = sum(5, 1, 2, 3, 4, 5);

	printf("Total 1: %d\n", total1);
	printf("Total 2: %d\n", total2);

	return 0;
}
