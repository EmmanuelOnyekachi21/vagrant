#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		sleep(3);
		// This is the child process
		char *args[] = {"ls", "-l", NULL};
		execvp("ls", args);
	}
	else if (child_pid > 0)
	{
		// This is the parent process
		wait(NULL);
		printf("Parent process: Child process has finished.\n");
	}
	else
	{
		/* Error occured */
		perror("fork");
	}

	return (0);
}
