#include "main.h"

/**
 * get_bit - prints the value of a bit at an index in a decimal number
 * @n: number search
 * @index: the bit index
 *
 * Return: bit value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_variable;

	if (index > 63)
		return (-1);

	bit_variable = (n >> index) & 1;

	return (bit_variable);
}

