#include <stdio.h>

int main()
{
	/* Program to check if bit is set */
	int num = 5;
	int position = 2;
	int mask = (1 << position);

	int result = num & mask;
	result >>= position;

	if (result)
		puts("Already set");
	else
		puts("Not set");

	return (0);
}
