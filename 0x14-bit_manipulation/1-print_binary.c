#include "main.h"

/**
 * print_binary - printing the equivalent binary of a decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int z, cnt = 0;
	unsigned long int now;

	for (z = 63; z >= 0; z--)
	{
		now = n >> z;

		if (now & 1)
		{
			_putchar('1');
			cnt++;
		}
		else if (cnt)
			_putchar('0');
	}
	if (!cnt)
		_putchar('0');
}

