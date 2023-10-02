#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *make_bufa(char *file);
void close_file(int fad);

/**
 * make_bufa - 980 bytes allocated for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *make_bufa(char *file)
{
	char *bufa;

	bufa = malloc(sizeof(char) * 980);

	if (bufa == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (bufa);
}

/**
 * close_file - Closes file descriptors.
 * @fad: file descriptor to be closed.
 */
void close_file(int fad)
{
	int g;

	g = close(fad);

	if (g == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fad);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	int beg, end, r, w;
	char *bufa;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	bufa = make_bufa(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(beg, bufa, 980);
	end = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (beg == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(bufa);
			exit(98);
		}

		w = write(end, bufa, r);
		if (end == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(bufa);
			exit(99);
		}

		r = read(from, bufa, 980);
		end = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(bufa);
	close_file(beg);
	close_file(end);

	return (0);
}

