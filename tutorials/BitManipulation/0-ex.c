#include <stdio.h>

int main()
{
	/* An Operation to set bit at specified position */
	int num = 5;

	/* Set the 3rd bit (from right) to 1 */

	num |= (1 << 3);

	/** (1 << 3) is a bit mask such that:
	 * 1 -> 0000 0001
	 * and is shifted three(3) times such that the above becomes:
	 * 0000 1000.  
	 * Now, 5, which is, 0000 0101 is now 'OR-ed' with the bit mask to set bit.
	 * bit mask = 0000 1000
	 * --- -num = 0000 0101
	 *  Result =  0000 1101 -> 13
	 */

	printf("Modified num: %d\n", num);
	return (0);
}
