#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- text file print to STDOUT.
 * @filename: file being read
 * @letters: amoubt of letters to be read
 * Return: w- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *bufa;
	ssize_t fad;
	ssize_t w;
	ssize_t t;

	fad = open(filename, O_RDONLY);
	if (fad == -1)
		return (0);
	bufa = malloc(sizeof(char) * letters);
	t = read(fad, bufa, letters);
	w = write(STDOUT_FILENO, bufa, t);

	close(fad);
	free(bufa);
	return (w);
}

