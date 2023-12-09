#include <stdio.h>
#include <stdarg.h>

void custom_print(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	while (*format)
	{
		if (*format == 'd')
		{
			int num = va_arg(args, int);
			printf("%d ", num);
		}
		else if (*format == 'f')
		{
			double num = va_arg(args, double);
			printf("%f ", num);
		}
		else if (*format == 's')
		{
			char *str = va_arg(args, char*);
			printf("%s ", str);
		}
		format++;
	}
	va_end(args);
}
int main(void)
{
	custom_print("dfs", 42, 3.141, "Hello, World!");

	return (0);
}
