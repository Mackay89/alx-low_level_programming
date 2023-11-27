#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file that print to STDOUT
 * @filename: text file being read
 * @letters: the number of letters to be read
 * Return: The actual number of byte or 0 if fails
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t f;
	ssize_t w;
	ssize_t t;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(f, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(f);
	return (w);
}
