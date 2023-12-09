#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;

void printPathDir()
{
	char *path = getenv("PATH");

	if (path == NULL)
	{
		fprintf(stderr, "PATH environment variable not found.\n");
			return;
	}

	/* Token the PATH variable using strtok */
	char *token = strtok(path, ":");

	/*Print each directory */
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, ":");
	}
}

int main(void)
{
	printf("Directories in the PATH variable:\n");
	printPathDir();

	return (0);
}
