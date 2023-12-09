#include <stdio.h>

int main()
{
	/* Program to check if bit is set */
	int num = 5;
	int position = 3;
	int mask = (num >> position);
	int result = mask & 1;

	if (result)
		puts("Already set");
	else
		puts("Not set");

	return (0);
}
