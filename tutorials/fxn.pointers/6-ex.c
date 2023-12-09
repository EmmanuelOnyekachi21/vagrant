#include <stdio.h>
#include <stdbool.h>

/* A compare function that is used for searching an integer array */
bool compare(const void *a, const void *b)
{
	return (*(int*)a == *(int *)b);
}
/**
 * General purpose search() function that can be used for searching an element *x
 * in an array arr[] of arr_size.  Note that void pointers are used so that the
 * function can be called by passing a pointer of any type.  ele_size is size of an
 * array element.
 */
int search(void *arr, int arr_size, int ele_size, void *x, bool compare(const void *, const void *))
{
	char *ptr = (char *)arr;
	int i;

	for (i = 0; i < arr_size; i++)
		if (compare(ptr + i * ele_size, x))
			return (i);

	return (-1);
}

int main()
{
	int arr[] = {2, 5, 7, 90, 70};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 7;
	printf("Returned index is %d ", search(arr, n, sizeof(int), &x, compare));

	return (0);
}
