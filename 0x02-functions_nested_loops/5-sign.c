#include "main.h"
/**
 * _isalpha - Checks for alphabetic character
 * @y: The character to be checked
 * Return: 1 for alphabetic character or 0 for anything else
 */

int _isalpha(int y)
{
	if ((y >= 65 && y <= 97) || (y >= 97 && y <= 122))
	{
		return (1);
	}
	return (0);
}
