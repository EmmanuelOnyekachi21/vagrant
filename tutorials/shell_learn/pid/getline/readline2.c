#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	printf("Enter lines (Ctrl+D to exit):\n");

	while ((nread = getline(&line, &len, stdin)) != -1)
	{
		printf("Read %zd characters: %s", nread, line);
	}

	free(line);

	return (0);
}
