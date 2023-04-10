#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: A pointer to the name of the file.
 * @letters: The number of letters the
 *           function should read and print.
 *
 * Return: If the function fails or filename is NULL - 0.
 *         O/w - the actual number of bytes the function can read and print.
 */

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

