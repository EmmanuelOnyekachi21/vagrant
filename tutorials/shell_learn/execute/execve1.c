#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	// Example program to execute
	char *programPath = "/bin/echo";

	/* Example command-line arguments for the program */
	char *programArgs[] = {"echo", "Hello, execve!", NULL};

	/* Example environment variables */
	char *envVariables[] = {
		"PATH=/usr/bin:/bin",
		"USER=emmanuel",
		NULL
	};
	
	if (execve(programPath, programArgs, envVariables) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}

	perror("execve");
	exit(EXIT_FAILURE);
	return (0);
}
