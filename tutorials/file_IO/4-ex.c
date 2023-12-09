#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int fd = open("example.txt", O_WRONLY | O_APPEND);
	char message[] = "Appending this line";
	write(fd, message, sizeof(message));
	close(fd);

	return (0);
}
