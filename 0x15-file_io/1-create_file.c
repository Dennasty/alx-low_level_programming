#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
 * create_file - Creates a file and writes text to it.
 * @filename: The name of the file to create.
 * @text_content: The text to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, const char *text_content)
{
	int fd, bytes_written, text_len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[text_len])
			text_len++;
	}

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_len > 0)
	{
		bytes_written = write(fd, text_content, text_len);
		if (bytes_written != text_len)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}

