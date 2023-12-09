#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("nonexistent.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		exit(1);
	}

	char buffer[100];
	int bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read == -1)
	{
		perror("Error reading file");
		close(fd);
		exit(1);
	}

	close(fd);
	write(STDOUT_FILENO, buffer, bytes_read);

	return (0);
}
