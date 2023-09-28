#include "main.h"

/**
 * get_endianness - checks the quantity of endian
 * Return: 0 (big), 1 (little)
 */
int get_endianness(void)
{
	unsigned int z = 1;
	char *q = (char *) &z;

	return (*q);
}

