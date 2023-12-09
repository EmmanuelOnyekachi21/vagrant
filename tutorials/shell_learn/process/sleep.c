#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		// This is the child process
		printf("Child process\n");
		sleep(3); /* Sleep for 3 secs to simulate a longer running child process. */
	}
	else if (child_pid > 0)
	{
		// This is the parent process
		printf("Parent process, child PID: %d\n", child_pid);
		int status;
		wait(&status);
	}
	else
	{
		/* Error occured */
		perror("fork");
	}

	return (0);
}
