#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	for (int i = 0; i < 5; i++)
	{
		pid_t child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork error");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			/* This is the child process */
			char *const args[] = { "ls", "-l", "/tmp", NULL}; /* Program to execute */
			execvp("ls", args);
			perror("execvp error.\n");
			exit(EXIT_FAILURE);
		}
		else
		{
			/* This is the parent process */
			/* Wait for the child to act */
			int status;
			waitpid(child_pid, &status, 0);

			if (WIFEXITED(status))
			{
				printf("Child process %d exited with status %d\n", i + 1, WEXITSTATUS(status));
			}
			else
			{
				fprintf(stderr, "Child process %d terminated abnormally\n", i + 1);
			}
		}
		sleep(3);
	}

	return (0);
}
