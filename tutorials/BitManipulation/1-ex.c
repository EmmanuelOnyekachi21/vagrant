#include <stdio.h>

int main()
{
	/* This is an Operation to clear bit at a specified position */
	int num = 13;

	/* Create mask */
	int mask = ~(1 << 3);

	/* Clear the 2nd bit (from right) to 0 */
	num &= mask;

	printf("Modified num: %d\n", num);
	return (0);
}
