#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to split a string into words and return an array of words */
char **splitString(const char *input, int *wordCount)
{
	char **words = NULL;
	char *token;
	char *copy = strdup(input);
	if (!copy)
	{
		perror("Memory allocation error.");
		return (NULL);
	}

	int count = 0;
	token = strtok(copy, " \t\n");

	while (token)
	{
		words = realloc(words, (count + 1) * sizeof(char *));
		if (!words)
		{
			perror("Memory allocation error.");
			free(copy);
			return (NULL);
		}

		words[count] = strdup(token);
		if (!words[count])
		{
			perror("Memory allocation error.");
			free(copy);
			return (NULL);
		}

		token = strtok(NULL, " \t\n");
		count++;
	}

	free(copy);

	if (wordCount)
		*wordCount = count;

	return (words);
}

int main(int argc, char **av)
{
	if (argc != 2)
	{
		printf("Usage: %s \"input_string\"\n", av[0]);
		return (1);
	}

	const char *input = av[1];
	int wordCount = 0;

	char ** words = splitString(input, &wordCount);

	if (words)
	{
		printf("Words in the string:\n");
		for (int i = 0; i < wordCount; i++)
		{
			printf("Word %d: %s\n", i + 1, words[i]);
			free(words[i]);
		}
		free(words);
	}

	return (0);
}
