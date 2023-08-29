#include "main.h"
#include <unistd.h>

/**
 * print_alphabet - Entry point
 * Return:0
 */

void print_alphabet(void)
{
	char q = 'a';

	while (q <= 'z')
	{
		_putchar(q);
		q++;

	}
	_putchar('\n');

}
