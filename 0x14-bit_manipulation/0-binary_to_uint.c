#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * binary_to_uint - Converts a binary string to an unsigned integer.
 * @b: The binary string.
 *
 * Return: The converted number, or 0 if there are non-binary characters in b
 * or if b is NULL.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int outpt = 0;
	int z,  ln = strlen(b);

	if (b == NULL)
	return (0);

	for (z = 0; z < ln; z++)
	{
		if (b[z] != '0' && b[z] != '1')
			return (0);
		outpt = (outpt << 1) | (b[z] - '0');
	}
	return (outpt);
}

int main(void)
{
	const char *binary_str = "110101";
	unsigned int outpt = binary_to_uint(binary_str);

	if (outpt != 0)
		printf("Unsigned Integer Value: %u\n", outpt);
	else
		printf("Invalid binary input.\n");

	return (0);
}

