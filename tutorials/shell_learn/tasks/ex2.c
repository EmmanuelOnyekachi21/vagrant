#include <stdio.h>
#include <stdlib.h>

extern char ** environ;

int main(int argc, char *argv[], char *env[])
{
	/* Print the addresses of env end environ */
	printf("Address of env (main's third parameter): %p\n", (void *)env);
	printf("Address of environ (global variable): %p\n", (void *)environ);

	/* Check if env and environ have the same address */
	if (env == environ)
		printf("env and environ have the same address.\n");
	else
		printf("env and environ have different addresses.\n");

	return (0);
}
