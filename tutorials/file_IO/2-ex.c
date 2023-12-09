#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int file_descriptor = open("example.txt", O_WRONLY | O_CREAT, 0644);
	dprintf(file_descriptor, "Formatted Output: %d %f %s\n", 42, 3.24, "example");
	close(file_descriptor);
	return (0);
}
