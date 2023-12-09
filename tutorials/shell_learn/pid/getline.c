#include <stdio.h>
#include <stdlib.h>

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	if (*lineptr == NULL || *n < 128)
	{
		*n =128;
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}

	size_t pos = 0;
	int c;

	while (1)
	{
		c = fgetc(stream);

		if (c == EOF || c == '\n')
		{
			if (c == EOF && pos == 0)
			{
				return (-1);
			}
			(*lineptr)[pos] = '\0';
			return (pos);
		}

		if (pos == *n - 1)
		{
			/* Double the buffer size and reallocate */
			*n *= 2;
			char *newptr = realloc(*lineptr, *n);
			if (newptr == NULL)
			{
				free(*lineptr);
				return (-1);
			}
			*lineptr = newptr;
		}

		(*lineptr)[pos++] = (char)c;
	}
}


int main(int argc, char **av)
{
	//FILE *stream;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

/**    if (argc != 2)
   * {
*	    fprintf(stderr, "Usage: %s <file>\n", av[0]);
*	    exit(1);
    } */

   // stream = fopen(av[1], "r");
/*    if (stream == NULL)
  *  {
*	    perror("fopen");
*	    exit(1);
    }*/

    printf("$ ");

    while ((nread = my_getline(&line, &len, stdin)) != -1) {
        printf("%s\n", line);
	printf("$ ");
    }

    free(line);
//    fclose(stream);
    exit(0);
}
