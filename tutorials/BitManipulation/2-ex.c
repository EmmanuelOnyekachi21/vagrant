#include <stdio.h>

int main()
{
	int num = 9;
	
	/* Creating a Bit mask */
	int mask = (1 << 0);
	/* 0 - Meaning 1 is pushed 0 times, i.e. we aim to toggle the first bit */	
	num = num ^ mask;

	printf("Modified num: %d\n", num);
	return (0);
}
