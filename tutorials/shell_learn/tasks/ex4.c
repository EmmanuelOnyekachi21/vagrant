#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure for a node in the linked list */
struct PathNode
{
	char directory[256];
	struct PathNode *next;
};

/* Function to print the directories in the linked list */
void printPath(struct PathNode *head)
{
	struct PathNode *current = head;

	while (current != NULL)
	{
		printf("%s\n", current->directory);
		current = current->next;
	}
}

/* Function to build a linked list of PATH directories */
struct PathNode *buildPathList()
{
	char *pathValue = getenv("PATH");

	if (pathValue == NULL)
	{
		fprintf(stderr, "PATH environment variable not found.\n");
		return (NULL);
	}

	char *token = strtok(pathValue, ":");

	/* Initialize the head of the linked list */
	struct PathNode *head = NULL;
	struct PathNode *current = NULL;

	/* Build the linked list */
	while (token != NULL)
	{
		/* Create a new node for the current directory */
