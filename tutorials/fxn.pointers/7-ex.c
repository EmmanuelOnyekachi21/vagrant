#include <stdio.h>

void neyo()
{
	printf("Good\n");
}

int main()
{
	void (*ptr)();

	ptr = &neyo;

	ptr();

	return (0);
}
