#include <stdio.h>
#include <stdarg.h>

void printReverse(const char *last, ...)
{
	va_list args;
	va_start(args, last);

	if (last)
	{
		printReverse(va_arg(args, char *), NULL);
		printf("%s ", last);
	}

	va_end(args);
}

int main()
{
	printReverse("World", "Hello", "Hi", NULL);
	return (0);
}
