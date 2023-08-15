#include "main.h"
/**
 * _islower - Checks for lowercase character
 * @y: The character to be checked
 * Return: 1 for lowercase character or 0 for anything else
 */

int _islower(int y)
{
	if (y >= 97 && y <= 122)
	{
		return (1);
	}
	return (0);
}
