#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

/* Fxn to create a new node */
struct node *createNode(int data)
{
	struct node *newnode = malloc(sizeof(struct node));
	newnode->data = data;
	newnode->next = NULL;
	return (newnode);
}

/* Function to insert a new node at the end of the list */
void insertEnd(struct node **head, int data)
{
	struct node *newNode = createNode(data);

	if (*head == NULL)
	{
		*head = newnode;
		return;
	}

	struct node *current = *head;
	while (current->next != NULL)
		current = current->next;

	current->next = newNode;
}

/* Function to print the elements of the list */
void printList(struct node *head)
{
	struct node *current = head;

	while (current != NULL)
	{
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

