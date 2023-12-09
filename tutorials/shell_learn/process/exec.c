#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		// This is the child process
		printf("Child process\n");

		/* Replace the child process with a new program (e.g., 'ls'). */
		char *args[] = {"ls", NULL};
		execvp("ls", args);

		/* If execvp returns, it means there was an error. */
		perror("execvp");
	}
	else if (child_pid > 0)
	{
		// This is the parent process
		printf("Parent process, child PID: %d\n", child_pid);
	}
	else
	{
		/* Error occured */
		perror("fork");
	}

	return (0);
}
