#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *input = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("$ ");

	while ((nread = getline(&input, &len, stdin)) != -1)
	{
		printf("You entered: %s", input);
		printf("$ ");
	}

	free(input);

	return (0);
}
