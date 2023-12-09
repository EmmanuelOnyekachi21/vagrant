#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define path_max_len 1024

int main(int argc, char **av)
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s filename ...\n", av[0]);
		exit(EXIT_FAILURE);
	}

	char *path_env = getenv("PATH");
	if (path_env == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not set.\n");
		exit(EXIT_FAILURE);
	}

	char *path_copy = strdup(path_env);
	if (path_copy == NULL)
	{
		perror("Error in strdup.");
		exit(EXIT_FAILURE);
	}

	char *token = strtok(path_copy, ":");
	while (token != NULL)
	{
		for (int i = 1; i < argc; i++)
		{
			char full_path[path_max_len];
			snprintf(full_path, path_max_len, "%s/%s", token, av[i]);

			/* Check if file exists */
			if (access(full_path, F_OK) == 0)
				printf("%s\n", full_path);
		}
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (EXIT_SUCCESS);
}
