#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		printf("#cisfun$ ");

		if ((nread = getline(&line, &len, stdin)) == -1)
		{
			perror("Error in getting input.");
			exit(EXIT_FAILURE);
		}

		/* Remove the newline character at the end of the line */
		line[strcspn(line, "\n")] = '\0';

		if (strcasecmp(line, "exit") == 0)
		{
			printf("Exiting shell...\n");
			sleep(1);
			break;
		}

		pid_t pid = fork();
		if (pid == -1)
		{
			perror("fork error.");
			exit(EXIT_FAILURE);
		}

		if (pid == 0)
		{
			if ((execvp(line, av)) == -1)
			{
				perror("execvp error");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			int status;
			if (waitpid(pid, &status, 0) == -1)
			{
				perror("waitpid error.");
				exit(EXIT_FAILURE);
			}
		}
	}

	free(line);
	return (0);
}
