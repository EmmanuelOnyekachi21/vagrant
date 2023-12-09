#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		// This is the child process
		printf("Child process\n");
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
