#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	const char *pid_max_path = "/proc/sys/kernel/pid_max";
	int fd;
	char buffer[20];

	fd = open(pid_max_path, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening /proc/sys/kernel/pid_max");
		exit(1);
	}

	ssize_t bytesRead = read(fd, buffer, sizeof(buffer));
	if (bytesRead == -1)
	{
		perror("Error");
		close(fd);
		exit(1);
	}

	close(fd);

	buffer[bytesRead] = '\0';

	long max_pid = strtol(buffer, NULL, 10);
	if (max_pid == 0)
	{
		dprintf(2, "Failed to read the maximum PID value.\n");
		exit(1);
	}

	dprintf(1, "Max PID value: %ld\n", max_pid);

	return (0);
}
