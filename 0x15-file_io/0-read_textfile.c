#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "main.h"
#include <stdio.h>

ssize_t read_textfile(const char *filename, size_t letters)
{
	if (filename == NULL)
		return 0;

	int fd = open(filename, O_RDONLY);
	if (fd == -1)
		return 0;

	char *buf = malloc(letters * sizeof(char));
	if (buf == NULL)
		return 0;

	ssize_t bytes_read = read(fd, buf, letters);
	if (bytes_read == -1)
	{
		free(buf);
		close(fd);
		return 0;
	}

	ssize_t bytes_written = write(STDOUT_FILENO, buf, bytes_read);
	free(buf);
	close(fd);

	if (bytes_written == -1 || bytes_written != bytes_read)
		return 0;

	return bytes_read;
}
