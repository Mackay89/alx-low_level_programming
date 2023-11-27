#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * create_buffer - allocate 1024 bytes for a buffer
 * @file: the name  of the file buffer is storing chars for
 * Return: the pointer to a newly-allocated buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - close file descriptors
 * @fd: the file descriptor to be closed
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file
 * @argc: the number of arguments supplied to the program
 * @argv: an array of the pointers tothe arguments
 * Return: 0 on success
 * Description: if the argument count is incorrect - exit code 97
 * if the file_from does not exist or cannot be read - exit code 98
 * if the file_to cannot be created or written to - exit code 99
 * if the file_to or file_from cannot be closed - exit code 100
 */
int main(int argc, char *argv[])
{
	int f, t, r, w;
	char *buffer;

	if (argc != 3)

	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	f = open(argv[1], O_RDONLY);
	r = read(f, buffer, 1024);
	t = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (f == -1 || r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(t, buffer, r);
		if (t == -1 || w == -1)
		{
			dprintf(STDERR_FILENO, "Error:Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(f, buffer, 1024);
		t = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(f);
	close_file(t);

	return (0);

}