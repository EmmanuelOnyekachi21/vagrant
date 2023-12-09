#include <stdio.h>
#include <stdarg.h>

void customPrintf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	for (const char *p = format; *p; ++p)
	{
		if (*p != '%')
			putchar(*p);
		else
		{
			switch (*++p)
			{
				case 'd':
					printf("%d", va_arg(args, int));
					break;
				case 'f':
					printf("%lf", va_arg(args, double));
					break;
				case 's':
					printf("%s", va_arg(args, char *));
					break;
			}
		}
	}
	va_end(args);
}

int main()
{
	customPrintf("Hello, %s! Your balance is $%f.\n", "John", 1234.56);
	return (0);
}
