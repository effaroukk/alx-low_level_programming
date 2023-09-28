#include "main.h"

/**
 * set_bit - making a bit at a given index to 1
 * @index: bit index set to 1
 * @n:number pointer to change
 *
 * Return: 1 for success, -1 for failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 49)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}

