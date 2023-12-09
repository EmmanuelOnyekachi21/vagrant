#include <stdio.h>
#include <stdlib.h>

/* Define the structure for a node in the singly linked list */
struct Node {
	int data;
	struct Node *next;
};

/* Function to create a new node */
struct Node *createNode(int data)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return (newNode);
}

/* Function to insert a new node at the beginning of the list */
struct Node *insertAtBeginning(struct Node *head, int value)
{
	struct Node *newnode = createNode(data);
	newnode->next = head;
	return (newnode);
}

/* Function to insert a node at the end of the list */
struct Node *insertAtEnd(struct Node *head, int data)
{
	struct Node *newnode = createNode(data);
	if (head == NULL)
		return (newnode);
	struct Node *current = head;

	while (current->next != NULL)
		current = current->next;

	current->next = newnode;
	return (head);
}

/* Function to delete a node with a specific value */
struct Node *deleteNode(struct Node *head, int value)
{
	if (head == NULL)
		return (NULL);

	if (head->data == value)
	{
		struct Node *temp = head->next;
		free(head);
		return (temp);
	}
	struct Node  *current = head;
	while (current->next != NULL && current->next->data != value)
		current = current->next;
	if (current->next != NULL)
	{
		struct Node *temp = current->next;
		current->next = current->next->next;
		free(temp);
	}
	return (head);
/* Function to display the contents of the Linked List */
void displayList(struct Node *head)
{
	struct Node *current = head;

	while (current != NULL)
	{
		printf("%d -> ", current->data);
		current = current->next;
	}

	printf("NULL\n");
}

int main()
{
	struct Node *head = NULL;

	head = insertAtBeginning(head, 3);
	head = insertAtBeginning(head, 2);
	head = insertAtBeginning(head, 1);

	printf("Linked List: ");
	displayList(head);

	return (0);
}
