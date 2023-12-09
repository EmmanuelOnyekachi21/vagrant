#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int file_descriptor = open("example.txt", O_WRONLY | O_CREAT, 0644);
	char message[] = "Hello, world!\n";
	write(file_descriptor, message, sizeof(message));
	close(file_descriptor);

	return (0);
}
