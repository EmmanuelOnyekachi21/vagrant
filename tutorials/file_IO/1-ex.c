#include <unistd.h>
#include <fcntl.h>

int main()
{
	int file_descriptor = open("example.txt", O_RDONLY);
	char buffer[100];
	int bytes_read = read(file_descriptor, buffer, sizeof(buffer));
	close(file_descriptor);

	write(STDOUT_FILENO, buffer, bytes_read);

	return (0);
}
