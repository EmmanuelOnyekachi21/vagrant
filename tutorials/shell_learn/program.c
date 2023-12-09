#include <stdio.h>

int main(int argc, char **av)
{
	(void)argc;

	for (int i = 0; av[i] != NULL; i++)
		printf("argument[%d] = %s\n", i, av[i]);
	return (0);
}
