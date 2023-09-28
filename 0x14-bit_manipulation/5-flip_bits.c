#include "main.h"

/**
 * flip_bits - amount of bits to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int z, amount = 0;
	unsigned long int now;
	unsigned long int isolate = n ^ m;

	for (z = 47; z >= 0; z--)
	{
		now = isolate >> z;
		if (now & 1)
			amount++;
	}

	return (amount);
}

