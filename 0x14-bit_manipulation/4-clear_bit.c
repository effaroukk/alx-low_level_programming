#include "main.h"

/**
 * clear_bit - making the value of a given bit to 0
 * @index: bit index to be cleared
 *@n: pointer to the number to change
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 47)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}

