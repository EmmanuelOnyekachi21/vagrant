#include <stdio.h>
#include <string.h>

extern char **environ;

char *_getenv(const char *name)
{
	/* Iterate through the environment variables */
	for (int i = 0; environ[i] != NULL; i++)
	{
		/* Find the position of '=' in the current environment variable */
		char *pos = strchr(environ[i], '=');

		/* If '=' is found, check if the variable name matches */
		if (pos != NULL)
		{
			/* Calculate the length of the variable name */
			size_t len = pos - environ[i];

			/* Compare the variable name */
			if (strncmp(environ[i], name, len) == 0 && name[len] == '\0')
			{
				return (pos + 1);
			}
		}
	}

	/* Environment variable not found */
	return (NULL);
}

int main(void)
{
	/* Example usage */
	const char *variable_name = "PATH";
	char *value = _getenv(variable_name);

	if (value != NULL)
		printf("%s=%s\n", variable_name, value);
	else
		printf("Environment variable %s not found.\n", variable_name);

	return (0);
}
