#include <stdio.h>

/* Function pointers for callbacks */

int compare_asc(const void *a, const void *b)
{
	return (*(int*)a - *(int *)b);
}

int compare_desc(const void *a, const void *b)
{
	return (*(int*)b - *(int *)a);
}

void sort(int arr[], int size, int (*compare)(const void *, const void *))
{
	qsort(arr, size, sizeof(int), compare);
}

int main()
{
	int arr[] = {5, 3, 2, 7, 1};
	int size = sizeof(arr) / sizeof(arr[0]);

	//Sort in ascending order
	sort(arr, size, compare_asc);
	printf("Asceding order");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);

	//sort in descending order
	sort(arr, size, compare_desc);
	printf("\nDescending order: ");
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);

	return (0);
}
