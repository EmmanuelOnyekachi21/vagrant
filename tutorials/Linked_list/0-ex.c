#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RECORDS 6

int main()
{
	struct jb
	{
		char actor[25];
		struct jb *next;
	};

	char *bonds[RECORDS] = {
		"Sean",
		"Harry",
		"Dom",
		"Dog",
		"Goat",
		"Inioluwa"
	};

	struct jb *first;
	struct jb *new;
	struct jb *current;
	int index = 0;

	/* Create the first structure in the list */
	first = malloc(sizeof(struct jb));
	current = first;

	/* Fill the structures */
	while (1)
	{
		strcpy(current->actor, bonds[index]);
		index++;
		if (index < RECORDS)
		{
			new = malloc(sizeof(struct jb));
			current->next = new;
			current = new;
		}
		else
		{
			current->next = NULL;
			break;
		}
	}
	/* Display the results */
	current = first;
	index = 1;
	while (current)
	{
		printf("Structure %d: ", index++);
		printf("%s\n", current->actor);
		current = current->next;
	}

	return (0);
}
	
