#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char ** environ;

int main()
{
	// Example program to execute
	char *programPath = "/bin/env";

	/* Example command-line arguments for the program */
	char *programArgs[] = {"env", NULL};

	/* Dynamically construct the envVariables array based on the current environment */
	char **envVariables = environ;
	
	if (execve(programPath, programArgs, envVariables) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}

	return (0);
}
