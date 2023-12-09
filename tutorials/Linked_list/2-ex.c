#include <stdio.h>

struct node
{
	int data;
	struct node *next;
};

/* Deleting a node by value */
void deleteNode(struct node **head, int key)
{
	struct node *temp = *head;
	struct node *prev = NULL;

	if (temp != NULL && temp->data == key)
	{
		*head = temp->next;
		free(temp);
		return;
	}

	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
		return;

	prev->next = temp->next;
	free(temp);
}
